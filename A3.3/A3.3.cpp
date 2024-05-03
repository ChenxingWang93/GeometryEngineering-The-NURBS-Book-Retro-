/* ARGUMENTS 
 *     Input Arguments:
 *         `n`        -        Number of control points in the curve.
 *         `p`        -        Degree of the curve.
 *         `U`        -        Knot vector of the curve.
 *         `P`        -        Array of control points.
 *         `d`        -        Maximum derivative order.
 *         `r1`       -        Starting index for the control points range.
 *         `r2`       -        Ending index for the control points range.
 * 
 *     Output Arguments:
 *         `PK`       -        Two-dimensional vector containing the control points of the curve derivatives.
 * 
 * Steps:
 *     i. Initialize `r` as the difference between `r2` and `r1`
 * 
 *     ii. For `i` from 0 to `r`, set `PK[0][i]` to the corresponding control point value `P[r1 + i]`.
 * 
 *     iii. For `k` from 1 to `d`:
 *              - Calculate `tmp` as `p - k + 1`.
 *              - For `i` from 0 to `r - k`:
 *                    - Compute the value for `PK[k][i]` using the formula:
 *                      $$ \text{PK}[k][i] = \frac{tmp \cdot (\text{PK}[k-1][i+1] - \text{PK}[k-1][i])}{U[r1 + i + p + 1] - U[r1 + i + k]} $$
 * 
 * Example:
 *     
 *     Input: `n = 5`,`p = 2`,`U = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0}`, `P = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0}`, `d = 2`, `r1 = 1`, `r2 = 4`
 * 
 *     Output: `PK` will contain the control points of the curve derivatives computed based on the given input parameters.
 * 
 * This algorithm computes the control points of the curve derivatives up to a specified order based on the input control points, knot vector, degree of the curve, and the specified
 * derivative range.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

void CurveDerivCpts(int n, int p, vector<double>& U, vector<double>& P, int d, int r1, int r2, vector<vector<double>>& PK);

void CurveDerivsCpts(int n, int p, vector<double> U, vector<vector<double>> P, int d, int r1, int r2, vector<vector<double>>& PK) {
    /* 计算曲线导数控制点Compute control points of curve derivatives */
    /* 输入Input:  n,p,U,P,d,r1,r2 */
    /* 输出Output: PK */
    int r = r2 - r1;

    for (int i = 0; i <= r; i++)
    {
        /* `PK` variable seems to be a 2D array (or a vector of vectors) to store the control points of the curve derivatives */
        PK[0][i] = P[r1 + i];
    }
    
    for (int k = 1; k <= d; k++) 
    {
        int tmp = p - k + 1;
        for (int i = 0; i <= r - k; i++)
        {
            PK[k][i] = tmp * (PK[k - 1][i + 1] - PK[k - 1][i]) / (U[r1 + i + p + 1] - U[r1 + i + k]);
        }
    }
}

int main() {
    int n = 5;
    int p = 2;

    vector<double> U = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0};
    vector<double> P = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    int d = 2;
    int r1 = 1;
    int r2 = 3;

    /* 
     * i. `vector<vector<double>> PK`: declares a 2D vector named `PK` where each element if of type `double`. vector of vectors, essentially creating a matrix-like structure.
     *  
     * ii. `(d + 1, vector<double>(r2 - r1 + 1, 0.0))`: initializes the 2D vector `PK` with dimensions
     *     `((d + 1) x (r2 - r1 + 1))`& sets all elements to `0.0`. 
     *         - `(d + 1)`: Specifies the number of rows in the 2D vector. In this case, it is `d + 1`, which means there are
     *           `(d + 1)` rows.
     * 
     *         - `vector<double>(r2 - r1 + 1, 0.0)`: Initializes each row with a vector of length `r2 - r1 + 1` filled
     *           with `0.0`.
     *               - `r2 - r1 + 1`: the number of columns in each row. This expression evaluates to the number
     *                 of columns in each row.
     *               - `0.0`: Initializes each elements in the row to `0.0`.
     * 
     * The below line of code creates a 2D vector `PK` with `d + 1` row and `r2 - r1 + 1` columns,
     * where all elements are initially set to `0.0`.
     */

    vector<vector<double>> PK(d + 1, vector<double>(r2 - r1 + 1, 0.0));

    CurveDerivCpts(n, p, U, P, d, r1, r2, PK);

    cout << "Control points of curve derivatives:" << endl;

    for (int k = 0; k <= d; k++)
    {
        for (int i = 0; i <= r2 - r1; i++)
        {
            cout << "PK[" << k << "][" << i << "] = " << PK[k][i] << endl;
        }
    }

    return 0;
}