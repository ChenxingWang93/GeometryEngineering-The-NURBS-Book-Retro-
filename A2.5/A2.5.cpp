#include <vector>
using namespace std;
void DersOneBasisFun(int p, int m, vector<double>& U, int i, double u, int n, vector<double>& ders) {
    /* Compute derivatives of basis function Nip */
    /* 输入Input: p,m,U,i,u,n */
    /* 输出Output: ders */

    if (u < U[i] || u >= U[i + p + 1])              /* Local property */
    {
        /* Local property not satisfied, set derivatives to zero */
        for (int k = 0; k <= n; k++)
        {
            ders[k] = 0.0;
        }
        return;
    }
    vector<double> N(p + 1, 0.0);


    for (int j = 0; j <= p; j++)                    /* Initialize zeroth-degree functions */
    {
        if (u >= U[i + j] && u < U[i + j + 1])
            N[j] = 1.0;
    }

    vector<double> ND(n + 1, 0.0);
    vector<double> saved(p + 1, 0.0);
    
    
    for (int k = 1; k <= p; k++)                    /* Compute full triangular table */
    {
        if (N[0] == 0.0)
            saved[0] = 0.0;
        else
            saved[0] = (u - U[i]) / (U[i + k] - U[i]);

        for (int j = 0; j < p - k + 1; j++)
        {
            double Uleft = U[i + j + 1];
            double Uright = U[i + j + k + 1];

            if (N[j + 1] == 0.0)
            {
                N[j] = saved[j];
                saved[j + 1] = 0.0;
            } else {
                double temp = N[j + 1] / (Uright - Uleft);
                N[j] = saved[j] + (Uright - u) * temp;
            }
        }
    }

    ders[0] = N[p];                                 /* The function value */ 

    for (int k = 1; k <= n; k++)                    /* Compute the derivatives */
    {
        for (int j = 0; j <= k; j++)                /* Load appropriate column */
            ND[j] = N[j + p - k];

        for (int jj = 1; jj <= k; jj++)             /* Compute table of width k */
        {
            if (ND[0] == 0.0)
                saved[0] = 0.0;
            else
                saved[0] = ND[0] / (U[i + p - k + jj] - U[i]);
            for (int j = 0; j < k - jj + 1; j++)
            {
                double Uleft = U[i + j + 1];
                double Uright = U[i + j + p + jj + 1];

                if (ND[j + 1] == 0.0)
                {
                    ND[j] = (p - k + jj) * saved[j];
                    saved[j + 1] = 0.0;
                } else {
                    double temp = ND[j + 1] / (Uright - Uleft);
                    ND[j] = (p - k + jj) * (saved[j] - temp);
                    saved[j + 1] = temp;
                }
            }
        }
        ders[k] = ND[0];                            /* kth derivative */ 
    }
}