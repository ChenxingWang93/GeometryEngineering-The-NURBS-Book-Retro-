#include <iostream>
#include <vector>
using namespace std;

void UnclampCurve(int n, int p, vector<double>& U, vector<Point>& Pw) {
    for (int i = 0; i <= p - 2; i++)
    {
        /* Uclamp at left end */
        U[p - i - 1] = U[p - i] - (U[n - i + 1] - U[n - i]);
        int k = p - 1;
        for (int j = i; j >= 0; j--)
        {
            double alfa = (U[p] - U[k]) / (U[p + j + 1] - U[k]);
            Pw[j] = (Pw[j] - alfa * Pw[j + 1]) / (1.0 - alfa);
            k--;
        }
    }

    /* Set first knot */
    U[0] = U[1] - (U[n - p + 2] - U[n - p + 1]);

    for (int i = 0; i <= p - 2; i++)
    {
        /* Unclamp at right end */
        U[n + i + 2] = U[n + i + 1] + (U[p + i + 1] - U[p + i]);
        for (int j = i; j >= 0; j--)
        {
            double alfa = (U[n + 1] - U[n - j]) / (U[n - j + i + 2] - U[n - j]);
            Pw[n - j] = (Pw[n - j] - (1.0 - alfa) * Pw[n - j - 1]) / alfa;
        }
    }

    /* Set last knot */
    U[n + p + 1] = U[n + p] + (U[2 * p] - U[2 * p - 1]);
}
