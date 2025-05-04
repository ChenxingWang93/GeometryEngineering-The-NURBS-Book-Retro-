#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double Distance4D(const std::vector<double>& p1, const std::vector<double>& p2);
void BezDegreeReduce(const std::vector<double>& bpts, std::vector<double>& rbpt, double& MaxErr);

/* Tolerance value */
const double TOL = 1e-6;

int DegreeReduceCurve(int n, int p, const std::vector<double>& U, const std::vector<double>& Qw, int nh, std::vector<double>& Uh, std::vector<double>& Pw) {
    int ph = p - 1;
    int mh = ph;
    int kind = ph + 1;
    int r = -1;
    int a = p;
    int b = p + 1;
    int cind = 1;
    int mult = p;
    int m = n + p + 1;
    
    Pw[0] = Qw[0];
    for (int i = 0; i <= ph; ++i) {
        Uh[i] = U[0];
    }

    std::vector<double> bpts(p + 1);
    std::vector<double> rbpts(ph + 1);
    std::vector<double> Nextbpts;
    std::vector<double> alphas(p + 1);
    std::vector<double> e(m, 0.0);

    for (int i = 0; i <= p; ++i) {
        bpts[i] = Qw[i];
    }
    while (b < m) {
        // First compute knot multiplicity
        int i = b;
        while (b < m && U[b] == U[b + 1]) {
            b++;
        }
        mult = b - i + 1;
        mh = mh + mult - 1;
        int oldr = r;
        r = p - mult;

        int lbz;
        if (oldr > 0) {
            lbz = (oldr + 2) / 2;
        } else {
            lbz = 1;
        }

        // Insert knot U[b] r times
        if (r > 0) {
            double numer = U[b] - U[a];
            for (int k = p; k >= mult; --k) {
                alphas[k - mult - 1] = numer / (U[a + k] - U[a]);
            }
            for (int j = 1; j <= r; ++j) {
                int save = r - j;
                int s = mult + j;
                for (int k = p; k >= s; --k) {
                    bpts[k] = alphas[k - s] * bpts[k] + (1.0 - alphas[k - s]) * bpts[k - 1];
                }
                Nextbpts[save] = bpts[p];
            }
        }

        // Degree reduce Bezier segment
        double MaxErr;
        BezDegreeReduce(bpts, rbpts, MaxErr);
        e[a] = e[a] + MaxErr;
        if (e[a] > TOL) {
            return 1; // Curve not degree reducible
        }

        /* Degree reduce Bezier segment 贝塞尔线段的度数减少 */
        double MaxErr;
        BezDegreeReduce(bpts, rbpts, MaxErr);
        e[a] = e[a] + MaxErr;
        if (e[a] > TOL) {
            return 1; // Curve not degree reducible
        }

        // Remove knot U[a] oldr times
        if (oldr > 0) {
            int first = kind;
            int last = kind;
            for (int k = 0; k < oldr; ++k) {
                i = first;
                int j = last;
                int kj = j - kind;
                while (j - i > k) {
                    double alfa = (U[a] - Uh[i - 1]) / (U[b] - Uh[i - 1]);
                    double beta = (U[a] - Uh[j - k - 1]) / (U[b] - Uh[j - k - 1]);
                    Pw[i - 1] = (Pw[i - 1] - (1.0 - alfa) * Pw[i - 2]) / alfa;
                    rbpts[kj] = (rbpts[kj] - beta * rbpts[kj + 1]) / (1.0 - beta);
                    i++;
                    j--;
                    kj--;
                }

                // Compute knot removal error bounds (Br)
                double Br;
                if (j - i < k) {
                    Br = Distance4D(std::vector<double>{Pw[i - 2]}, std::vector<double>{rbpts[kj + 1]});
                } else {
                    double delta = (U[a] - Uh[i - 1]) / (U[b] - Uh[i - 1]);
                    double A = delta * rbpts[kj + 1] + (1.0 - delta) * Pw[i - 2];
                    Br = Distance4D(std::vector<double>{Pw[i - 1]}, std::vector<double>{A});
                }

                // Update the error vector
                int K = a + oldr - k;
                int q = (2 * q - k + 1) / 2;
                int L = K - q;
                for (int ii = L; ii <= a; ++ii) {
                    e[ii] = e[ii] + Br;
                    if (e[ii] > TOL) {
                        return 1;
                    }
                }
                first--;
                last++;
            }
            cind = i - 1;
        }

        /* Load knot vector and control points 加载结点向量与控制点 */
        if (a != p)
        {
            for (int i = 0; i < ph - oldr; i++)
            {
                Uh[kind] = U[a];
                kind++;
            }
        }
        
        for (int i = lbz; i <= ph; i++)
        {
            Pw[cind] = rbpts[i];
            cind++;
        }

        if (b < m)
        {
            for (int i = 0; i < r; i++){
                bpts[i] = Nextbpts[i];
            }
                

            for (int i = r; i <= p; i++){
                bpts[i] = Qw[b - p + i];
            }
            a = b;
            b = b + 1;
        } else {
            for (int i = 0; i <= ph; i++){
                Uh[kind + i] = U[b];
            } 
        }
    }
    nh = mh - ph - 1;
    return 0;
}