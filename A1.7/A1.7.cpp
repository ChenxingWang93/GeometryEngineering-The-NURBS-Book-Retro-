/* ARGUMENTS
 *     Input Arguments:
 *         `P`        -     A 2D vector representing the control points of the Bezier surface.
 *         `n`        -     An integer representing the degree of the Bezier surface in the u-direction.
 *         `m`        -     An integer representing the degree of the Bezier surface in the v-direction.
 *         `u0`       -     A double representing the parameter value in the u-direction.
 *         `v0`       -     A double representing the parameter value in the v-direction.
 * 
 *     Output Arguments:
 *         `S`        -     A double representing the computed point on the Bezier surface at parameters `u0` and `v0`.
 * 
 * Steps:
 *     i. `deCasteljau1` Function:
 *            This function computes a point on a Bezier surface using the deCasteljau algorithm. It takes the control
 *            point `P`,degree `n`,parameter `u`,and outputs the computed point `C`.
 * 
 *     ii. `deCasteljau2` Function:
 *             This function computes a point on a Bezier surface using the de Casteljau algorithm. It first checks if `n` is 
 *             less than or equal to `m`.
 *                 If `n <= m`,it iterates over the rows of control points `P` and applies `deCasteljau1` to
 *                 each row to get intermediate points in the `Q` array. Then, it applies `deCasteljau1` to `Q`
 *                 to get the final point `S`.
 *                 
 *                 If `n > m`,it iterates over the columns of control points `P` and applies `deCasteljau1` to 
 *                 each column to get intermediate points in the `Q` array. Then, it applies `deCasteljau1` to 
 *                 `Q` to get the final point `S`.
 * 
 *     iii. `main` Function:
 *              In the `main` function, example values for `n`, `m`, `u0`, `v0`,and control point `P` are provided.
 *              The `deCasteljau2` function is called with these inputs to compute the point on the Bezier surface at
 *              parameters `u0` and `v0`.
 *              The computed point `S` is then outputted to the console.
 * 
 */

#include <iostream>
#include <vector>
#include "../deCasteljau1.h"
using namespace std;

void deCasteljau1(const vector<double>&P, int n, double u, double& C) {
    /* Initialize Q with the control points P */
    vector<double> Q(P);

    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <= n - k; i++)
        {
            Q[i] = (1.0 - u) * Q[i] + u * Q[i + 1];   
        }
    }

    /* Set the output point C to be the computed point */
    C = Q[0];
}

void deCasteljau2(const vector<vector<double>>& P, int n, int m, double u0, double v0, double& S) {

    /* Temporary array for intermediate results */
    vector<double> Q(max(n,m) + 1, 0.0);
    
    if (n <= m)
    {
        for (int j = 0; j <= m; j++)
        {
            deCasteljau1(P[j], n, u0, &Q[j]); /* P[j][] is jth row */
        }
        deCasteljau1(Q, m, v0, &S);
    } else {
        for (int i = 0; i <= n; i++)
        {
            vector<double> column;
            for (int j = 0; j <= m; j++)
            {
                column.push_back(P[j][i]);
            }
            deCasteljau1(column, m, v0, Q[i]); /* P[][i] is ith column */
        }
        deCasteljau1(Q, n, u0, S);
    }
}

int main() {
    /* Example value of n */
    int n = 2;

    /* Example value of m */
    int m = 2;

    /* Example value of u0 */
    double u0 = 0.3;

    /* Example value of v0 */
    double v0 = 0.6;

    /* Control points of the Bezier surface */
    vector<vector<double>> P = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

    /* Call the deCasteljau2 function */
    deCasteljau2(P, n, m, u0, v0, S);

    /* Output the computed point on the Bezier surface using de Casteljau algorithm */

    cout << "Point on Bezier surface at (u0, v0) = (" << u0 << ", " << v0 << "): " << S << endl;

    return 0;
}
