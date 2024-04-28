/* ARGUMENTS
 *     Input Arguments:
 *         `np`        -    Number of control points in the U-direction.
 *         `p`         -    Degree in the U-direction.
 *         `UP`        -    Knot vector in the U-direction.
 *         `mp`        -    Number of control points in the V-direction.
 *         `q`         -    Degree in the V-direction.
 *         `VP`        -    Knot vector in the V-direction.
 *         `Pw`        -    Control points of the surface.
 *         `dir`       -    Direction indicator (`U_DIRECTION`or`V_DIRECTION`)
 *         `uv`        -    Knot to be inserted.
 *         `k`         -    Index of the knot to insert before.
 *         `s`         -    Multiplicity of the knot to insert before.
 *         `r`         -    Number of times to insert the knot.
 * 
 *     Outputs Arguments:
 *         `nq`        -    Number of control points in the U-direction after knot insertion.
 *         `UQ`        -    Updated knot vector in the U-direction.
 *         `mq`        -    Number of control points in the V-direction after knot insertion.
 *         `VQ`        -    Updated knot vector in the V-direction.
 *         `Qw`        -    Control points of the surface after knot insertion.
 * 
 * Steps:
 *     i.If the direction is in the U-direction:
 *         Load the u-vector as in Algorithm A5.1.
 *         Copy the v-vector into `VQ`.
 *         Save the alphas for knot insertion.
 *         For each row:
 *           Save unaltered control points.
 *           Load auxiliary control points.
 *           Insert the knot `r` times.
 *           Load the remaining control points
 *     ii.If the direction is in the V-direction:
 *         Similar steps as above with u- and v-directional parameters switched.
 */

#include <iostream>
#include <vector>
using namespace std;

#define U_DIRECTION 0
#define V_DIRECTION 1

void SurfaceKnotIns(int np, int p, vector<double> UP, int mp, int q, vector<double> VP, vector<vector<double>>& Pw, int dir, double uv, int k, int s, int r, int& nq, vector<double>& UQ, int& mq, vector<double>& VQ, vector<vector<double>>& Qw) {
    int L,i;
    if (dir == U_DIRECTION)
    {
        nq = np + r;
        mq = mp;

        /* Load u-vector as in Algorithm A5.1 */
        vector<double> Rw(p - s + 1);
        vector<vector<double>> alpha(p - s + 1, vector<double>(r + 1));

        for (int j = 1; j <= r; j++)
        {
            int L = k - p + j;
            for (int i = 0; i <= p - j - s; i++)
            {
                alpha[i][j] = (uv - UP[L + i]) / (UP[i + k + 1] - UP[L + i]);
            }
        }

        for (int row = 0; row <= mp; row++)
        {
            
            /* Save unaltered control points */
            for (int i = 0; i <= k - p; i++)
            {
                Qw[i][row] = Pw[i][row];
            }
            for (int i = k - s; i < np; i++)
            {
                Qw[i + r][row] = Pw[i][row];
            }
            
            /* Load auxiliary control points */
            for (int i = 0; i <= p - s; i++)
            {
                Rw[i] = Pw[k - p + i][row];
            }

            /* Insert the knot r times */
            for (int j = 1; j <= r; j++)
            {
                int L = k - p + j;
                for (int i = 0; i <= p - j - s; i++)
                {
                    Rw[i] = alpha[i][j] * Rw[i + 1] + (1.0 - alpha[i][j]) * Rw[i];
                }
                Qw[L][row] = Rw[0];
                Qw[k + r - j - s][row] = Rw[p - j - s];
            }

            /* Load the remaining control points */
            for (int i = L + 1; i < k - s; i++)
            {
                Qw[i][row] = Rw[i - L];
            }
        }
    }

    if (dir == V_DIRECTION)
    {
        nq = np;
        mq = mp + r;
        
        /* Copy u-vector into UQ */
        UQ = UP;

        /* Load v-vector as in Algorithm A5.1 */
        vector<double> Rw(q - s + 1);
        vector<vector<double>> beta(q - s + 1, vector<double>(r + 1));

        for (int j = 1; i <= r; j++)
        {
            int L = k - q + j;
            for (int i = 0; i < q - j - s; i++)
            {
                beta[i][j] = (uv - VP[L + i]) / (VP[i + k + 1] - VP[L + i]);
            }
        }
        
        for (int col = 0; col <= np; col++) {
            /* Save unaltered control points */ 
            for (int i = 0; i <= k - q; i++) {
                Qw[col][i] = Pw[col][i];
            }
            for (int i = k - s; i <= mp; i++) {
                Qw[col][i + r] = Pw[col][i];
            }

            /* Load auxiliary control points */ 
            for (int i = 0; i <= q - s; i++) {
                Rw[i] = Pw[col][k - q + i];
            }

            for (int j = 1; j <= r; j++) {
                int L = k - q + j;
                for (int i = 0; i <= q - j - s; i++) {
                    Rw[i] = beta[i][j] * Rw[i + 1] + (1.0 - beta[i][j]) * Rw[i];
                }
                Qw[col][L] = Rw[0];
                Qw[col][k + r - j - s] = Rw[q - j - s];
            }

            /* Load the remaining control points */
            for (int i = L + 1; i < k - s; i++) {
                Qw[col][i] = Rw[i - L];
            }
        }

        /* Copy v-vector into VQ */
        VQ = VP;
    }
}

int main() {
    /* Example usage of SurfaceKnotIns */
    int np = 5; /* Number of control points in U-direction */
    int p = 2;  /* Degree in U-direction */
    vector<double> UP = {0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 3.0, 3.0};   /* Knot vector in U-direction */
    int mp = 5; /* Number of control points in V-direction */
    int q = 2;  /* Degree in V-direction */
    vector<double> VP = {0.0, 0.0, 1.0, 2.0, 3.0, 3.0};    /* Knot vector in V-direction */
    vector<vector<double>> Pw = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}, {10.0, 11.0, 12.0}, {13.0, 14.0, 15.0}, {16.0, 17.0, 18.0}};    /* Control points */
    int dir = U_DIRECTION;  /* Direction (U_DIRECTION or V_DIRECTION) */
    double uv = 2.5;
    int k = 3;
    int s = 2;
    int r = 1;
    
    int nq;
    vector<double> UQ;
    int mq;
    vector<double> VQ;
    vector<vector<double>> Qw(np + r, vector<double>(mp));

    SurfaceKnotIns(np, p, UP, mp, q, VP, Pw, dir, uv, k, s, r, nq, UQ, mq, VQ, Qw);

    /* Display or further process the results */
    return 0;
}