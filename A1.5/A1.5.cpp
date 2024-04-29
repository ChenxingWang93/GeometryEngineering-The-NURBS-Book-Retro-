/* ARGUMENTS
 *     Input Arguments: 
 *         `P`        -    An array representing the control points of the Bezier curve.
 *         `n`        -    The degree of the Bezier curve.
 *         `u`        -    The parameter at which to compute the point on the Bezier curve.
 *     
 *     Outputs Arguments: 
 *         `C`        -    The computed point on the Bezier curve corresponding to the parameter `u`.
 * 
 * Steps:
 *     i. Initialize Q with P:
 *        Create a local array `Q` and initialize it with the same values as the input array `P`,which represents the control points of the Bezier curve.
 * 
 *     ii. Iterativa Calculation using de Casteljau algorithm:
 *         Iterate over `k` from 1 to `n`:
 *             For each iteration of `k`, iterate over `i` from 0 to `n - k`:
 *                 Update `Q[i]` using the de Casteljau algorithm:
 *                     `Q[i] = (1.0 - u) * Q[i] + u * Q[i + 1]`.
 *                     This calculates the intermediate control points of the Bezier curve based on the parameter `u`.
 * 
 *     iii. Set the Output Point C:
 *              Set the output point `C`  to be the first element of the array `Q`,which represents the computed point on the Bezier curve corresponding to the parameter `u`.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

void deCasteljau1(const vector<double>& P, int n, double u, double& C) {

    /* Initialize Q with the control points P */
    vector<double> Q(P);

    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <= n - k; i++)
        {
            Q[i] = (1.0 - u) * Q[i] + u * Q[i + 1];
        }
    }

    /* Set the output point C to the computed point */
    C = Q[0];
}

int main() {

    /* Example value of n */
    int n = 3;

    /* Example value of u */
    double u = 0.5;

    /* Control points of the Bezier curve */
    vector<double> P = {1.0, 2.0, 3.0, 4.0};

    /* Call the deCasteljau1 function */
    double C;

    /* Output the computed point on the Bezier curve using de Casteljau algorithm */
    cout << "Point on Bezier curve at u = " << u << ": " << C << endl;

    return 0;
}