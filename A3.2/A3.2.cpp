/* ARGUMENTS
 *     Input Arguments: 
 *         `n`        -       Number of control points in the curve.
 *         `p`        -       Degree of the curve.
 *         `U`        -       Knot vector of the curve.
 *         `P`        -       Array of control points.
 *         `u`        -       Parameter value at which the derivatives of the curve are to be computed.
 *         `d`        -       Maximum derivative order to be computed.
 * 
 *     Output Arguments:
 *         `CK`        -      Array storing the computed curve derivatives up to order `d`.
 * 
 * Steps:
 *     i. Compute Derivative Order:
 *            Set `du` as the minimum of `d` and `p` to determine the actual derivative order to compute.
 * 
 *     ii. Initialize Higher Order Derivatives:
 *             For each derivative order `k` from `p+1` to `d`, set `CK[k]` to 0.0 as these derivatives are not computed.
 * 
 *     iii. Find Span:
 *              Use the `FindSpan` function to find the knot span index `span` based on the parameter value `u` and the
 *              knot vector `U`.
 * 
 *     iv. Compute Basis Function Derivatives
 *             Call the function `DersBasisFuns(span, u, p, du, Unders)` to compute the derivatives of the basis
 *             functions up to order `du` at the given parameter value `u`.
 * 
 *     v. Compute Curve Derivatives:
 *            For each derivative order `k` from 0 to `du`:
 *                Initialize `CK[k]` to 0.0.
 *                Iterate over the basis function derivatives `nders[k][j]` for `j` from 0 to `p`.
 *                For each basis function derivative, multiply the derivative value `nders[k][j]` with the corresponding
 *                control point `P[span - p + j]` and add it to the derivative `CK[k]`.
 * Example:
 * 
 *     Input: `n = 5`, `p = 2`, `U = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0}`, `P = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0}`, `u = 1.5`, `d = 2`
 * 
 *     Output: The derivatives of the curve up to order 2 at `u = 1.5` will be computed and stored in the array `CK`.
 * 
 * This algorithm efficiently calculates the derivatives of a curve at a specified parameter value up to a given order by
 * utilizing basis function derivatives and control points defined by the input parameters.
 * 
 */

#include <iostream>
#include <vector>
#include "../findSpan.h"
#include "../DersBasisFuns.h"
using namespace std;
void CurveDerivsAlg1(int n, int p, double* U, double* P, double u, int d, double* CK);

int FindSpan(int n, int p, double u, double* U) {
    /* Implementation of FindSpan function */
    /* This function is assumed to be implemented separately */
    /* and is used to find the knot span index */
    return 0; /* Placeholder return value */
}

void DersBasisFuns(int span, double u, int p, int du, double** Unders) {
    /* Implementation of DersBasisFuns function */
    /* This function is assumed to be implemented separately */
    /* and is used to compute the derivatives of basis functions at a given parameter u */
    /* The results are stored in the 2D array Unders */
}

void CurveDerivsAlg1(int n, int p, double* U, double* P, double u, int d, double* CK) {
    int du = min(d, p);

    for (int k = p + 1; k <= d; k++)
    {
        CK[k] = 0.0;
    }
    
    int span = FindSpan(n, p, u, U);
    /* Assuming this is a 2D array to store derivatives of basis functions */
    double** Unders;
    vector<vector<double>> Unders(du + 1,vector<double>(p + 1));
    DersBasisFuns(span, u, p, du, Unders);
    
    for (int k = 0; k <= du; k++)
    {
        CK[k] = 0.0;
        for (int j = 0; j <= p; j++)
        {
            CK[k] += Unders[k][j] * P[span - p + j];
        }
    }
}

int main() {
    /* Define input parameters 定义输入参数 */
    /* Number of control points */
    int n = 6;
    /* Degree of the curve */
    int p = 2;
    /* Maximum derivative order */
    int d = 4;
    /* Knot vector */
    double U[] = {0.0, 0.0, 0.0, 0.5, 1.0, 1.0, 1.0};
    /* Control points */
    double P[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    /* Parameter value */
    double u = 1.5;

    /* Initialize CK vector 初始化 CK 向量 */
    // vector<double> CK(d + 1);
    double CK[3];

    /* Call the CurveDerivsAlg1 function Call 曲线导数算法1 */
    CurveDerivsAlg1(n, p, U, P, u, d, CK);

    cout << "Curve derivatives at u = " << u << ":" << endl;
    for (int k = 0; k <= d; k++)
    {
        cout << "Derivative of order " << k << ": " << CK[k] << endl;
    }
    
    return 0;
}