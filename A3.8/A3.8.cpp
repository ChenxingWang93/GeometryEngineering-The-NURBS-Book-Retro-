#include "../findSpan.h"
#include <algorithm>
//using namespace std; 
void SurfaceDerivsAlgs2(int n, int p, double* U, int m, int q, double* V, double*** P, double u, double v, int d, double** SKL) {
    int du = std::min(d, p);
    int dv = std::min(d, q);
    int k, l, i, j;
    double tmp;
    for (k = p + 1; k <= d; k++)
    {
        for (l = 0; l <= d; l++)
        {
            SKL[k][l] = 0.0;
        }
    }
    int uspan = FindSpan(n, p, u, U);
    double* Nu = new double[p + 1];
    AllBasisFuns(uspan, u, p, U, Nu);
    int vspan = FindSpan(m, q, v, V);
    double* Nv = new double[q + 1];
    AllBasisFuns(vspan, v, q, V, Nv);
    double**** PKL = new double***[du + 1];
    for (k = 0; k <= du; k++)
    {
        PKL[k] = new double**[dv + 1];
        for (l = 0; l <= dv; l++)
        {
            SKL[k][l] = 0.0;
            for (i = 0; i <= q - l; i++)
            {
                tmp = 0.0;
                for (j = 0; j <= p - k; j++)
                {
                    tmp += Nu[j][p - k] * PKL[k][l][j][i];
                }
                SKL[k][l] += Nv[i][q - l] * tmp;
            }
        }
    }
    /* Clean up memory 清理🧹内存 */
    for (int k = 0; k <= p; k++)
    {
        delete[] Nu[k];
    }
    delete[] Nv;
    for (int k = 0; k <= du; k++)
    {
        for (int l = 0; l <= dv; l++)
        {
            for (int i = 0; i <= p - k; i++)
            {
                delete[] PKL[k][l][i];
            }
            delete[] PKL[k][l];
        }
        delete[] PKL[k];
    }    
    delete[] PKL;
}