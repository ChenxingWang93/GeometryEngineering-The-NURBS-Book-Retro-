/* ARGUMENTS
 *     Input Arguments:
 *         `p`        -         The degree of the basis function.
 *         `m`        -         The total number of control points minus 1.
 *         `U`        -         An array representing the knot vector.
 *         `i`        -         The knot span index.
 *         `u`        -         The parameter value.
 *         `n`        -         The maximum number of derivatives to compute.
 * 
 *     Output Arguments:
 *         `ders`      -        An array storing the computed derivatives of the basis function.
 * 
 * Steps:
 * 
 *     i. Check if `u` is within the local knot span. If not,
 * 
 *     ii. Initialize the zeroth-degree functions based on the parameter value `u`.
 * 
 *     iii. Compute a full triangular table of basis functions.
 * 
 *     iv. Calculate the function value `ders[0]` as the value of the basis function at degree `p`.
 * 
 *     v. Compute the derivatives up to the `n`-th derivative:
 *            For each derivative `k`,load the appropriate column from the triangular table.
 *            Compute a table of width `k` to calculate the derivative values.
 *            Update the derivative values in the `ders` array.
 * 
 * Explanation:
 * 
 *     The algorithm first checks if the parameter `u` falls within the local knot span. If not, it sets all derivatives to 0.
 *      
 *     It then initializes the zeroth-degree functions based on the parameter value `u`.
 * 
 *     By computing a full triangular table of basis functions, it sets up the initial values for further derivative
 *     calculations.
 * 
 *     The algorithm calculates the function value (zeroth derivative) and then proceeds to compute the higher
 *     derivatives up to the `n`-th derivative.
 * 
 *     The derivative values are computed using a recursive formula involving the previously calculated values.
 * 
 * By following these steps, the algorithm efficiently computes the derivatives of the basis function at the given
 * parameter value and knot span index, providing essential values for spline calculations and curve fitting.
 * 
 */

#include <vector>
using namespace std;

void DersOneBasisFun(int p, int m, vector<double>& U, int i, double u, int n, vector<double>& ders) {
    /* Compute derivatives of basis function Nip */
    /* 输入Input: p,m,U,i,u,n */
    /* 输出Output: ders */

    /* Matrix to store basis functions and their derivatives */
    double N[20][20];
    /* Temporary array to store intermediate results */
    double ND[20];
    /* Variables to store knot span values */
    double Uleft, Uright;

    /* Check if the parameter 'u' is outside the local property of the basis function */
    if (u < U[i] || u >= U[i + p + 1])              /* Local property */
    {
        /* if outside local property, set all derivatives to zero */
        for (int k = 0; k <= n; k++)
        {
            ders[k] = 0.0;
        }
        return;
    }

    vector<double> N(p + 1, 0.0);

    /* Initialize zeroth-degree functions based on the parameter 'u' */
    for (int j = 0; j <= p; j++)
    {
        if (u >= U[i + j] && u < U[i + j + 1])
            N[j][0] = 1.0;
        else
            N[j][0] = 0.0;
    }


    vector<double> ND(n + 1, 0.0);
    vector<double> saved(p + 1, 0.0);
    
    /* Compute full triangular table of basis functions and their derivatives */
    for (int k = 1; k <= p; k++)
    {
        
        if (N[0][k - 1] == 0.0)
            saved[0] = 0.0;
        else
            saved[0] = (u - U[i] * N[0][k - 1]) / (U[i + k] - U[i]);

        
        for (int j = 0; j < p - k + 1; j++)
        {
            double Uleft = U[i + j + 1];
            double Uright = U[i + j + k + 1];

            if (N[j + 1][k - 1] == 0.0)
            {
                N[j][k] = saved[j];
                saved[j + 1] = 0.0;
            } else {
                double temp = N[j + 1][k - 1] / (Uright - Uleft);
                N[j][k] = saved[j] + (Uright - u) * temp;
                saved[j] = (u - Uleft) * temp;
            }
        }
    }

    /* store the function value (zeroth derivative) */ 
    ders[0] = N[0][p];

    /* Compute higher-order derivatives */
    for (int k = 1; k <= n; k++)
    {   
        /* Load appropriate column */
        for (int j = 0; j <= k; j++)
            ND[j] = N[j][p - k];

        /* Compute table of width k */
        for (int jj = 1; jj <= k; jj++)
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

        /* Store the kth derivative */
        ders[k] = ND[0];
    }
}

#include <iostream>
void DersOneBasisFun(int p, int m, double* U, int i, double u, int n, double* ders);

int main() {
    /* Degree of the basis function */
    int p = 2;
    /* Number of control points */
    int m = 5;
    /* Knot vector */
    double U[] = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0};
    /* Knot span index */
    int i = 1;
    /* Parameter value */
    double u = 1.5;
    /* Maximum derivative order */
    int n = 2;
    /* Array to store derivatives */
    double ders[3];

    /* Call the function to compute derivatives of the basis function at u */
    DersOneBasisFun(p, m, U, i, u, n, ders);

    /* Output the computed derivatives */
    cout << "Derivatives of the basis function at u = " << u << ":" << endl;

    for (int k = 0; k <= n; k++)
    {
        cout << "Derivative of order " << k << ": " << ders[k] << endl;
    }
    
    return 0;
}