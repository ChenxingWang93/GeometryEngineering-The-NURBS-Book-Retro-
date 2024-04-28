/* ARGUMENTS
 *     Input Arguments:
 *         `i`        -    The index of the Bernstein polynomial term.
 *         `n`        -    The degree of the Bernstein polynomial.
 *         `u`        -    The parameter at which the Bernstein polynomial is to be evaluated.
 * 
 *     Outputs Arguments:
 *         `B`        -    The value of the Bernstein polynomial at the given parameter u`.
 * 
 * Steps:
 *     i. Initialize an array `temp` of size `n+1` to store intermediate values of the Bernstein polynomail.
 * 
 *     ii. Initialize all elements of the `temp` array to 0.0.
 * 
 *     iii. Set `temp[n-i]` to 1.0. This step initializes the array to represent the Bernstein polynomial term corresponding to index `i`.
 * 
 *     iv. Calculate `u1 = 1.0 - u`. This will be used in the subsequent calculations.
 * 
 *     v. Iterate over `k` from 1 to `n`:
 *           - For each `k`,iterate over `j` from `n` down to `k`:
 *               - Update `temp[j]` using the formula: `temp[j] = u1 * temp[j] + u * temp[j-1]`.
 *               - This process updates the values in the `temp` array based on the parameter `u`.
 * 
 *     vi. After the loops, the value of the Bernstein polynomial at parameter `u` is stored in `B = temp[n]`.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

void Bernstein(int i, int n, double u, double& B) {
    /* Temporary array to store values 存儲值的臨時陣列 */
    vector<double> temp(n + 1, 0.0);

    /* Initialize the temporary array 初始化臨時陣列 */
    temp[n + i] = 1.0;

    for (int j = 0; j <= n; j++) {
        temp[j] = 0.0;
    }

    temp[n - i] = 1.0;
    double u1 = 1.0 - u;

    /* Compute the values of the Bernstein polynomial 計算多項式係數值 */
    for (int k = 1; k <= n; k++) {
        for (int j = n; j >= k; j--) {
            temp[j] = u1 * temp[j] + u * temp[j - 1];
        }
    }
    
    /* Set the output value B to the computed value at u 將u處計算所得輸出到值B */
    B = temp[n];
}

int main() {
    int i = 2;    /* Example value of i */
    int n = 5;    /* Example value of n */
    double u = 0.3;    /* Example value of u */
    double B;    /* Output value of the Bernstein polynomial */

    /* Call the Bernstein function */
    Bernstein(i, n, u, B);

    /* Output the result */
    cout << "The value of the Bernstein polynomial at u = " << u << " is: " << B << endl;

    return 0;
}