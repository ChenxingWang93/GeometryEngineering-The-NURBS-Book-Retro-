/* ARGUMENTS
 *     Input Arguments:
 *         `n`        -    Number of control points minus one.
 *         `p`        -    Degree of the curve.
 *         `U`        -    Knot vector of the original curve.
 *         `Pw`       -    Control points of the original curve.
 *         `X`        -    Array containing the knot values to be inserted.
 *         `r`        -    Number of times each knot is to be inserted.
 * 
 *     Outputs Arguments:
 *         `Ubar`     -    Refined knot vector of the curve.
 *         `Qw`       -    Refined control points of the curve.
 * 
 * Steps:
 *     i.Initialization:
 *         Compute `m = n + p + 1`.
 *         Find the span `a` of the original knot corresponding to `X[0]` and `b` corresponding to `X[r]`.
 *         Increment `b` by 1.
 *     ii.Copying Control Points:
 *         Copy the control points from `0` to `a-p` directly from `Pw` to `Qw`.
 *         Copy the control points from `b-1` to `n` directly from `Pw` to `Qw`, but shifted to the right by `r+1` positions.
 *     iii.Refining Knot Vector:
 *         Copy the knot values from `0` to `a` directly from `U` to `Ubar`.
 *         Copy the knot values from `b+p` to `m` directly from `U` to `Ubar`,but shifted to the right by `r+1` positions.
 *     iv.Inserting Knots:
 *         Initialize `i = b+p-1` and `k = b+p+r`.
 *         Loop over each knot value in `X` in reverse order (from`r`to`0`)
 *         While the current knot value `X[j]` is less than or equal to `U[i]`and`i`is greater than `a`, insert control points and refine the knot vector:
 *         Insert control points and refine the knot vector:
 *           - Insert the control point `Pw[i-p-1]`at position`Qw[k-p-1]`.
 *           - Insert the knot value `U[i]` at position `Ubar[k]`.
 *           - Decrement `k` and `i`.
 *         After the loop, insert the remaining control points using the de Boor algorithm:
 *           - For each segment, compute the blending factor `alfa`.
 *           - Interpolate the control point between `Qw[k-p]` and `Qw[k-p-1]` using the blending factor.
 *           - Insert the knot value `X[j]` at position `Ubar[k]`.
 *           - Decrement `k`.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../findSpan.h"
using namespace std;

int FindSpan(int n, int p, double x, vector<double>& U) {
    /* Implementation of FindSpan function goes here */
}

void RefineKnotVectCurve(int n, int p, vector<double>& U, vector<double>& Pw, vector<double>& X, int r, vector<double>& Ubar, vector<double>& Qw) {
    int m = n + p + 1;
    int a = FindSpan(n, p, X[0], U);
    int b = FindSpan(n, p, X[r], U);
    b = b + 1;

    /* Copy control points 複製控制點 */
    for (int j = 0; j <= a - p; j++)
        Qw[j] = Pw[j];
    
    for (int j = b - 1; j <= n; j++)
        Qw[j + r + 1] = Pw[j];
    
    for (int j = 0; j <= a; j++)
        Ubar[j] = U[j];

    for (int j = b + p; j <= m; j++)
        Ubar[j + r + 1] = U[j];

    int i = b + p - 1;
    int k = b + p + r;

    /* Copy knot vector 複製結點向量 */
    copy(U.begin(), U.begin() + a + 1, Ubar.begin());
    copy(U.begin() + b + p, U.begin() + m + 1, Ubar.begin() + b + p + r + 1);

    for (int j = r; j >= 0; j--)
    {
        /* Your logic for refining knot vector and control points goes here */
        while (X[j] <= U[i] && i > a)
        {
            Qw[k - p - 1] = Pw[i - p - 1];
            Ubar[k] = U[i];
            k = k - 1;
            i = i - 1;
        }

        Qw[k - p - 1] = Qw[k - p];
        for (int l = 1; l <= p; l++)
        {
            int ind = k - p + l;
            double alfa = Ubar[k + 1] - X[j];
            if (abs(alfa) == 0.0)
                Qw[ind - 1] = Qw[ind];
            else {
                alfa = alfa / (Ubar[k + l] - U[i - p + l]);
                Qw[ind - 1] = alfa * Qw[ind - 1] + (1.0 - alfa) * Qw[ind];
            }
        }

        Ubar[k] = X[j];
        k = k - 1;
    }
}

int main() {
    /* Example usage of RefineKnotVectCurve */
    int n = 5;  /* Number of control points */
    int p = 2;  /* Degree */
    vector<double> U = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 3.0, 3.0};  /* knot vector */
    vector<double> Pw = {1, 2, 3, 4, 5, 6, 7};  /* Control points with weights */
    vector<double> X = {0.5, 1.5};  /* Knots value to be inserted */
    int r = 2;  /* Number of times to insert the knots */
    vector<double> Ubar(n + p + r + 2); /* Output: New knot vector */
    vector<double> Qw(n + r + 1); /* Output: New control points with weights */

    RefineKnotVectCurve(n, p, U, Pw, X, r, Ubar, Qw);

    cout << "New knot vector Ubar:" << endl;
    for (double knot : Ubar)
    {
        cout << knot << " ";
    }
    cout << endl;

    cout << "New control points Qw:" << endl;
    for (double controlPoint : Qw)
    {
        cout << controlPoint << " ";
    }
    cout << endl;
    
    return 0;
}