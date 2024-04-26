/* ARGUMENTS
 *     Input Arguments:
 *         `n`        -    Number of control points minus one in the u-direction.
 *         `p`        -    Degree of the B-spline curve in the u-direction.
 *         `U`        -    Knot vector of the B-spline curve in the u-direction.
 *         `m`        -    Number of control points minus one in the v-direction.
 *         `q`        -    Degree of the B-spline curve in the v-direction.
 *         `V`        -    Knot vector of the B-spline curve in the v-direction.
 *         `Pw`       -    Control points of the surface.
 *         `X`        -    Array containing the knot values to be inserted.
 *         `r`        -    Number of times each knot is to be inserted.
 *         `dir`      -    Direction indicator(whether to refine in the u-direction or v-direction).
 * 
 *     Outputs Arguments:
 *         `Ubar`     -    Refined knot vector of the surface in the u-direction.
 *         `Vbar`     -    Refined knot vector of the surface in the v-direction.
 *         `Qw`       -    Refined control points of the surface.
 * 
 * Steps:
 *     i.Initialization:
 *         Find indexes `a` and `b` corresponding to the knot values in the u-direction.
 *         Initialize `Ubar`.
 *         Copy the knot vector `V` into `Vbar`.
 *         Save unaltered control points into `Qw`.
 * 
 *     ii.Refining in the U-direction:
 *         Iterate over each knot value in `X` in reverse order.
 *         While the current knot value is less than or equal to `U[i]` and `i` is greater than `a`, insert control points and refine the knot vector:
 *             Update control points and refine the knot vector using the de Boor algorithm.
 *             Decrement `k` and `i`.
 *         Insert the remaining control points using the de Boor algorithm.
 * 
 *     iii.Refining in the V-direction (similar steps as in the U-direction).
 *         
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void RefineKnotVectSurface(int n, int p, vector<double>& U, int m, int q, vector<double>& V, vector<vector<double>>& Pw, vector<double>& X, int r, int dir, vector<double>& Ubar, vector<double>& Vbar, vector<vector<double>>& Qw) {
    if (dir == 0)
    {
        /* Refining in U direction 在 U-方向 精製 */
        int a, b;
        
        /* Find indexes a and b 找到 a &b指針 */
        /* Save unaltered control points 保存 不變的 控制點 */
        for (int row = 0; row <= m; row++)
        {
            for (int k = 0; k <= a - p; k++)
            {
                Qw[k][row] = Pw[k][row];
            }
            for (int k = b - 1; k <= n; k++)
            {
                Qw[k + r + 1][row] = Pw[k][row];
            }
        }
        for (int j = r; j >= 0; j--)
        {
            int i = n + 1;
            while (X[j] <= U[i] && i > a)
            {
                /* Compute Ubar 計算 U-bar */
                int k = n + p;
                for (int row = 0; row <= m; row++)
                {
                    Qw[k - p - 1][row] = Pw[i - p - 1][row];
                }
                k = k - 1;
                i = i - 1;
            }
            int k = n + p;
            for (int row = 0; row <= m; row++)
            {
                Qw[k - p - 1][row] = Qw[k - p][row];
            }
            for (int l = 1; l <= p; l++)
            {
                int ind = k - p + l;
                double alfa;
                if (abs(alfa) == 0.0)
                {
                    for (int row = 0; row <= m; row++)
                    {
                        Qw[ind - 1][row] = Qw[ind][row];
                    } 
                } else {
                    /* Compute alfa 計算 alfa */
                    for (int row = 0; row <= m; row++)
                    {
                        Qw[ind - 1][row] = alfa * Qw[ind - 1][row] + (1.0 - alfa) * Qw[ind][row];
                    }
                }
            }
            Ubar[k] = X[j];
            k = k - 1;
        }
    }
    if (dir == 1)
    {
        /* Refining in V direction (similar code as above with parameters switched */
        /* Similar code as above with U and V directional parameters switched */
    }
}

int main() {
    /* Example usage of the function */
    int n, p, m, q, r, dir;

    /* Initialize n, p, U, m, q, V, Pw, X, r, dir */
    vector<double> U, V, X, Ubar, Vbar;
    vector<vector<double>> Pw, Qw;
    RefineKnotVectSurface(n, p, U, m, q, V, Pw, X, r, dir, Ubar, Vbar, Qw);
    return 0;
}