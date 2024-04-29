/* ARGUMENTS
 *     Input Arguments:
 *         `n`        -    The degree of the Bernstein polynomials to be computed.
 *         `u`        -    The parameter at which the Bernstein polynomials are to be evaluated.
 * 
 *     Outputs Arguments:
 *         `B`        -    An array storing all nth-degree Bernstein polynomials, where `B[0]` to `B[n]` represent the coefficients of the polynomials.
 * 
 * Steps:
 *     i. Initialize `B[0]` to 1.0, as the 0th-degree Bernstein polynomial is always 1.
 * 
 *     ii. Calculate `u1 = 1.0 - u`, which will be used in subsequent calculations.
 *     
 *     iii. Iterate over `j` from 1 to `n`:
 *           Initialize `saved` to 0.0 for each iteration.
 *           For each `j`, iterate over `k` from 0 to `j`:
 *             Store the value of `B[k]` in a temporay variable `temp`.
 *             Update `B[k]` using the formula: `B[k] = saved + u1 * temp`.
 *             Update `saved` to  `u * temp`.
 *           Set `B[j]` to the final value of `saved`.
 * 
 *     iv. After the loops, the array `B` will contain all nth-degree Bernstein polynomials, where `B[0]` to `B[n]` represent the coefficients of the polynomials.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

void AllBernstein(int n, double u, vector<double>& B) {
    B[0] = 1.0;
    double u1 = 1.0 - u;

    for (int j = 1; j <= n; j++)
    {
        double saved = 0.0;
        for (int k = 0; k < j; k++)
        {
            double temp = B[k];
            B[k] = saved + u1 * temp;
            saved = u * temp;
        }

        B[j] = saved;
    }
}

int main() {
    /* Example value of n */
    int n = 5;
    /* Example value of u */
    double u = 0.3;
    /* Array to store the Bernstein polynomials */
    vector<double> B(n + 1, 0.0);

    /* Call the AllBernstein function */
    AllBernstein(n, u, B);

    /* Output the computed Bernstein polynomials */
    cout << "Bernstein Polynomials for n = " << n << " and u = " << ":" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << "B[" << i << "] = " << B[i] << endl;
    }
    
    return 0;
}