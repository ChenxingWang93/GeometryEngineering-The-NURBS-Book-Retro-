#include <vector>
#include "../findSpan.h"
#include "../BasisFuns.h"
using namespace std;
void CurvePoint(int n, int p, const vector<double>& U, const vector<double>& C)
{
    int span = FindSpan(n, p, u, U);
    vector<double> N(p + 1, 0.0);

    BasisFuns(span, u, p, U, N);

    C.assign(P.size(), 0.0);

    for (int i = 0; i <= p; i++)
    {
        C = C + N[i] * P[span - p + i];
    }
}