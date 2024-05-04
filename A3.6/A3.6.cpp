#include <iostream>
#include <vector>
using namespace std;

/* Function to find the span of a knot vector */
int FindSpan(int n, int p, double u, const vector<double>& U) {
    /* Implementation of FindSpan algorithm */
    /* This function is not provided here, assuming it's implemented elsewhere */
    /* Returns the span */
    return 0;
}

void DersBasisFuns(int span, double u, int p, int d, const std::vector<double>& U, std::vector<std::vector<double>>& ders) {
    /* Implementation of DersBasisFuns algorithm */
    /* This function is not provided here, assuming it's implemented elsewhere */
    /* Computes derivative basis functions and stores them in the ders array */
}

void SurfaceDerivsAlg1(int n, int p, const vector<double>& U, int m, int q, const vector<double> V, 
                       const vector<vector<double>>& P, double u, double v, int d, vector<vector<double>>& SKL) {
    int du = min(d, p);
    int dv = min(d, q);

    for (int k = p + 1; k <= d; k++)
    {
        for (int l = 0; l <= d - k; l++)
        {
            SKL[k][l] = 0.0;
        }
    }
    for (int l = q + 1; l <= d; l++)
    {
        for (int k = 0; k <= d - l; k++)
        {
            SKL[k][l] = 0.0;
        }
    }    

    int uspan = FindSpan(n, p, u, U);
    vector<vector<double>> Nu(du + 1, vector<double>(p + 1));
    DersBasisFuns(uspan, u, p, du, U, Nu);
    /* Implement FindSpan function to find uspan */

    /* Implement DersBasisFuns function to compute Nu */

    int vspan = FindSpan(m, q, v, V);
    vector<vector<double>> Nv(dv + 1, vector<double>(q + 1));
    DersBasisFuns(vspan, v, q, dv, V, Nv);
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

int main() {
    /* 输入值Input values for n, p, U, m, q, V, P, u, v, d */
    int n = 3; /* Degree in u-direction */
    int p = 2; /* Degree in v-direction */
    int m = 4; /* Degree in v-direction */
    int q = 3; /* Degree in v-direction */
    vector<double> U = {0.0, 0.0, 0.0, 0.5, 1.0, 1.0, 1.0}; /* knot vector in u-direction */
    vector<double> V = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0}; /* knot vector in v-direction */
    vector<vector<double>> P = {{0.0, 0.0, 0.0},
                                {1.0, 1.0, 1.0}, 
                                {2.0, 2.0, 2.0}, 
                                {3.0, 3.0, 3.0},
                                {4.0, 4.0, 4.0},
                                {5.0, 5.0, 35.0}}; /*  */
    double u = 0.5; /*  */
    double v = 0.5;
    int d = 3;

    /* Initialize SKL matrix 初始化 SKL矩阵 */
    vector<vector<double>> SKL(d + 1, vector<double>(d + 1, 0.0));

    /* Call Function to compute surface derivatives Call 函数计算曲面导数 */
    SurfaceDerivsAlg1(n, p, U, m, q, V, P, u, v, d, SKL);

    /* Output SKL matrix 输出 SKL 矩阵*/
    for (int k = 0; k <= d; k++)
    {
        for (int l = 0; l <= d - k; l++)
        {
            cout << "SKL[" << k << "][" << l << "] = " << SKL[k][l] << endl;
        }
    }
    
    return 0;
}