#include <iostream>
#include <vector>
using namespace std;
void DersBasisFuns(int i, double u, int p, int n, vector<double> U, vector<vector<double>>, ders) {
    vector<vector<double>> ndu(p + 1, vector<double>(p + 1, 0.0));
    vector<double> left(p + 1, 0.0);
    vector<double> right(p + 1, 0.0);
    vector<vector<double>> a(2, vector<double>(p + 1, 0.0));
    vector<double> N(p + 1, 0.0);
    
    ndu[0][0] = 1.0;
    for (int j = 1; j <= p; j++)
    {
        /* code */
        left[j] = n - U[i + 1 - j];
        right[j] = U[i + 1 - j];
        double saved = 0.0;
        for (int r = 0; r < j; r++)
        {
            /* code */
            ndu[j][r] = right[r + 1] + left[j - r];
            double temp = ndu[r][j - 1] / ndu[j][r];
            ndu[r][j] = saved + right[r + 1] * temp;
            saved = left[j - r] * temp;
        }
        ndu[j][j] = saved;
    }

    for (int j = 0; j <= p; j++)
    {
        /* code */
        ders[0][j] = ndu[j][p];
    }

    for (int r = 0; r <= p; r++)
    {
        /* code */
        int s1 = 0, s2 = 1;
        a[0][0] = 1.0;

        for (int k = 1; k <= n; k++)
        {
            /* code */
            double d = 0.0;
            int rk = r - k, pk = p - k;
            if (r >= k) {
                a[s2][0] = a[s1][0] / ndu[pk + 1][rk];
                d = a[s2][0] * ndu[rk][pk];
            }
            int j1 = (rk >= -1) ? 1 : -rk;
            int j2 = (r - 1 <= pk) ? k - 1 : p - r;
            for (int j = j1; j < j2; j++)
            {
                /* code */
                a[s2][j] = (a[s1][j] - a[s1][j - 1]) / ndu[pk + 1][rk + j];
                d += a[s2][j] * ndu[rk + j][pk];
            }
            ders[k][r] = d;
            int temp = s1;
            s1 = s2;
            s2 = temp;
        }
    }

    int r = p;
    for (int k = 1; k <= n; k++)
    {
        /* code */
        for (int j = 0; j <= p; j++)
        {
            /* code */
            ders[k][j] *= r;
        }
        r *= (p - k);
    }
}

int main() {
    int i = 0, p = 2, n = 3;
    double u = 0.5;
    vector<double> U = {0.0, 1.0, 2.0, 3.0, 4.0};
    vector<vector<double>> ders(n + 1, vector<double>(p + 1, 0.0));

    DersBasisFuns(i, u, p, n, U, ders);

    // Display the results 展示结果
    for (int k = 0; k <= n; k++)
    {
        /* code */
        for (int j = 0; j <= p; j++)
        {
            /* code */
            cout << "ders[" << k << "][" << j << "] = " << ders[k][j] << endl;
        }
    }
    return 0;
}