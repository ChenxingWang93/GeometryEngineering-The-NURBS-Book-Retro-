#include <iostream>
#include <vector>
using namespace std;

int FindSpan(int n, int p, double u, vector<double>& U) {
    /* Implementation of FindSpan function */
    /* (Assuming FindSpan function is available for use in the algorithm) */
}

void BasisFuns(int span, double u, int p, vector<double>& U, vector<double>& Nu) {
    /* Implementation of BasisFuns function */
    /* (Assuming BasisFuns function is available for use in the algorithm) */
}

void SurfacePoint(int n, int p, vector<double>& U, int m, int q, vector<double>& V, vector<vector<double>>& P, double u, double v, vector<vector<double>>& S) {
    /*  Compute surface point计算曲面上的点  */
    /*  输入Input:  n,p,U,m,q,V,P,u,v  */
    /*  输出Output: S  */
    int uspan = FindSpan(n, p, u, U);
    vector<double> Nu(p+1, 0.0);
    BasisFuns(uspan, u, p, U, Nu);

    int vspan = FindSpan(m, q, v, V);
    vector<double> Nv(q+1, 0.0);
    BasisFuns(vspan, v, q, V, Nv);

    int uind = uspan - p;
    S.assign(3, vector<double>(3, 0.0)); /* Assuming S is a 3x3 matrix 假设S为一个3x3矩阵 */

    for (int l = 0; l <= q; l++)
    {
        double temp = 0.0;
        int vind = vspan - q + l;
        for (int k = 0; k <= p; k++)
        {

            temp += Nu[k] * P[uind + k][vind];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                S[i][j] +=Nv[l] * temp;
            }
        }
    }
}

int main() {
    /* Define n, p, U, m, q, V, P, u, v */
    /* Call SurfacePoint function with the input parameters */
    /* Output the resulting surface point S */
    return 0;
}