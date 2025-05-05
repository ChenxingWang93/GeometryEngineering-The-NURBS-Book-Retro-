/* ARGUMENTS
 *     Input Arguments:
 *         `CurvePoint`-    is the function name.
 *         `n`         -    is the number of control points in the curve.
 *         `p`         -    is the degree of the basis function.
 *         `U`         -    is the knot vector of the curve.
 *         `P`         -    is the Array of control points.
 *         `u`         -    is the parameter value at which the curve point is to be computed.
 *         `C`         -    is the output variable to store the computed curve point.
 * 
 *     Output Arguments:
 *         `C`         -    Computed curve point at the parameter value `u`
 * 
 * Steps:
 *         i. Find Span:
 *                The algorithm first calls a function `FindSpan(n, p, u, U)` to find the knot span index `span` based on the
 *                parameter value `u` and the knot vector `U`.
 * 
 *         ii. Compute Basis Functions:
 *                 The algorithm then calls a function `BasisFuns(span, u, p, U, N)` to compute the basis functions at the
 *                 given parameter value `u` and stores the results in an array `N`.
 * 
 *         iii.Compute Curve Point:
 *                 The algorithm then calls a function `BasisFuns(span, u, p, U, N)` to compute the basis functions at the
 *                 given parameter value `u` and the knot vector `U`.
 * 
 *         iv. Compute Curve Point:
 *                 Initialize the curve point `C` to 0.0.
 *                 Iterate over the basis function `N[i]` for `i` from 0 to `p`.
 *                 For each basis function, multiply the basis function value(summing up the product of each basis function value) `N[i]` 
 *                 with the corresponding control point `P[span - p + i]` and add it to the curve point `c`.
 * 
 *         v. Output:
 *                The final curve point `C` is the output of the algorithm, representing the point on the curve at the 
 *                parameter value `u`.
 * 
 * Example:
 * 
 *     Input: `n = 5`,`p = 2`,`U = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0}`,`P = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0}`,`u = 1.5`
 *     
 *     Output: The curve point at `u = 1.5` will be computed and stored in the variable `C`.
 * 
 * This algorithm efficiently calculates the point on a curve at a given parameter value by utilizing basis functions and 
 * control points defined by the input parameters.
 * 
 */

#include <iostream>
#include <vector>
#include "../findSpan.h"
#include "../BasisFuns.h"
using namespace std;

void CurvePoint(int n, int p, double* U, double* P, double u, double& C);

int FindSpan(int n, int p, double u, const vector<double>& U) {
    /* Implementation of FindSpan function */
    /* This function is assumed to be implemented separately */
    /* and is used to find the knot span index */
    return 0; /* Placeholder return value */
}

void BasisFuns(int span, double u, int p, const vector<double>& U, vector<double>& N) {
    /* Implementation of BasisFuns function */
    /* This function is assumed to be implemented separately */
    /* and is used to compute the basis functions at a given parameter u */
    /* The results are stored in the array N */
}

void CurvePoint(int n, int p, double* U, double** P, double* C)
{
    /* 计算弧线点Compute curve point */
    /* 输入Input:  n,p,U,P,u */
    /* 输出Output: C */
    double N[20];
    double u;
    /* Find the span of the knot vector 找到结点向量的跨度 */
    int span = FindSpan(n, p, u, U);

    /* Compute the basis functions 计算基函数 */
    BasisFuns(span, u, p, U, N);

    /* Initialize C to store the computed curve point 初始化 C 存储已计算的弧形点 */
    C[0] = 0.0;

    for (int i = 0; i <= p; i++)
    {
        C[0] += N[i] * P[span - p + i][0];
    }
}

int main() {
    
    int n = 5;    /* Number of control points */
    int p = 2;    /* Degree of the curve */
    double U[] = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0};    /* Knot vector */
    double P[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};    /* Control points */
    double u = 1.5;    /* Parameter value */
    double C;    /* Curve point */

    CurvePoint(n, p, U, P, u, C);

    /* Output the computed curve point */
    cout << "Curve point at u = " << u << ": " << C << endl;

    return 0;
}