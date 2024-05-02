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