#include <iostream>
#include <vector>
using namespace std;
void OneBasisFun(int p, int m, vector<double>& U, int i, double u, double &Nip) {
    /* Compute the basis function Nip 计算基函数 Nip */
    /* 输入Input: p, m, U, i, u */
    /* 输出Output: Nip */
    vector<double> N(p + 1, 0.0);
    if ((i == 0 && u == U[0]) || 
        (i == m - p - 1 && u == U[m]))      /* Special Cases */
    {
        Nip = 1.0;
        return;
    }

    if (u < U[i] || u >= U[i + p + 1])      /* Local property */
    {
        Nip = 0.0;
        return;
    }
    
    double saved, temp, Uleft, Uright;
    vector<double> N(p + 1); /* Array to store basis functions 存储基函数的阵列 */

    for (int j = 0; j <= p; j++)            /* Initialize zeroth-degree functs 初始化 零度 函数 */
    {
        if (u >= U[i + j] && u < U[i + j + 1])
            N[j] = 1.0;
        else
            N[j] = 0.0;
    }

    for (int k = 1; k <= p; k++)            /* Compute triangular table 计算 三角 表格 */
    {
        double saved;
        if (N[0] == 0.0)
            saved = 0.0;
        else
            saved = ((u - U[i]) * N[0]) / (U[i + k] - U[i]);
        for (int j = 0; j <= p - k + 1; j++)
        {
            double Uleft = U[i + j + 1];
            double Uright = U[i + j + k + 1];
            
            if (N[j + 1] == 0.0)
            {
                N[j] = saved;
                saved = 0.0;
            }
            else{
                double temp = N[j + 1] / (Uright - Uleft);
                N[j] = saved + (Uright - u) * temp;
                saved = (u - Uleft) * temp;
            }
        }
    }
    Nip = N[0];
}