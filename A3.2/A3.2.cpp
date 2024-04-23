#include <iostream>
#include <vector>
#include "../findSpan.h"
#include "../DersBasisFuns.h"
using namespace std;

void CurveDerivsAlg1(int n, int p, vector<double> U, vector<double> P, double u, int d, vector<double> CK) {
    int du = min(d, p);

    for (int k = p + 1; k <= d; k++)
    {
        CK[k] = 0.0;
    }
    
    int span = FindSpan(n, p, u, U);
    vector<vector<double>> Unders(du + 1,vector<double>(p + 1));
    DersBasisFuns(span, u, p, du, Unders);

    for (int k = 0; k <= du; k++)
    {
        CK[k] = 0.0;
        for (int j = 0; j <= p; j++)
        {
            CK[k] += Unders[k][j] * P[span - p + j];
        }
    }
}

int main() {
    /* Define input parameters 定义输入参数 */
    int n = 6, p = 2, d = 4;
    vector<double> U = {0.0, 0.0, 0.0, 0.5, 1.0, 1.0, 1.0};
    vector<double> P = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double u = 0.3;

    /* Initialize CK vector 初始化 CK 向量 */
    vector<double> CK(d + 1);

    /* Call the CurveDerivsAlg1 function Call 曲线导数算法1 */
    CurveDerivsAlg1(n, p, U, P, u, d, CK);

    /* Output the CK vector 输出 CK 向量 */
    for (double val : CK)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
