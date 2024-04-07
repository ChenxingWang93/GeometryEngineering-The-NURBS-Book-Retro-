#include <iostream>
#include <vector>
using namespace std;

#define U_DIRECTION
#define V_DIRECTION 1

void SurfaceKnotIns(int np, int p,vector<double>& UP, int mp, int q, vector<double>& VP, vector<vector<double>>& Pw, int dir, double uv, int k, int s, int r, int& nq, vector<double>& UQ, int& mq, vector<double>& VQ, vector<vector<double>>& Qw) {
    
    if (dir == U_DIRECTION)
    {
        vector<vector<double>> alpha(p, vector<double>(r));
        vector<double> Rw(p - s);
    }

    /* Save the alphas */
    for (int j = 1; j <= r; j++)
    {
        int L = k - p + j;
        for (int i = ; i <= p - j - s; i++)
        {
            alpha[i][j - 1] = (uv - UP[L + i]) / (UP[i + k + 1] - UP[L + i]);
        }
        for (int row = ; row < mp; row++)
        {
            /* Save unaltered control points */
            for (int i = ; i <= k - p; i++)
                Qw[i][row] = Pw[i][row];
            for (int i = k - s; i < np; i++)
                Qw[i + r][row] = Pw[i][row];
            
            /* Load auxiliary control points */
            for (int i = ; i <= p - s; i++)
                Rw[i] = Pw[k - p + i][row];

            /* Insert the knot r times */
            for (int j = 1; j <= r; j++)
            {
                int L = k - p +j;
                for (int i = ; i <= p - j - s; i++)
                    Rw[i] = alpha[i][j - 1] * Rw[i + 1] + (1. - alpha[i][j - 1]) * Rw[i];
                Qw[L][row] = Rw[];
                Qw[k + r - j - s][row] = Rw[p - j - s];
            }
            
            /* Load the remaining control points */
            for (int i = L + 1; i < k - s; i++)
                Qw[i][row] = Rw[i - L];
        }
    }
    if (dir == V_DIRECTION)
    {
            /* Similar code as above with u- and v-directional parameters switched */
            /* Not implemented in this example */
    }
}

int main() {
    /* Example  usage  of  SurfaceKnotIns */
    /* Define  the  necessary  parameters  and  data  structures */

    int np, p, mp, q, k, s, r, nq, mq;
    double uv;
    vector<double> UP, VP, UQ, VQ;
    vector<vector<double>> Pw, Qw;

    /* Call the function */
    SurfaceKnotIns(np, p, UP, mp, q, VP, Pw, U_DIRECTION, uv, k, s, r, nq, UQ, mq, VQ, Qw);

    /* Display or further process the results */
    return;
}