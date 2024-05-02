/* ARGUMENTS
 *     Input Arguments:
 *         `i`        -       The knot span index.
 *         `u`        -       The parameter value.
 *         `p`        -       The degree of the basis functions.
 *         `U`        -       An array representing the knot vector.
 * 
 *     Output Arguments:
 *         `N`        -       An array storing the nonvanishing basis functions.
 * 
 * Steps:
 *     
 *     i. Initialize `N[0]` to 1.0, as the first basis function is always 1.0.
 * 
 *     ii. Iterate over `j` from 1 to `p`:
 *             a. Calculate `left[j]` as `u - U[i+1-j]` and `right[j]` as `U[i+j] - u`.
 *             b. Initialize `saved` to 0.0.
 *             c. Iterate over `r` from 0 to `j`:
 *                    Calculate `temp` as `N[r] / (right[r+1] + left[j-r])`.
 *                    Update `saved` as `left[j-r] * temp`.
 *             d. Set `N[j]` to `saved`.
 * Explanation:
 *     
 *     The algorithm starts by setting the first basis function `N[0]` to 1.0.
 *      
 *     It then iterates over the remaining basis functions from 1 to `p`.
 * 
 *     For each basis function, it calculates the `left` and `right` values based on the knot vector and parameter.
 * 
 *     It computes the nonvanishing basis functions using a recurrence relation involving previously
 *     computed values.
 * 
 *     The algorithm efficiently calculates the nonvanishing basis functions required for various
 *     computations in spline algorithms.
 * 
 * By following these steps, the algorithm computes the nonvanishing basis functions efficiently,
 * providing essential values for further spline calculations.
 * 
 */

void BasisFuns(int i, double u, int p, double* U, double* N) {
    double* left = new double[p+1];
    double* right = new double[p+1];

    double saved, temp;
    N[0] = 1.0;

    for (int j = 1; j <= p; j++)
    {
        left[j] = u - U[i+1-j];
        right[j] = U[i+j] - u;
        saved = 0.0;
        
        for (int r = 0; r < j; r++)
        {
            temp = N[r] / (right[r+1] + left[j-r]);
            N[r] = saved + right[r+1] * temp;
            saved = left[j-r] * temp;
        }
        
        N[j] = saved;
    }
    delete[] left;
    delete[] right;
}