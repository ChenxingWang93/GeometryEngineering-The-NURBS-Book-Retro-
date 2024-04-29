/* ARGUMENTS
 *     Input Arguments:
 *         `a`        -    A 2D array representing the coefficients of the power basis surface.
 *         `n`        -    The degree of the surface in the u-direction.
 *         `m`        -    The degree of the surface in the v-direction.
 *         `u0`       -    The u-parameter at which to evaluate the surface.
 *         `v0`       -    The v-parameter at which to evaluate the surface.
 * 
 *     Output Arguments:
 *         `S`        -    The computed point on the power basis surface at parameters `u0` and `v0`.
 * 
 * Steps:
 *     i.Initialization:
 *           Initialize an array `b` to store intermediate results.
 * 
 *     ii.Evaluate Horner's Method for each row in the u-direction:
 *            For each row `i` from 0 to `n`:
 *                Apply Horner's Method (Algorithm A1.7) to evaluate the polynomial in the v-direction for the coefficients in row `a[i][]`, storing the result in `b[i]`.
 * 
 *     iii.Evaluate Horner's Method for the u-direction:
 *             Apply Horner's Method to evaluate the polynomial in the u-direction for the coefficients in the array `b`, using the parameter `u0`, and store the result in `S`.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/* Horner's method for evaluating a polynomial */
void Horner1(const vector<double>& a, int n, double u, double& C)
{
    C = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        C = u * C + a[i];
    }
}

/* Horner2 function to compute a point on a power basis surface */
void Horner2(const vector<vector<double>>& a, int n, int m, double u0, double v0, double& S) {
    vector <double> b(n + 1, 0.0);

    for (int i = 0; i <= n; i++)
    {
        Horner1(a[i], m, v0, b[i]); /* a[i][] is the ith row */
    }

    Horner1(b, n, u0, S);
}

int main() {
    /* Example value of n */
    int n = 2;

    /* Example value of m */
    int m = 3;

    /* Example value of u0 */
    double u0 = 0.5;

    /* Example value of v0 */
    double v0 = 0.3;

    /* Point on the power basis surface */
    double S;

    /* Example 2D vector representing the coefficients of the power basis surface */
    vector<vector<double>> a = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

    /* Call the Horner2 function */
    Horner2(a, n, m, u0, v0, S);

    /* Output the computed point on the power basis surface */
    cout << "Point on power basis surface at (u0, v0) = (" << u0 << ". " << "): " << S << endl;

    return 0;
}