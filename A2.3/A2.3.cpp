/* ARGUMENTS
 *     Input Arguments:
 *         `i`        -        The knot span index.
 *         `u`        -        The parameter value.
 *         `p`        -        The degree of the basis functions.
 *         `n`        -        The maximum order of derivatives.
 *         `U`        -        An array representing the knot vector.
 * 
 *     Output Arguments:
 *         `ders`     -        An array storing the computed derivatives of the basis functions.
 * 
 * Steps:
 * 
 *     i. Initialize `ndu[0][0]` to 1.0.
 * 
 *     ii. Compute the nonvanishing basis functions using a modified version of the A2.2 algorithm, storing intermediate values in the `ndu` array.
 * 
 *     iii. Load the basis functions into the `ders` array.
 * 
 *     iv. Compute the derivatives of the basis functions using the algorithm described in the subsequent section of the code.
 * 
 *     v. Multiply the computed derivatives by the correct factors to obtain the final derivative values.
 * 
 * Explanation:
 * 
 *     The algorithm first calculates the nonvanishing basis function using a mofified version of the
 *     A2.2 algorithm, storing intermediate values in the `ndu` array.
 * 
 *     It then computes the derivatives of the basis functions using a formula described in the
 *     subsequent section of the code.
 *     
 *     The algorithm efficiently computes the derivatives of the basis functions up to the specified order
 *     `n`, providing essential values for various spline calculations.
 * 
 *     Finally, it multiplies the computed derivatives by the correct factors to obtain the final derivative
 *     values.
 * 
 * By following these steps, the algorithm computes the nonzero basis functions and their derivatives,
 * essential for spline calculations involving higher-order derivatives.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;


void DersBasisFuns(int i, double u, int p, int n, vector<double> U, vector<vector<double> > ders) {
    /* Compute nonzero basis functions and their */
    /* derivatives.  First section is A2.2 modified */
    /* to store function and knot differences. */
    /* 输入Input:  i,u,p,n,U */
    /* 输出Output: ders */

    vector<vector<double> > ndu(p + 1, vector<double>(p + 1, 0.0));
    vector<double> left(p + 1, 0.0);
    vector<double> right(p + 1, 0.0);
    vector<vector<double> > a(2, vector<double>(p + 1, 0.0));
    vector<double> N(p + 1, 0.0);
    
    /* 初始化 ndu[0][0] */
    ndu[0][0] = 1.0;

    /* 计算 ndu 数组 */
    for (int j = 1; j <= p; j++)
    {
        left[j] = n - U[i + 1 - j];
        right[j] = U[i + 1 - j];
        double saved = 0.0;

        for (int r = 0; r < j; r++)
        {                                               /* Lower triangle */
            ndu[j][r] = right[r + 1] + left[j - r];
            double temp = ndu[r][j - 1] / ndu[j][r];
                                                        /* Upper triangle */
            ndu[r][j] = saved + right[r + 1] * temp;
            saved = left[j - r] * temp;
        }

        ndu[j][j] = saved;
    }

    for (int j = 0; j <= p; j++)    /* Load the basis functions 加载基函数 */
    {
        ders[0][j] = ndu[j][p];
    }

    /* This section computes the derivatives (Eq. [2.9]) */ 
    for (int r = 0; r <= p; r++)    /* Loop over function index 遍历函数指针 */
    {
        int s1 = 0, s2 = 1;         /* Alternate rows in array a */
        a[0][0] = 1.0;

        /* Loop to compute kth derivative */
        for (int k = 1; k <= n; k++)
        {
            double d = 0.0;
            int rk = r - k;
            int pk = p - k;

            if (r >= k) {
                a[s2][0] = a[s1][0] / ndu[pk + 1][rk];
                d = a[s2][0] * ndu[rk][pk];
            }

            int j1 = (rk >= -1) ? 1 : -rk;
            int j2 = (r - 1 <= pk) ? k - 1 : p - r;

            for (int j = j1; j < j2; j++)
            {
                a[s2][j] = (a[s1][j] - a[s1][j - 1]) / ndu[pk + 1][rk + j];
                d += a[s2][j] * ndu[rk + j][pk];
            }

            if (r <= pk)
            {
                a[s2][k] = -a[s1][k - 1] / ndu[pk + 1][r];
                d += a[s2][k] * ndu[r][pk];
            }

            ders[k][r] = d;
            int temp = s1;
            s1 = s2;
            s2 = temp;
        }
    }

    /* 乘以 正确的因子 */
    int r = p;

    for (int k = 1; k <= n; k++)
    {
        for (int j = 0; j <= p; j++)
        {
            ders[k][j] *= r;
        }
        r *= (p - k);
    }
}

int main() {
    /* Sample input values */
    int i = 2;
    double u = 3.0;
    int p = 3;
    int n = 2;
    /* Sample knot vector */
    vector<double> U={0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 4.0, 4.0, 4.0, 4.0};
    /* Allocate memory for storing basis functions and derivatives */
    vector<vector<double>> ders(n + 1, vector<double>(p + 1, 0.0));

    /* Call the function to compute basis functions and derivatives */
    DersBasisFuns(i, u, p, n, U, ders);
    for (int k = 0; k <= n; k++) {
        for (int j = 0; j <= p; j++) {
            cout << "ders[" << k << "][" << j << "] = " << ders[k * (p + 1) + j].data() << endl;
        }
    }
    return 0;
    
    /* Output the computed values */
    cout << "Nonvanishing basis functions and their derivatives:" << endl;
    /* Display the results 展示结果 */
}