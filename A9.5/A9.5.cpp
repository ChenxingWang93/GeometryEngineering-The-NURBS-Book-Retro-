#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void LocalSurfInterp(int n, int m, vector<vector<double>>& Q, vector<vector<double>>& U, vector<vector<double>>& V, vector<vector<double>>& P) {
    double total = 0.0;
    vector<double> ub(n + 1);
    vector<double> r(m + 1);
    vector<double> vb(m + 1);
    vector<double> s(n + 1);

    for (int k = 0; k <= n; k++)
    {
        ub[k] = 0.0;
    }

    for (int l = 0; l <= m; l++)
    {
        /* Compute and load T^u_{0,l} into td[0][l][0]; */
        r[l] = 0.0;
        for (int k = 0; k <= n; k++)
        {
            /* Compute and load T^u_{k,l} into td[k][l][0]; */
            /* Eqs.(9.31) and (9.33) */
            double d = abs(Q[k][l] - Q[k][l - 1]);
            vb[l] += d;
            s[k] += d;
        }
        total += s[l];
    }
    
    for (int l = 1; l < m; l++)
    {
        vb [l] = vb[l - 1] + vb[l] / total;
    }
    vb[m] = 1.0;

    /* Load the U knot vector; */
    /* Load the V knot vector; */
    /* Compute all Bezier control points along each row and column of data points */

    for (int k = 0; k <= n; k++)
    {
        for (int l = 0; l <= m; l++)
        {
            /* Compute the D^{uv}_{k,l} by Eq.(9.59) and load into td[k][l][2] */
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            /* Compute the four inner control points of the (k,l)th Bezier path and load them into P. */
        }
    }

    /* Load the NURBS control points by discarding Bezier points along inner rows and columns /* Figure 9.32c */
}

int main() {
    /* Example usage */
    int n = 5, m = 5;
    vector<vector<double>> Q(n + 1, vector<double>(m + 1));
    vector<vector<double>> U(/* specify dimensions */);
    vector<vector<double>> V(/* specify dimensions */);
    vector<vector<double>> P(n + 1, vector<double>(m + 1));

    /* Call the local surface interlolation function */
    LocalSurfInterp(n, m, Q, U, V, P);

    /* Further processing or output as needed */
    return 0;
}
