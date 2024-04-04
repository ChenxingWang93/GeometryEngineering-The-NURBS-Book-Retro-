#include <vector>
using namespace std;

/* Function to find the span of the knot vector where the parameter u lies */
int FindSpan(int n, int p, double u, const vector<double>& U) {
    // Implementation of FindSpan function
}

/* Function to compute the basis functions at the given parameter u */
void BasisFuns(int span, double u, int p, const vector<double>& U, vector<double>& N) {
    // Implementation of BasisFuns function
}

void CurvePoint(int n, int p, const vector<double>& U, const vector<double>& C)
{
    int span = FindSpan(n, p, u, U);
    vector<double> N(p + 1, 0.0);

    BasisFuns(span, u, p, U, N);

    C.assign(P.size(), 0.0);

    for (int i = 0; i <= p; i++)
    {
        for (int j = 0; j < P.size(); j++)
        {
            C[j] += N[i] * P[span - p + i];
        }
    }
}