#include <vector>
#include "../findSpan.h"
#include "../BasisFuns.h"
using namespace std;

void CurvePoint(int n, int p, const vector<double>& U, const vector<double>& C)
{
    int span;
    vector<double> N(p + 1);

    /* Find the span of the knot vector */
    span = FindSpan(n, p, u, U);

    /* Compute the basis functions */
    BasisFuns(span, u, p, U, N);

    /* Initialize C to store the computed curve point */
    C.assign(P.size(), 0.0);

    /**/
    for (int i = 0; i <= p; i++)
    {
        for (int j = 0; j < P.size(); j++)
        {
            C[j] += N[i] * P[span - p + i];
            /*C = C + N[i] * P[span - p + i];*/
        }
    }
}