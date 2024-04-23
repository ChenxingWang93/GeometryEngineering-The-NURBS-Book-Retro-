/* ARGUMENTS
 *     Input Arguments: 
 *         `n`         -    number of control points minus 1.
 *         `p`         -    degree of the curve.
 *         `U`         -    knot vector.
 *         `Pw`        -    array of weighted control points.
 *         `u`         -    parameter value.
 *         `c`         -    output point on the curve.
 * Steps:
 *         i.          `span = FindSpan(n,p,u,U);`:Finds the span of the knot vector that contains the parameter value `u`.
 *         ii.         `BasisFuns(Span,u,p,u,U,N);`:Computes the non-zero B-spline basis functions at `u` for the given span and degree, storing the results in the array `N`.
 *         iii.        `Cw = 0.0;`: Initializes a variable `Cw` to 0.
 *         iv.         `for (j=0; j<=p; j++)`:Loop over the non-zero basis functions.
 *                       i.`Cw = Cw + N[j]*Pw[span-p+j];`:Compute the weighted sum of control points based on the non-zero basis functions.
 *         v.          `C = Cw/w;`:Divides the computed sum by the total weight (`w`) to get the final point on the curve `C`
 */

#include <iostream>
#include <vector>
#include "../findSpan.h"
#include "../BasisFuns.h"

/* Functions for finding the span and computing the basis functions */
int FindSpan() {
    /* Implementation of finding the span */
    /* ... */
}
void BasisFuns() {
    /* Implementation of computing the basis functions */
    /* ... */
}
/* Main function for computing the point on the B-spline curve 用于计算在B-样条曲线上的点的主函数 */
void CurvePoint(int n, int p, vector<double>& U, vector<double>& Pw, double u, vector<double>& C) {
    int span = FindSpan(n, p, u, U);
    vector<double> N(p+1);
    BasisFuns(span, u, p, U, N);
    double Cw = 0.0;
    double w = 0.0;
    for (int j = 0; j <= p; j++)
    {
        Cw += N[j] * Pw[span-p+j];
        w += Pw[span-p+j];
    }
    double weight = w != 0.0 ? Cw / w : 0.0;
    for (int i = 0; i < C.size(); i++)
    {
        C[i] = Pw[span-p+i] * weight; /* Divide by weight 除以权重 */
    }
}
int main() {
    /* Example usage */
    int n = 4;
    int p = 2;
    vector<double> U = {0.0, 0.0, 0.0, 0.5, 1.0, 1.0, 1.0};
    vector<double> Pw = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    double u = 0.25;
    vector<double> C(n);
    CurvePoint(n, p, U, Pw, u, C);
    /* Print the resulting point on the curve 打印结果点在曲线上 */
    for (int i = 0; i < C.size; i++)
    {
        cout << "C[" << i << "] = " << C[i] << endl;
    }
    return 0;    
}