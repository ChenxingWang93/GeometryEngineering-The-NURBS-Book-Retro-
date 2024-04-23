#include <iostream>
#include <vector>
using namespace std;

void SurfaceDerivsAlg1(int n, int p, vector<double> U, int m, int q, vector<double> V, vector<vector<double>>& P, double u, double v, int d, vector<vector<double>>& SKL) {
    int du = min(d, p);

    for (int k = p + 1; k <= d; k++)
    {
        for (int l = 0; l <= d - k; l++)
        {
            SKL[k][l] = 0.0;
        }
        
        int dv = min(d, q);

        for (int l = q + 1; l <= d; l++)
        {
            for (int k = 0; k <= d - l; k++)
            {
                SKL[k][l] = 0.0;
            }
        }

        int uspan;
        /* Implement FindSpan function to find uspan */

        /* Implement DersBasisFuns function to compute Nu */

        int vspan;
        /* Implement FindSpan function to find vspan */

        /* Implement DersBasisFuns function to compute Nv */

        vector<double> temp(q + 1, 0.0);

        for (int k = 0; k <= du; k++)
        {
            for (int s = 0; s <= q; s++)
            {
                temp[s] = 0.0;
                for (int r = 0; r <= p; r++)
                {
                    temp[s] += Nu[k][r] * P[uspan - p + r][vspan - q + s];
                }   
            }

            int dd = min(d - k, dv);

            for (int l = 0; l <= dd; l++)
            {
                SKL[k][l] = 0.0;
                for (int s = 0; s <= q; s++)
                {
                    SKL[k][l] += Nv[l][s] * temp[s];
                }
            }
        }
    }
}

int main() {
    /* 输入值Input values for n, p, U, m, q, V, P, u, v, d */
    int n = 3, p = 2, m = 4, q = 3;
    vector<double> U = {0.0, 0.0, 0.0, 0.5, 1.0, 1.0, 1.0};
    vector<double> V = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};
    vector<vector<double>> P = {{0.0, 1.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    double u = 0.5, v = 0.5;
    int d = 3;

    /* Initialize SKL matrix 初始化 SKL矩阵 */
    vector<vector<double>> SKL(d + 1, vector<double>(d + 1, 0.0));

    /* Call Function to compute surface derivatives Call 函数计算曲面导数 */
    SurfaceDerivsAlg1(n, p, U, m, q, V, P, u, v, d, SKL);

    /* Output SKL matrix 输出 SKL 矩阵*/
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j <= d - i; j++)
        {
            cout << "SKL[" << i << "][" << j << "] = " << SKL[i][j] << endl;
        }
    }
    
    return 0;
}