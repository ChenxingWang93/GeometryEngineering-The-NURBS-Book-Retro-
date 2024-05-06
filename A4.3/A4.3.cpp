#include <iostream>
#include <vector>
using namespace std;
#include "../findSpan.h"
#include "../BasisFuns.h"

void SurfacePoint(int n, int p, double* U, int m, int q, double* V, vector<vector<double>>& Pw, double u, double v, double w, double& S) {
    /* Variables for storing intermediate results */
    int uspan, vspan;
    vector<double> Nu(p+1);
    vector<double> Nv(q+1);
    vector<double> temp(q+1);

    /* Find span of curve in u-direction 找到弧线 在 u-方向 跨度 */
    uspan = FindSpan(n, p, u, U);
    /* Calculate basis functions for u-direction 计算 u-方向 基函数 */
    BasisFuns(uspan, u, p, U, Nu.data());

    /* Find span of curve in v-direction 找到弧线 在 v-方向 跨度 */
    vspan = FindSpan(m, q, v, V);
    /* Calculate basis functions for v-direction 计算 v-方向 基函数 */
    BasisFuns(vspan, v, q, V, Nv.data());

    vector<double> Sw(q+1, 0.0);
    for (int l = 0; l <= q; l++)
    {
        temp[l] = 0.0;
        for (int k = 0; k <= p; k++)
        {
            temp[l] += Nu[k] * Pw[uspan - p + k][vspan - q + l];
        }
    }
    
    S = 0.0;
    for (int l = 0; l <= q; l++)
    {
        S += Nv[l] * temp[l];
    }
    
    S /= w;
}

int main() {
    /* Define inputs 定义输入 */
    int n = 5;
    int p = 2;
    double U[] = {0, 0, 0, 1, 2, 3, 3, 3};
    int m = 4;
    int q = 3;
    double V[] = {0, 0, 0, 1, 2, 2, 2};
    vector<vector<double>> Pw = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    double u = 1.5; 
    double v = 1.5;
    double w = 1.0;
    double S;

    /* Calculate point on the surface 计算曲面上的点 */
    SurfacePoint(n, p, U, m, q, V, Pw, u, v, w, S);

    /* Output the result 输出结果 */
    cout << "Point on the B-spline surface at (u, v) = (" << u << ", " << v << ") is: " << S << endl;

    return 0;
}