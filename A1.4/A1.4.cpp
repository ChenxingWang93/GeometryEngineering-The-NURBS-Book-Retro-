/* ARGUMENTS
 *     Input Arguments:
 *         `P`        -    An array of control points of the Bezier curve.
 *         `n`        -    The degree of the Bezier curve.
 *         `u`        -    The parameter at which the point on the Bezier curve needs to be computed.
 * 
 *     Outputs Arguments:
 *         `C`        -    The computed point on the Bezier curve.
 * 
 * Steps:
 *     i. Call the `AllBernstein` function to compute all nth-degree Bernstein polynomials and store them in an array `B`.
 * 
 *     ii. Initialize the point `C` to be zero vector(0.0 in each dimension).
 * 
 *     iii. For each control point `P[k]`, multiply it by the corresponding Bernstein polynomial `B[k]` and accumulate the results to obtain the point `C`.
 * 
 */

#include <iostream>
#include <vector>
#include "../AllBernstein.h"
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

void PointOnBezierCurve(const vector<double>& P, int n, double u, double& C) {
    /* Array to store Bernstein polynomials */
    vector<double> B(n + 1, 0.0);


    /* Compute Bernstein polynomials */
    AllBernstein(n, u, B);

    C = 0.0;

    for (int k = 0; k <= n; k++)
    {
        C += B[k] * P[k];
    }
}

int main() {
    /* Example value of n */
    int n = 3;

    /* Example value of u */
    double u = 0.5;

    /* Control points of the Bezier curve */
    vector<double> P = {1.0, 2.0, 3.0, 4.0};

    /* Point on the Bezier curve */
    double C;

    /* Output the computed point on the Bezier curve */
    cout << "Point on Bezier curve at u = " << u << ": " << C << endl;

    return 0;
}