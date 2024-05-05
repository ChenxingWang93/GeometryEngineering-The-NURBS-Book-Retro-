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
 *         `d`        -         Maximum derivative order.
 *         `r1`,`r2`  -         Index range of control points in the u-direction.
 *         `s1`,`s2`  -         Index range of control points in the v-direction.
 * 
 *     Output Arguments:
 *         PKL:
 *         Control points of the derivative surface, stored in a 4D array.
 * 
 * Steps:
 *     i. Compute Minimum Derivative Orders:
 *            `du = min(d, p)`: Compute the minimum of the maximum derivative order `d` and the degree of the B-spline curve in the u-direction `p`.
 *            
 *            `dv = min(d, q)`: Compute the minimum of the maximum derivative order `d` and the degree of the B-spline curve in the u-direction `q`.
 * 
 *     ii. Compute Control Points of Derivative Surfaces:
 *             Calculate the difference in index ranges for control points: `r = r2 - r1` and `s = s2 - s1`.
 *             Iterate over the v-direction control points:
 *                 Call `CurveDerivCpts` function to compute derivative control points for each curve in the u-direction.
 *                 
 *                 Store the computed derivative control points in temporary storage `temp`.
 *                 
 *                 Copy the computed control points to the appropriate locations in the `PKL` array.
 * 
 *     iii. Compute Derivative Control Points in the u-direction:
 *              Iterate over the u-direction derivative orders:
 *                  Iterate over the control points in the u-direction (`r - k` iterations).
 *                  
 *                  Call `CurveDerivCpts` function to compute derivative control points for each curve in the v-direction.
 *                  
 *                  Store the computed derivative control points in temporary storage `temp`.
 *                  
 *                  Copy the computed control points to the appropriate location in the `PKL` array.
 * Summary:
 * Algorithm A3.7 calculates the control points of derivative surfaces based on the given B-spline surface and derivative order parameters. It iterates over the control points, computes
 * derivative control points for each curve in both u and v directions, and stores the results in a multi-dimensional array `PKL`. The algorithm utilizes the CurveDerivCpts function to
 * compute derivative control points for individual curves.
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Function declaration for CurveDerivCpts 曲面导控制点函数的声明 */
void CurveDerivCpts(int n, int p, const vector<double>& U, const vector<double>& P, int d, int r1, int r2, vector<vector<double>>& temp) {
    /* Implementation of CurveDerivCpts algorithm */
    /* This function is not provided here, assuming it's implemented elsewhere */
    /* Computes control points of derivative curves and stores them in the temp array */
}

/* Function to compute control points of derivative surfaces 计算导曲面上的控制点 */
void SurfaceDerivCpts(int n, int p, const vector<double> U, int m, int q, const vector<double>& V,
                      const vector<vector<vector<double>>>& P, int d, int r1, int r2, int s1, int s2,
                      vector<vector<vector<vector<double>>>>& PKL) {
    int du = min(d, p);
    int dv = min(d, q);
    int r = r2 - r1;
    int s = s2 - s1;

    // vector<vector<double>> temp;

    for (int j = s1; j <= s2; j++)
    {
        vector<vector<double>> temp(du + 1, vector<double>(r + 1));
        CurveDerivCpts(n, p, U, P[0][j], du, r1, r2, temp);

        for (int k = 0; k <= du; k++)
        {
            for (int i = 0; i <= r - k; i++)
            {
                PKL[k][0][i][j - s1] = temp[k][i];
            }
        }
    }
    
    for (int k = 0; k < du; k++)
    {
        for (int i = 0; i <= r - k; i++)
        {
            int dd = min(d - k, dv);
            vector<vector<double>> temp(dd + 1, vector<double>(s + 1));
            CurveDerivCpts(m, q, V, PKL[k][0][i], dd, 0, s, temp);

            for (int l = 1; l <= dd; l++)
            {
                for (int j = 0; j < s - l; j++)
                {
                    PKL[k][l][i][j] = temp[l][j];
                }
            }
        }
    }
}

int main() {
    /* Example usage of SurfaceDerivCpts 曲面导数控制点 */
    int n = 5; /* Degree in u-direction */
    int p = 2; /* Degree in v-direction */
    vector<double> U = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};
    int m = 5; /* Degree in v-direction */
    int q = 2; /* Degree in v-direction */
    vector<double> V = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};

    int d = 3; /* Maximum derivative order */
    int r1 = 0, r2 = 2; /* Range for r */
    int s1 = 0, s2 = 2; /* Range for s */

    vector<vector<vector<vector<double>>>> PKL(d + 1, vector<vector<vector<double>>>(d + 1, vector<vector<double>>(d + 1, vector<double>(d + 1, 0.0))));
    
    vector<vector<vector<double>>> P; /* Control points of the B-spline surface */
    /* Initialize P with some values */
    /* For simplicity, let's assume P is a 3x3x3 array */
    P = {{{1.0, 2.0, 3.0},
          {4.0, 5.0, 6.0},
          {7.0, 8.0, 9.0}},
         {{10.0, 11.0, 12.0},
          {13.0, 14.0, 15.0},
          {16.0, 17.0, 18.0}},
         {{19.0, 20.0, 21.0},
          {22.0, 23.0, 24.0},
          {25.0, 26.0, 27.0}}};

    SurfaceDerivCpts(n, p, U, m, q, V, P, d, r1, r2, s1, s2, PKL);

    /* Output the computed control points of derivative surfaces */
    for (int k = 0; k <= d; k++)
    {
        for (int l = 0; l <= d - k; l++)
        {
            for (int i = 0; i <= d - k - l; i++)
            {
                for (int j = 0; j <= d - k - l - i; j++)
                {
                    cout << "PKL[" << k << "][" << l << "][" << i << "][" << j << "] = " << PKL[k][l][i][j] << endl;
                }
            }
        }
    }

    return 0;
}