#include <iostream>
#include <vector>
using namespace std;
#include "../findSpan.h"

void CurveDerivsAlg2(int n, int p, vector<double> &U, vector<vector<double>> &P, double u, int d, vector<double> &CK) {
    /* Compute curve derivatives */
    /* 输入Input:  n,p,U,P,u,d */
    /* 输出Output: CK */
    int du = min(d, p);

    for (int k = p + 1; k <= d; k++)
    {
        CK[k] = 0.0;
    }
    
    int span = FindSpan(n, p, u, U);
    AllBasisFuns(span, u, p, U, N);

    vector<vector<double>> PK;
    CurveDerivsCpts(n, p, U, P, du, span - p, span, PK);

    for (int k = 0; k <= du; k++)
    {
        CK[k] = 0.0;
        for (int j = 0; j < p - k; j++)
        {
            CK[k] += N[j][p - k] * PK[k][j];
        }
    }
}

int main() {
    /* Define input parameters 定义输入参数 */
    int n = 5;
    int p = 2;
    vector<double> U = {0.0, 0.25, 0.5, 0.75, 1.0};
    vector<vector<double>> P = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}, {10.0, 11.0, 12.0}, {13.0, 14.0, 15.0}};
    double u = 0.5;
    int d = 3;

    /* Initialize CK vector 初始化 CK 向量 */
    vector<double> CK(d + 1, 0.0);

    /* Call CurveDerivsAlg2 function Call 弧形导数算法2函数 */
    CurveDerivsAlg2(n, p, U, P, u, d, CK);

    for (int i = 0; i <= d; i++)
    {
        cout << "CK[" << i << "] = " << CK[i] << endl;
    }
    
    return 0;
}