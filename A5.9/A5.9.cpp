#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double BinomialCoeff(int n, int k) {
    if (k == 0 || k == n)
    {
        return 1;
    }
    return BinomialCoeff(n - 1, k - 1) + BinomialCoeff(n - 1, k);
}

void DegreeElevateCurve(int n, int p, vector<double>& U, vector<double>& Pw, int t, int& nh, vector<double>& Uh, vector<double>& Qw) {
    int m = n + p + 1;
    int ph = p + t;
    int ph2 = ph / 2;

    /* Compute Bezier degree elevation coefficients */
    vector<vector<double>> bezalfs(ph + 1, vector<double>(p + 1, 0.0));

    /* Compute Bezier degree elevation coefficients 计算贝塞尔度 评估系数 */
    bezalfs[0][0] = bezalfs[ph][p] = 1.0;
    
    for (int i = 1; i <= ph2; i++)
    {
        double inv = 1.0 / BinomialCoeff(ph, i);
        int mpi = min(p, i);

        for (int j = max(0, i - t); j <= mpi; j++)
        {
            bezalfs[i][j] = bezalfs[ph - i][p - j];
        }
    }
    
    int mh = ph;
    int kind = ph + 1;
    int r = -1;
    int a = p;
    int b = p + 1;
    int cind = 1;
    double ua = U[0];
    Qw[0] = Pw[0];

    vector<double> bpts(ph + 1, 0.0);
    vector<double> Nextbpts(p + 1, 0.0);
    vector<double> alfs(p - t, 0.0);
    vector<double> ebpts(ph + 1, 0.0);

    for (int i = 0; i <= ph; i++)
    {
        Uh[i] = ua;
    }

    for (int i = 0; i <= ph; i++)
    {
        bpts[i] = Pw[i];
    }
    
    while (b < m)
    {
        int i = b;

        while (b < m && U[b] == U[b + 1])
        {
            ++b;
        }
        
        int mul = b - i + 1;
        mh = mh + mul + t;
        double ub = U[b];
        int oldr = r;
        r = p - mul;

        int lbz, rbz;
        if (oldr > 0)
        {
            lbz = (oldr + 2) / 2;
        } else {
            lbz = 1;
        }
        
        int rbz = (r > 0) ? ph - (r + 1) / 2 : ph;

        if (r > 0)
        {

            rbz = ph - (r + 1) / 2;
        } else {
            rbz = ph;
        }
        
        /* Insert knot to get Bezier segment 插入结点得到 贝塞尔线段 */
        if (r > 0)
        {
            double numer = ub - ua;
            for (int k = p; k > mul; k--)
            {
                alfs[k - mul - 1] = numer / (U[a + k] - ua);
            }

            for (int j = 1; j <= r; j++)
            {
                double save = r - j;
                int s = mul + j;
                for (int k = p; k >= s; k--)
                {
                    bpts[k] = alfs[k - s] * bpts[k] + (1.0 - alfs[k - s]) * bpts[k - 1];
                }
                Nextbpts[save] = bpts[p];
            }
        }

        for (int i = lbz; i <= ph; i++)
        {
            ebpts[i] = 0.0;
            int mpi = min(p, i);
            for (int j = max(0, i - t); j <= mpi; j++)
            {
                ebpts[i] += bezalfs[i][j] * bpts[j];
            }
        }

        /* Further implementation for knot removal and loading control points into Qw can be added here 结点移除 并加载控制点 到 Qw */
        if (b < m)
        {
            for (int j = 0; j < r; j++)
            {
                bpts[j] = Nextbpts[j];
            }
            for (int j = r; j <= p; j++)
            {
                bpts[j] = Pw[b - p + j];
            }
            a = b;
            b = b + 1;
            ua = ub;
        } else {
            for (int i = 0; i <= ph; i++)
            {
                Uh[kind + i] = ub;
            }
        }
    }

    nh = mh - ph - 1;
}
