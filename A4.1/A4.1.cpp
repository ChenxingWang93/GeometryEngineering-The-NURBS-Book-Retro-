/* ARGUMENTS
 *     Input Arguments:
 *         `n`         -    number of control points minus 1.
 *         `p`         -    degree of the B-spline curve.
 *         `U`         -    knot vector of the B-spline curve.
 *         `Pw`        -    array of weighted control points.
 *         `u`         -    parameter value.
 *         `c`         -    output variable where the resulting point on the B-spline curve will be stored.
 * 
 *    Output Arguments:
 *         `C`         -    The points on the B-spline curve corresponding to the parameter value `u`.
 * 
 * Steps:
 *         i.          FindSpan: `span = FindSpan(n,p,u,U);`:Finds the span of the knot vector that contains the parameter value `u`.
 * 
 *         ii.         BasisFuns: `BasisFuns(Span,u,p,u,U,N);`:Computes the non-zero B-spline basis functions at `u` for the given span and degree, storing the results in the array `N`.
 * 
 *         iii.        Calculate Cw: `Cw = 0.0;`: Initializes a variable `Cw` to 0.
 * 
 *         iv.         `for (j=0; j<=p; j++)`:Loop over the non-zero basis functions.
 *                       i.`Cw = Cw + N[j]*Pw[span-p+j];`:Compute the weighted sum of control points based on the non-zero basis functions.
 * 
 *         v.          Calculate C: `C = Cw/w;`:Divides the computed sum by the total weight (`w`) to get the final point on the curve `C`.
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include "../findSpan.h"
#include "../BasisFuns.h"
using namespace std;

/* Functions for finding the span and computing the basis functions */
int FindSpan(int n, int p, double u, const vector<double>& U) {
    /* Implementation of finding the span 寻找跨度 */
    /* ... */
    return 0;
}

void BasisFuns(int span, double u, int p, const vector<double>& U, vector<double>& N) {
    /* Implementation of computing the basis functions 寻找基函数 */
    /* ... */
}

/* Main function for computing the point on the B-spline curve 用于计算在B-样条曲线上的点的主函数 */
void CurvePoint(int n, int p, vector<double>& U, const vector<double>& Pw, double u, vector<double>& C) {
    /* Find the knot span where the parameter u lies */
    int span = FindSpan(n, p, u, U);
    
    /* Initialize a vector to store the basis functions */
    vector<double> N(p + 1);
    
    /* Compute the basis functions at parameter u */
    BasisFuns(span, u, p, U, N);

    /* Initialize variable for weighted sum */
    double Cw = 0.0;

    for (int j = 0; j <= p; j++)
    {
        Cw += N[j] * Pw[span - p + j];
    }

    double w = 0.0;
    for (int j = 0; j <= p; j++)
    {
        w += Pw[span - p + j];
    }

    double weight = w != 0.0 ? Cw / w : 0.0;
    for (int i = 0; i < C.size(); i++)
    {
        C[i] = Pw[span - p + i] * weight; /* Divide by weight 除以权重 */
    }
}

int main() {
    /* Example usage */
    int n = 4;
    int p = 2;
    vector<double> U = {0.0, 0.0, 0.0, 1.0, 1.0, 1.0};
    vector<double> Pw = {1.0, 2.0, 3.0, 1.0, 1.0, 1.0};
    double u = 0.25;

    vector<double> C;
    CurvePoint(n, p, U, Pw, u, C);

    /* Print the resulting point on the curve 打印结果点在曲线上 */
    cout << "Point on the B-spline curve at parameter u = " << u << ": (" << C[0] << ", " << C[1] << ", " << C[2] << ")" << endl;

    return 0;
}