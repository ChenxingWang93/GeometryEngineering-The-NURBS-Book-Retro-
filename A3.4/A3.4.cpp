/* ARGUMENTS
 *     Input Arguments:
 *         `n`        -         Number of control points in the curve.
 *         `p`        -         Degree of the curve.
 *         `U`        -         Knot vector of the curve.
 *         `P`        -         Array of control points.
 *         `u`        -         Parameter value at which the curve derivatives are to be computed.
 *         `d`        -         Maximum derivative order.
 *         `CK`       -         Output variable to store the computed curve derivatives.
 * 
 *     Output Arguments:
 *         `CK`        -        Computed curve derivatives at the parameter value `u`.
 * 
 * Steps:
 *     i. Compute Derivative Order:
 *            Compute `du` as the minimum of `d` and `p`.
 * 
 *     ii. Initialize Curve Derivatives:
 *             Set `CK[k] = 0.0` for `k` from `p + 1` to `d`.
 * 
 *     iii. Find Span:
 *              Find the knot span index `span` using the `FindSpan` function based on `u`,`p`,`u`,and `U`.
 * 
 *     iv. Compute Basis Functions:
 *             Calculate all basis functions at the knot span `span` and parameter `u` using the `AllBasisFuns` function.
 *             Store the results in the array `N`.
 * 
 *     v. Compute Curve Derivative Control Points:
 *            Call the `CurveDerivCpts` function to compute the control points of curve derivatives.
 *            
 *            Pass parameters `n`,`p`,`U`,`P`,`du`,`span-p`,and`span`to`CurveDerivCpts`.
 *            
 *            Store the computed control points in the 2D vector `PK`.
 * 
 *     vi. Compute Curve Derivatives:
 *             Initialize `CK[k] = 0.0` from 0 to `du`.
 *             
 *             For each derivative order `k`, calculate the curve derivative using the basis function `N` and control points
 *             `PK`.
 * 
 * Example:
 * 
 *     - Input: `n = 5`, `p = 2`, `U = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0}`, `P = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0}`, `u = 1.5`, `d = 2`
 * 
 *     - Output: The curve derivatives at `u = 1.5` up to order `d` will computed and stored in array `CK`.
 * 
 * This algorithm efficiently calculates the curve derivatives up to a specified order at a given parameter value by
 * utilizing basis functions, control points, and derivative control points as intermediate steps.
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "../findSpan.h"

int FindSpan(int n, int p, double u, double* U) {
    /* Implementation of FindSpan function */
    /* This function is assumed to be implemented separately */
    /* and is used to find the knot span index */
    return 0; /* Placeholder return value */
}

void AllBasisFuns(int span, double u, int p, double* U, double** N) {
    /* Implementation of AllBasisFuns function */
    /* This function is assumed to be implemented separately */
    /* and is used to compute all basis functions at a given parameter u */
    /* The results are stored in the 2D vector N */
}

void CurveDerivsCpts(int n, int p, double* U, double* P, int d, int r1, int r2, vector<vector<double>>& PK) {
    /* Implementation of CurveDerivCpts function */
    /* This function computes the control points of curve derivatives */
    /* The results are stored in the 2D vector PK */
}

void CurveDerivsAlg2(int n, int p, double* U, double* P, double u, int d, double* CK);

void CurveDerivsAlg2(int n, int p, const vector<double>& U, const vector<double>& P, double u, int d, vector<double>& CK) {
    /* Compute curve derivatives */
    /* 输入Input:  n,p,U,P,u,d */
    /* 输出Output: CK */
    int du = min(d, p);

    for (int k = p + 1; k <= d; k++)
    {
        CK[k] = 0.0;
    }
    
    double** N;
    int span = FindSpan(n, p, u, U);

    AllBasisFuns(span, u, p, U, N);

    vector<vector<double>> PK(d + 1, std::vector<double>(span - p + 1, 0.0));
    
    CurveDerivsCpts(n, p, U, P, du, span - p, span, PK);

    for (int k = 0; k <= du; k++)
    {
        CK[k] = 0.0;
        for (int j = 0; j < p - k; j++)
        {
            CK[k] += N[j][p - k] * PK[k][j];
        }
    }
}

int main() {
    /* Define input parameters 定义输入参数 */
    int n = 5;
    int p = 2;
    vector<double> U = {0.0, 0.25, 0.5, 0.75, 1.0};
    vector<double> P = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double u = 0.5;
    int d = 3;

    /* Initialize CK vector 初始化 CK 向量 */
    vector<double> CK(d + 1, 0.0);

    /* Call CurveDerivsAlg2 function Call 弧形导数算法2函数 */
    CurveDerivsAlg2(n, p, U, P, u, d, CK);

    cout << "Curve derivatives at u = " << u << ":" << endl;
    for (int k = 0; k = d; k++)
    {
        cout << "Derivative of order " << k << ": " << "CK[k]" << endl;
    }
    
    return 0;
}