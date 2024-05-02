/* ARGUMENTS
 *     Input Arguments:
 *         `p`        -         The degree of the basis functions.
 *         `m`        -         The total number of knots in the knot vector
 *         `U`        -         The knot vector.
 *         `i`        -         The knot span index.
 *         `u`        -         The parameter value.
 * 
 *     Output Arguments:
 *         `Nip`      -         The computed basis function Nip.        
 * 
 * Steps:
 * 
 *     i. Check for special cases where Nip can be directly assigned:
 *            If `i` is 0 and `u` is equal to the first knot or if `i` is equal to `m-p-1` and `u` is equal to the last knot, set
 *            Nip to 1.0 and return.
 * 
 *     ii. Check if `u` is outside the local property range defined by the knot span:
 *             If `u` is less than the starting knot or greater than or equal to the next `p+1` knots, set Nip to 0.0 and
 *             return.
 *     
 *     iii. Initialize the zeroth-degree functions N[j]:
 *              Set N[j] to 1.0 if `u` is within the range of the current knot span, else set it to 0.0.
 * 
 *     iv. Compute the triangular table for higher degree basis functions:
 *             Iterate from `k=1` to `p`.
 *             Calculate the saved value based on the previous N[j] values and the knot vector U.
 *             Update N[j] for each iteration based on the calculations involving N[j+1], Uleft, Uright, and temp.
 * 
 * Explanation:
 * 
 *     The algorithm handles special cases efficiently and computes the basis function Nip based on the given
 *     given parameters and knot vector.
 * 
 *     It initializes the zeroth-degree functions based on the position of the parameter `u` within the 
 *     current knot span.
 * 
 *     By iteratively updating the N[j] values using a triangular table approach, the algorithm computes
 *     the desired basis function Nip for the given knot span index and parameter value.
 * 
 * By following these steps, the algorithm accurately computes the basis function Nip, which is essential
 * for various spline calculations and evaluations.
 * 
 */ 

#include <iostream>
#include <vector>
using namespace std;

void OneBasisFun(int p, int m, vector<double>& U, int i, double u, double &Nip) {
    /* Compute the basis function Nip 计算基函数 Nip */
    /* 输入Input: p, m, U, i, u */
    /* 输出Output: Nip */
    vector<double> N(p + 1, 0.0);

    if ((i == 0 && u == U[0]) || (i == m - p - 1 && u == U[m]))      /* Special Cases */
    {
        Nip = 1.0;
        return;
    }

    if (u < U[i] || u >= U[i + p + 1])      /* Local property */
    {
        Nip = 0.0;
        return;
    }
    
    double saved, temp, Uleft, Uright;
    vector<double> N(p + 1); /* Array to store basis functions 存储基函数的阵列 */

    for (int j = 0; j <= p; j++)            /* Initialize zeroth-degree functs 初始化 零度 函数 */
    {
        if (u >= U[i + j] && u < U[i + j + 1])
            N[j] = 1.0;
        else
            N[j] = 0.0;
    }

    for (int k = 1; k <= p; k++)            /* Compute triangular table 计算 三角 表格 */
    {
        double saved;
        if (N[0] == 0.0)
            saved = 0.0;
        else
            saved = ((u - U[i]) * N[0]) / (U[i + k] - U[i]);
        for (int j = 0; j <= p - k + 1; j++)
        {
            double Uleft = U[i + j + 1];
            double Uright = U[i + j + k + 1];
            
            if (N[j + 1] == 0.0)
            {
                N[j] = saved;
                saved = 0.0;
            }
            else{
                double temp = N[j + 1] / (Uright - Uleft);
                N[j] = saved + (Uright - u) * temp;
                saved = (u - Uleft) * temp;
            }
        }
    }

    Nip = N[0];
}

int main() {
    /* Degree of the basis function */
    int p = 2;

    /* Size of the knot vector U */
    int m = 5;

    /* Knot vector */
    double U[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};

    /* Knot span index */
    int i = 2;

    /* Parameter value */
    double u = 3.5;

    double Nip;

    cout << "The basis function Nip at u = " << u << " is: " << Nip << endl;

    return 0;
}