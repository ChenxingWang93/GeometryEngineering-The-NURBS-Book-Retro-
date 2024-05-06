/* ARGUMENTS
 *     Input Arguments:
 *         `n`         -    Number of control points of the curve.
 *         `p`         -    Degree of the curve.
 *         `U`         -    Knot vector of the curve.
 *         `Pw`        -    Control points of the curve.
 *         `u`         -    Parameter value at which to compute the point on the curve.
 * 
 *     Output Arguments:
 *         `C`         -    Computed point on the curve at parameter `u`.
 * 
 * Steps:
 *     i.Handle special cases for endpoints.
 *     ii.Find the span and multiplicity of the parameter `u` in the knot vector.
 *     iii.Compute the point on the curve using the corner cut method.
 */

#include <iostream>
#include <vector>
using namespace std;

void FindSpanMult(int n, int p, double u, vector<double>& U, int* k, int* s) {

}

void CurvePntByCornerCut(int n, int p, vector<double>& U, vector<double>& Pw, double u, double& C) {
    /* Special case: endpoint 特殊情況： 端點 */
    if (u == U[0])
    {
        C = Pw[0];
        return;
    }
    if (u == U[n + p + 1])
    {
        C = Pw[n];
        return;
    }

    /* General case 通用情況 */
    int k, s;
    FindSpanMult(n, p, u, U, &k, &s);
    int r = p - s;
    vector<double> Rw(r + 1);
    
    for (int i = 0; i <= r; i++)
    {
        Rw[i] = Pw[k - p + i];
    }

    for (int j = 1; j <= r; j++)
    {
        for (int i = 0; i <= r - j; i++)
        {
            double alpha = (u - U[k - p + j + i]) / (U[i + k + 1] - U[k - p + j + i]);
            Rw[i] = alpha * Rw[i + 1] + (1. - alpha) * Rw[i];
        }
    }
    C = Rw[0];
}

/* Example usage */
int main() {
    /* Example usage of the algorithms */
    int n = 5;  /* Number of control points */
    int p = 3;  /* Degree of the curve */
    vector<double> U = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 3.0, 3.0};
    vector<double> Pw = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    double u = 2.5; /* Parameter value to compute the point on the curve */
    double C;   /* Output point on the curve */

    /* Call the function */
    CurvePntByCornerCut(n, p, U, Pw, u, C);

    /* Output the result 輸出 結果 */
    cout << "Point on the curve at u = " << u << ": " << C << std::endl;

    return 0;
}