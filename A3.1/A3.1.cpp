/* ARGUMENTS
 *     Input Arguments: 
 *         `CurvePoint`-    is the function name.
 *         `n`         -    is the degree of the curve.
 *         `p`         -    is the degree of the basis function.
 *         `U`         -    is the knot vector.
 *         `P`         -    is the control points.
 *         `u`         -    is the parameter at which to evaluate the curve.
 *         `C`         -    is the computed curve point.
 * Steps:
 *         
 *         The function first finds the span of the knot vector where the parameter
 *         `u` lies using `FindSpan` function. Then, it computes the basis functions
 *         `N` at the given parameter `u` and stores them in the array `N`
 *         Finally, it computes the curve point `C` by summing up the product of each basis function value
 *         `N[i]` and its corresponding control point `P[span-p+i]`.
 */

#include <vector>
#include "../findSpan.h"
#include "../BasisFuns.h"
using namespace std;

void CurvePoint(int n, int p, const vector<double>& U, const vector<double>& C)
{
    /* 计算弧线点Compute curve point */
    /* 输入Input:  n,p,U,P,u */
    /* 输出Output: C */
    
    int span;
    vector<double> N(p + 1);

    /* Find the span of the knot vector 找到结点向量的跨度 */
    span = FindSpan(n, p, u, U);

    /* Compute the basis functions 计算基函数 */
    BasisFuns(span, u, p, U, N);

    /* Initialize C to store the computed curve point 初始化 C 存储已计算的弧形点 */
    C.assign(P.size(), 0.0);
    
    /**/
    for (int i = 0; i <= p; i++)
    {
        for (int j = 0; j < P.size(); j++)
        {
            C[j] += N[i] * P[span - p + i];
            /* C = C + N[i] * P[span - p + i]; */
        }
    }
}
