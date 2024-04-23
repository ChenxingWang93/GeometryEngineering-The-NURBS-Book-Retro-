#include <iostream>
#include <vector>
using namespace std;
#include "../findSpan.h"
#include "../BasisFuns.h"

void SurfacePoint(int n, int p, vector<double> U, int m, int q, vector<double> V, vector<vector<double>> Pw, double u, double v, vector<double>& S) {
    int uspan, vspan;
    vector<double> Nu(p+1);
    vector<double> Nv(q+1);
    vector<double> temp(q+1);
    double Sw = 0.0;

    /* Find span of curve in u-direction 找到弧线 在 u-方向 跨度 */
    uspan = FindSpan(n, p, u, U);

    /* Calculate basis functions for u-direction 计算 u-方向 基函数 */
    BasisFuns(uspan, u, p, U, Nu);

    /* Find span of curve in v-direction 找到弧线 在 v-方向 跨度 */
    vspan = FindSpan(m, q, v, V);

    /* Calculate basis functions for v-direction 计算 v-方向 基函数 */
    BasisFuns(vspan, v, q, V, Nv);

    for (int l = 0; l <= q; l++)
    {
        temp[l] = 0.0;
        for (int k = 0; k <= p; k++)
        {
            temp[l] += Nu[k] * Pw[uspan - p + k][vspan - q + l];
        }
    }
    
    for (int l = 0; l <= q; l++)
    {
        Sw += Nv[l] * temp[l];
    }
    
    S.clear();
    /* Calculate point on the surface 计算曲面上的点 */
    for (int i = 0; i < Pw[0].size(); i++)
    {
        S.push_back(Sw / Pw[uspan-p][vspan-q][Pw[uspan-p].size()-1]);
    }
}

// int FindSpan() {
//     /* Implement FindSpan function here */
//     /* Return index of span */
// }

// void BasisFuns() {
//     /* Implement BasisFuns function here */
//     /* Calculate basis functions and store them in N */
// }

int main() {
    /* Define inputs 定义输入 */
    vector<double> U = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};
    vector<double> V = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};
    vector<vector<double>> Pw = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double u = 0.5, v = 0.5;
    vector<double> S;

    /* Calculate point on the surface 计算曲面上的点 */
    SurfacePoint(n, p, U, m, q, V, Pw, u, v, S);

    /* Output the result 输出结果 */
    cout << "Point on the surface S: ";
    for (int i = 0; i < S.size(); i++)
    {
        cout << S[i] << " ";
    }
    cout << endl;

    return 0;
}