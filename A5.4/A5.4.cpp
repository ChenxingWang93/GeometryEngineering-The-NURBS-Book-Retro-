#include <vector>
#include <algorithm>
#include "../findSpan.h"
using namespace std;


void RefineKnotVectCurve(int n, int p, vector<double>& U, vector<double>& Pw, vector<double>& X, int r, vector<double>& Ubar, vector<double>& Qw) {
    int m = n + p + 1;
    int a = FindSpan(n, p, X[0], U);
    int b = FindSpan(n, p, X[r], U);
    b = b + 1;

    /* Copy control points */
    for (int j = 0; j <= a - p; j++)
        Qw[j] = Pw[j];
    for (int j = b - 1; j <= n; j++)
        Qw[j + r + 1] = Pw[j];

    /* Copy knot vector */
    copy(U.begin(), U.begin() + a + 1, Ubar.begin());
    copy(U.begin() + b + p, U.begin() + m + 1, Ubar.begin() + b + p + r + 1);

    int i = b + p - 1;
    int k = b + p + r;

    for (int j = r; j >= 0; j--)
    {
        /* Your logic for refining knot vector and control points goes here */
    }   
}