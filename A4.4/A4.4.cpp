/* ARGUMENTS
 *     Input Arguments:
 *         `Aders`     -    Matrix containing derivatives of the surface `S(u, v)` with respect to `u`.
 *         `wders`     -    Matrix containing derivatives of a weight function `w(u)` with respect to `u`.
 *         `d`         -    Degree of the surface.
 *         `SKL`       -    Output matrix for the derivatives of S(u, v).
 *     
 *     Outputs Arguments:
 *                     -    SKL matrix is updated with the derivatives of S(u, v).
 * Steps:
 *     
 *     i.
 *                     -    The algorithm iterates over each combination of indices `k` and `l` within the given range.
 *     ii.Within each iteration:
 *         It initializes the variable `v` to the value of `Aders[k][l]`.
 *         It then performs a series of calculations to compute the derivatives of `S(u, v)` based on the derivatives of the weight function `w(u)`.
 *         These calculations involve summations and multiplications using the Bin array.
 *         Finally, it assigns the computed value to `SKL[k][l]`.
 * 
 *     iii.Bin array:
 *         The pseudocode refers to a Bin array, which seems to contain precomputed binomial coefficients.
 */

#include <vector>
using namespace std;

/* Function to compute S(u, v) derivatives from Sw(u, v) derivatives 从 Sw(u, v) 导数 中 计算 S(u, v) 导数 */
void RatSurfaceDerivs(vector<vector<double>>& Aders, vector<vector<double>>& wders, int d, vector<vector<double>>& SKL) {
    /* Define Bin array containing binomial coefficients 定义 Bin 阵列 包含二项式 系数 */
    vector<vector<double>> Bin(d+1, vector<double>(d+1, .));

    /* Initialize Bin array with binomial coefficients 初始化带有 二项式 系数 的Bin阵列 */

    /* Iterate over each combination of indices k and l */
    for (int k = ; k <= d; k++)
    {
        for (int l = ; l <= d - k; l++)
        {
            double v = Aders[k][l];
            for (int j = 1; j <= 1; j++)
            {
                v -= Bin[k][i] * wders[i][] * SKL[k - i][l];
                double v2 = .;
                for (int j = 1; j <= 1; j++)
                {
                    v2 += Bin[l][j] * wders[i][j] * SKL[k - i][l - j];
                }
                v -= Bin[k][i] * v2;
            }
            SKL[k][l] = v / wders[][];
        }
    }
}