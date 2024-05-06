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
 *         `u`,`v`    -         Parameters at which the surface derivatives are to be computed.
 *         `d`        -         Maximum derivative order.
 *  
 *     Output Arguments:
 *                  SKL:
 *                  Computed surface derivatives stored in a 2D array.
 * 
 * Steps:
 *     i. Compute Minimum Derivative Orders:
 *            `du = min(d, p)`:Compute the minimum of the maximum derivative order `d` and the degree of the B-
 *            spline curve in the u-direction `p`.
 * 
 *            `dv = min(d, q)`:Compute the minimum of the maximum derivative order `d` and the degree of the B-
 *            spline curve in the v-direction `q`.
 * 
 *     ii. Compute Control Points of Derivative Surfaces:
 *             Calculate the difference in index ranges for control points: `r = r2 - r1` & `s = s2 - s1`.
 * 
 *             Iterate over the v-direction control points:
 *                 Call `CurveDerivCpts` function to compute derivative control points for each curve in the u-direction.
 *                 
 *                 Store the computed derivative control points in temporary storage `temp`.
 *                 
 *                 Copy the computed control points to the appropriate locations in the `PKL` array.
 * 
 *     iii. Compute Derivative Control Points in the u-direction:
 *              Iterate over the u-direction derivative orders:
 *                  Iterate over the control points in the u-direction(`r - k` iterations).
 * 
 *                  Call `CurveDerivCpts` function to compute derivative control points for each curve in the v-direction.
 * 
 *                  Store the computed derivative control points in temporary storage `temp`.
 *  
 *                  Copy the computed control points to the appropriate locations in the `PKL` array.
 * 
 * Algorithm A3.8 for computing surface derivatives on a B-spline surface.
 * 
 */                 

#include "../findSpan.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int FindSpan(int n, int p, double u, const vector<double>& U) {
    /* Implementation of FindSpan algorithm */
    /* This function is not provided here, assuming it's implemented elsewhere */
    /* Returns the span */
    return 0;
}

void AllBasisFuns(int span, double u, int p, const vector<double>& U, vector<double>& Nu) {
    /* Implementation of AllBasisFuns algorithm */
    /* This function is not provided here, assuming it's implemented elsewhere */
    /* Computes all basis functions and stores them in the Nu array */
}

void SurfaceDerivCpts(int n, int p, const vector<double>& U, int m, int q, const vector<double>& V,
                      const vector<vector<double>>& P, int d, int r1, int r2, int s1, int s2,
                      vector<vector<vector<vector<double>>>>& PKL) {
    /* Implementation of SurfaceDerivCpts algorithm */
    /* This function is not provided here, assuming it's implemented elsewhere */
    /* Computes surface derivative control points and stores them in the PKL array */
}

void SurfaceDerivsAlgs2(int n, int p, const vector<double>& U, int m, int q, const vector<double>& V,
                        const vector<vector<double>>& P, double u, double v, int d, 
                        vector<vector<double>>& SKL) {
    int du = min(d, p);
    int dv = min(d, q);

    for (int k = p + 1; k <= d; k++)
    {
        for (int l = 0; l <= d; l++)
        {
            SKL[k][l] = 0.0;
        }
    }

    for (int l = q + 1; l <= d; l++)
    {
        for (int k = 0; k <= d - 1; k++)
        {
            SKL[k][l] = 0.0;
        }
    }
    
    int uspan = FindSpan(n, p, u, U);
    vector<double> Nu(p + 1);
    AllBasisFuns(uspan, u, p, U, Nu);

    int vspan = FindSpan(m, q, v, V);
    vector<double> Nv(q + 1);
    AllBasisFuns(vspan, v, q, V, Nv);

    vector<vector<vector<vector<double>>>> PKL(du + 1,
        vector<vector<vector<double>>>(dv + 1,
            vector<vector<double>>(p + 1, vector<double>(q + 1))));

    SurfaceDerivCpts(n, p, U, m, q, V, P, d, uspan - p, uspan, vspan - q, vspan, PKL);

    for (int k = 0; k <= du; k++)
    {
        int dd = min(d - k, dv);
        for (int l = 0; l <= dd; l++)
        {
            SKL[k][l] = 0.0;
            for (int i = 0; i <= q - l; i++)
            {
                double tmp = 0.0;
                for (int j = 0; j <= p - k; j++)
                {
                    tmp += Nu[j] * PKL[k][l][j][i];
                }
                SKL[k][l] += Nv[i] * tmp;
            }
        }
    }
}

int main() {
    int n = 5;
    int p = 2;
    vector<double> U = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};

    int m = 5;
    int q = 2;
    vector<double> V = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};
    vector<vector<double>> P = {{0.0, 0.0, 0.0},
                                {1.0, 1.0, 1.0},
                                {2.0, 2.0, 2.0},
                                {3.0, 3.0, 3.0},
                                {4.0, 4.0, 4.0},
                                {5.0, 5.0, 5.0}};
                                
    double u = 0.5;
    double v = 0.5;
    int d = 3;

    vector<vector<double>> SKL(d + 1, vector<double>(d + 1, 0.0));

    SurfaceDerivsAlgs2(n, p, U, m, q, V, P, u, v, d, SKL);

    for (int k = 0; k <= d; k++)
    {
        for (int l = 0; l <= d; l++)
        {
            cout << "SKL[" << k << "][" << l << "] = " << SKL[k][l] << endl;
        }
    }
    
    return 0;
}