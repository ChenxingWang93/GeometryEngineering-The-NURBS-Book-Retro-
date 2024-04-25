/* ARGUMENTS
 *     Input Arguments:
 *         `np`        -    number of control points in the original curve.
 *         `p`         -    degree of the original curve.
 *         `UP`        -    knot vector of the original curve.
 *         `Pw`        -    control points of the original curve.
 *         `u`         -    knot to be inserted.
 *         `k`         -    index of the knot span where `u` lies.
 *         `s`         -    multiplicity of the knot `u` in the original knot vector.
 *         `r`         -    number of times `u` is to be inserted.
 *     
 *     Outputs Arguments:
 *         `nq`        -    number of control points in the new curve.
 *         `UQ`        -    knot vector of the new curve.
 *         `Qw`        -    control points of the new curve.
 * 
 * Steps:
 *     i.initialize Variables:
 *         `mp`        -    total number of control points including the original ones and those to be inserted.
 *         `np`        -    set as the number of control points in the new curve after knot insertion.
 *     
 *     ii.Load New Knot Vector:
 *         Copy the first `k-p` control points from the original curve to the new curve.
 *         Copy the remaining control points from the original curve to the new curve, shifted by `r`.
 *         Extract the control points that are affected by the knot insertion into a temporary array `Rw`.
 *                  
 *     iii.Insert Knot `u` into the Curve:
 *         Iterate `r` times to insert the knot `u`.
 *         For each iteration, calculate blending factors `alpha` and interpolate the control points in the temporary array `Rw`
 *         Update the control points in the new curve at appropriate positions based on `L` and `k`.
 * 
 *     iv.Load Remaining Control Points:
 *         Copy the remaining control points from the temporary array `Rw` to the new curve.
 */

#include <vector>
using namespace std;

void CurveKnotIns(int np, int p, vector<double>& UP, vector<double>& Pw, double u, int k, int s, int r, int& nq, vector<double>& UQ, vector<double>& Qw) {
    int mp = np + p + 1;
    nq = np + r;

    /* Temporary array for control points 控制點的臨時 陣列 */
    vector<double> Rw(p + 1);

    /* Load new knot vector 加載新 的結點向量 */
    for (int i = 0; i <= k - p; i++)
    {
        Qw[i] = Pw[i];
    }
    for (int i = k - s; i <= np; i++)
    {
        Qw[i + r] = Pw[i];
    }

    vector<double> Rw(p - s + 1);
    for (int i = 0; i <= p - s; i++)
    {
        Rw[i] = Pw[k - p + i];
    }

    for (int j = 1; j <= r; j++)
    {
        /* Insert the knot r times 插入結點 r 次 */
        int L = k - p + j;
        for (int i = 0; i <= p - j - s; i++)
        {
            double alpha = (u - UP[L + i]) / (UP[i + k + 1] - UP[L + i]);
            Rw[i] = alpha * Rw[i + 1] + (1. - alpha) * Rw[i];
        }
        Qw[L] = Rw[0];
        Qw[k + r - j - s] = Rw[p - j - s];
    }
    
    int L = k - p + r;
    for (int i = L + 1; i < k - s; i++)
    {
        /* Load remaining control points 加載剩餘的 控制點 */
        Qw[i] = Rw[i - L];
    }
}