#include <iostream>
#include <vector>
using namespace std;
void CurveDerivsCpts(int n, int p, vector<double> U, vector<vector<double>> P, int d, int r1, int r2, vector<vector<double>>& PK) {
    /* 计算曲线导数控制点Compute control points of curve derivatives */
    /* 输入Input:  n,p,U,P,d,r1,r2 */
    /* 输出Output: PK */
    int r = r2 - r1;

    for (int i = 0; i <= r; i++)
    {
        PK[0][i] = P[r1 + i];
    }
    
    for (int k = 1; k <= d; k++)
    {
        int tmp = p - k + 1;

        for (int i = 0; i <= r - k; i++)
        {
            PK[k][i] = tmp * (PK[k - 1][i + 1] - PK[k - 1][i]) / 
                (U[r1 + i + p + 1] - U[r1 + i + k]);
        }
    }