/* ARGUMENTS
 *     Input Arguments:
 *         `a`        -    An array storing the coefficients of a polynomial of degree `n`.
 *         `n`        -    The degree of the polynomial.
 *         `u0`       -    The value at which the polynomial needs to be evaluated.
 *     
 *     Outputs Arguments:
 *         `C`        -    The result of evaluating the polynomial at the point `u0`.
 * 
 * Steps:
 *     i.Initialize `C` to be the coefficient of the highest degree term in the polynomial, i.e., `C = a[n]`.
 * 
 *     ii.Starting from the next highest degree term, iterate through the coefficients in reverse order(from `n-1` to `0`).
 * 
 *     iii.For each coefficient `a[i]`, update `C` using the Horner's method:
 *           Multiply the current value of `C` by `u0`.
 *           Add the next coefficient `a[i]`.
 *     iv.Repeat this process for all coefficients from the second highest degree down to the constant term.
 * 
 *     v.After iterating through all coefficients, `C` will hold the value of the polynomial evaluated at the point `u0`.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

/* Function to compute point on power basis curve using Horner's method */
double Horner1(vector<double>& a, int n, double u0, double& C) {
    double C = a[n];

    for (int i = n - 1; i >= 0; i--)
    {
        C = C * u0 + a[i];
    }
    return C;
}

int main() {
    /* Example input data */
    vector<double> coefficients = {1.0, 2.0, 3.0, 4.0};    /* Example coefficients of the power basis curve */
    int n = a.size() - 1;    /* Example degree of the curve */
    double u0 = 2.5;    /* Parameter value */
    double C;    /* Output point on the curve */

    /* Call the Horner1 function */
    Horner1(a, n, u0, C);

    /* Output the result */
    cout << "Point on the power basis curve at u0= " << u0 << ": " << C << endl;
    
    return 0;
}