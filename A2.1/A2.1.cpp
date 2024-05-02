/* ARGUMENTS
 *     Input Arguments:
 *         `n`        -      The number of control points minus 1.
 *         `p`        -      The degree of the B-spline curve.
 *         `u`        -      The parameter value at which to find the knot span.
 *         `U`        -      The knot vector of the B-spline curve.
 * 
 *     Output Arguments:
 *         The knot span index, which is the index of the knot span that contains the parameter value `u`.
 * 
 * Steps:
 *     i. Special Case Check:
 *            If the parameter value `u` is equal to the last knot value `U[n+1]`,return `n`(a special case
 *            where `u` is at the end of the knot vector).
 * 
 *     ii. Binary Search:
 *             Initialize `low` to `p` and `high` to `n+1`.
 *             Calculate the midpoint `mid` as the average of `low` and `high`.
 *             While the parameter value `u` is less than the knot value at `U[mid]` or greater than or equal
 *             to the knot value at `U[mid+1]`, do the following:
 *                If `u` is less than the knot value at `U[mid]`, update `high` to `mid`.
 *                Otherwise, update `low` to `mid`.
 *                Recalculate the midpoint `mid` as the average of the updated `low` and `high`.
 * 
 *     iii. Return the Result:
 *              Once the while loop exits, return the final `mid` value, which represents the knot span index
 *              where the parameter value `u` lies.
 * 
 * Example:
 * 
 *     Suppose we have `n = 5`, `p = 2`, `u = 0.4`, and `U = {0, 0, 0, 0.5, 1, 1, 1}`.
 * 
 *     The algorithm will determine the knot span index for the parameter value `u = 0.4` in the given
 *     knot vector `U` using binary search and return the appropriate knot span index.
 * 
 * This algorithm efficiently finds the knot span index for a given parameter value `u` in the context of 
 * B-spline curves, which is crucial for further B-spine curve calculations.
 * 
 */ 

int FindSpan(int n, int p, double u, double* U) {
    if (u == U[n+1]) return n; /* Special case 特殊案例 */

    int low = p;
    int high = n+1;
    int mid = (low+high)/2;

    while (u < U[mid] || u >= U[mid+1])
    {
        if (u < U[mid]) high = mid;

        else low = mid;

        mid = (low+high)/2;
    }

    return mid;
}