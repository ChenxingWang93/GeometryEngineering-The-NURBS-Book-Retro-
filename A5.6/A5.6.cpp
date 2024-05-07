/* ARGUMENTS
 *     Input Arguments:
 *         `n`        -    Number of control points minus one.
 *         `p`        -    Degree of the B-spline curve.
 *         `U`        -    Knot vector of the B-spline curve.
 *         `Pw`       -    Control points of the B-spline curve.
 *     
 *     Outputs Arguments:
 *         `nb`       -    Number of Bezier segments generated.
 *         `Qw`       -    Control points of the Bezier segments.
 * 
 * Steps:
 *     i.Initialization:
 *         Set `m = n + p + 1`, `a = p`, and `b = p + 1`.
 *         Initialize `nb = 0`.
 *         Store the first `p + 1` control points of the B-spline curve into `Qw[0]`.
 *     ii.Decomposition:
 *         While `b < m`, repeat the following steps:
 *          - Increment `i` until a new knot value is encountered.
 *          - Determine the multiplicity `mult` of the knot value `U[b]`.
 *          - If `mult < p`,meaning the knot is not repeated enough timestimes for the degree of the curve:
 *               - Compute `numer` as the numerator of the alpha value.
 *               - Compute and store the alpha values.
 *               - Insert the knot `U[b]` `r = p - mult` times:
 *                   - For each insertion:
 *                       - Compute the alpha value.
 *                       - Update control points using the de Casteljau algorithm.
 *                       - If there are more knots, store the control point for the next segment.
 *          - Increment `nb` to indicate completion of a Bezier segment.
 *          - If there are more knots:
 *               - Initialize control points for the next segment.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

void DecomposeCurve(int n, int p, vector<double> U, vector<vector<double>>& Pw, int& nb, vector<vector<double>>& Qw) {
    int m = n + p + 1;
    int a = p;
    int b = p + 1;
    nb = 0;

    vector<double> alphas(p + 1);

    for (int i = 0; i <= p; i++)
    {
        /* Assuming Pw is a 2D vector containing control points as [x, y, z, ...] 假设 Pw 是一个 2D 向量 包含控制点 [x, y, z, ...] */
        Qw[nb][i] = Pw[i][0];
    }

    while (b < m)
    {
        int i = b;
        while (b < m && U[b + 1] == U[b])
            b++;
        int mult = b - i + 1;

        if (mult < p) {
            double numer = U[b] - U[a];  /* Numerator of alpha */
            /* Compute & store alphas */
            for (int j = p; j < mult; j--)
                alphas[j - mult - 1] = numer / (U[a + j] - U[a]);

            int r = p - mult;  /* This many new points */
            for (int j = 1; j <= r; j++)
            {
                int save  = r - j;
                int s = mult + j;
                for (int k = p; k >= s; k--)
                {
                    double alpha = alphas[k - s];
                    Qw[nb][k] = alpha * Qw[nb][k] + (1.0 - alpha) * Qw[nb][k - 1];
                }
                if (b < m)  /* Control point of next segment */
                    Qw[nb + 1][save] = Qw[nb][p];
            }
        }

        nb++;
        if (b < m)
        {
            for (int i = p - mult; i <= p; i++)
            {
                Qw[nb][i] = Pw[b - p + i][0];
            }
            a = b;
            b = b + 1;
        }
    }
}

int main() {
    /* Example usage */
    /* Number of control points minus one */
    int n = 5;
    /* Degree of the B-spline curve */
    int p = 2;

    /* Example knot vector 結點向量 */
    vector<double> U = {0, 0, 0, 1, 2, 2, 2};

    /* Example control points 控制點 */
    vector<vector<double>> Pw = {{1, 2},
                                 {3, 4}, 
                                 {5, 6}, 
                                 {7, 8}, 
                                 {9, 10}, 
                                 {11, 12}
    };
    
    int n = Pw.size() - 1;
    int p = U.size() - n - 2;
    int nb;
    /* Output Bezier control points 控制點 */
    vector<vector<double>> Qw(n + 1, vector<double>(p + 1));

    /* Call the DecomposeCurve function */
    DecomposeCurve(n, p, U, Pw, nb, Qw);

    /* Display the resulting Bezier segments 展示 Bezier 片段的結果 */
    cout << "Number of Bezier segments: " << nb << endl;
    cout << "Bezier control points: " << endl;
    for (int i = 0; i < nb; i++)
    {
        cout << "Segment " << i + 1 << ": ";
        for (int j = 0; j <= p; j++)
        {
            cout << "(" << Qw[i][j] << ") ";
        }
        cout << endl;
    }

    return 0;
}