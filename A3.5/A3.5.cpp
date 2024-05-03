/* ARGUMENTS 
 *     Input Arguments:
 *          Parameters:
 *         `n`        -         Degree of the B-spline curve in the u-direction.
 *         `p`        -         Degree of the B-spline curve in the v-direction.
 *         `U`        -         Knot vector in the u-direction with `(n+1)` knots.
 *         `m`        -         Degree of the B-spline curve in the v-direction.
 *         `q`        -         Degree of the B-spline curve in the v-direction.
 *         `V`        -         Knot vector in the v-direction with `(m+1)` knots.
 *         `P`        -         Control points of the B-spline surface, typically given as a 2D array.
 *         `u`,`v`    -         Parameters at which the surface point is to be computed.
 *  
 *     Output Arguments:
 *        Surface Point:
 *         `S`        -         The computed surface point at the coordinates `(u, v)` on the B-spline surface.
 * 
 *  Steps:
 *      i. Find Spans:
 *             `uspan = FindSpan(n, p, u, U)`: Find the span in the u-direction using the `FindSpan` algorithm.
 *             `vspan = FindSpan(m, q, v, V)`: Find the span in the v-direction using the `FindSpan` algorithm.
 * 
 *      ii. Compute Basis Functions:
 *              `BasisFuns(uspan, u, p, U, Nu)`: Compute the basis functions in the u-direction using the `BasisFuns`
 *              algorithm and store the results in `Nu`.
 *              
 *              `BasisFuns(vspan, v, p, V, Nv)`: Compute the basis functions in the v-direction using the `BasisFuns`
 *              algorithm and store the results in `Nv`.
 * 
 *      iii. Initialize Variables:
 *               `uind = uspan - p`: Initialize the variable `uind` to start from the correct row index in the control points
 *               array.
 * 
 *               Initialize `S`(surface point) to `0.0`.
 * 
 * 
 *      iv. Iterate to Compute Surface Point:
 *              For each `l` from `0` to `q`:
 *                  Initialize `temp` as `0.0`.
 * 
 *                  Calculate `vind = vspan - q + l` to start from the correct column index in the control points array.
 * 
 *                  For each `k` from `0` to `p`:
 *                      Update `temp` by adding `Nu[k] * P[uind + k][vind]`.
 * 
 *                  Updates `S` by adding `Nv[l] * temp` to compute the surface point.
 * 
 *      v. Output:
 *             The computed surface point `S` at the coordinates `(u, v)` on the B-spline surface.
 * 
 * Summary
 * 
 * Algorithm A3.4 involves finding spans, computing basis functions, and iterating through nested loops to calculate
 * the surface point on a B-spline surface at the given parameters `u` and `v`. The algorithm utilizes the control
 * points, knot vectors, and degrees of the B-spline curves to interpolate and compute the surface point.
 * 
 */


#include <iostream>
#include <vector>
using namespace std;

int FindSpan(int n, int p, double u, vector<double>& U) {
    /* Implementation of FindSpan function */
    /* This function is not provided here, assuming it's implemented elsewhere */
    /* Returns the span */
    return 0;

}

void BasisFuns(int span, double u, int p, const vector<double>& U, vector<double>& Nu) {
    /* Implementation of BasisFuns function */
    /* (Assuming BasisFuns function is available for use in the algorithm) */
}

void SurfacePoint(int n, int p, vector<double>& U, int m, int q, const vector<double>& V, const vector<vector<double>>& P, double u, double v, vector<vector<double>>& S) {
    /*  Compute surface point计算曲面上的点  */
    /*  输入Input:  n,p,U,m,q,V,P,u,v  */
    /*  输出Output: S  */
    int uspan = FindSpan(n, p, u, U);

    vector<double> Nu(p+1, 0.0);
    BasisFuns(uspan, u, p, U, Nu);

    int vspan = FindSpan(m, q, v, V);

    vector<double> Nv(q+1, 0.0);
    BasisFuns(vspan, v, q, V, Nv);

    int uind = uspan - p;
    S.assign(3, vector<double>(3, 0.0)); /* Assuming S is a 3x3 matrix 假设S为一个3x3矩阵 */

    for (int l = 0; l <= q; l++)
    {
        double temp = 0.0;
        int vind = vspan - q + l;
        for (int k = 0; k <= p; k++)
        {

            temp += Nu[k] * P[uind + k][vind];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                S[i][j] +=Nv[l] * temp;
            }
        }
    }
}

int main() {
    /* Define n, p, U, m, q, V, P, u, v */

    int n = 5;
    int p = 2;
    vector<double> U = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};

    int m = 5;
    int q = 2;
    vector<double> V = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};

    /* Control points */
    vector<vector<double>> P = {{0.0, 0.0, 0.0},
                                {1.0, 1.0, 1.0},
                                {2.0, 2.0, 2.0},
                                {3.0, 3.0, 3.0},
                                {4.0, 4.0, 4.0},
                                {5.0, 5.0, 5.0}};

    double u = 0.5;
    double v = 0.5;
    /* Call SurfacePoint function with the input parameters */
    /* Output the resulting surface point S */
    vector<double> S;

    /* Compute surface point */
    SurfacePoint(n, p, U, m, q, V, P, u, v, S);

    for (size_t i = 0; i < S.size(); i++)
    {
        cout << "S[" << i << "] =" << S[i] << endl;
    }

    return 0;
}