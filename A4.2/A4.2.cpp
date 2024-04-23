#include <iostream>
#include <vector>
using namespace std;

void RatCurveDerivs(vector<double> Aders, vector<double> wders, int d, vector<double>& CK) {
    vector<vector<double>> Bin(d+1, vector<double>(d+1, 1.0));

        /* Initialize binomial coefficients 初始化二项式系数 */

        for (int k = 0; k <= d; k++)
        {
            double v = Aders[k];
            for (int i = 1; i <= k; i++)
            {
                v -= Bin[k][i] * wders[i] * CK[k-i];
            }
            CK[k] = v / wders[0];   
        }
}

int main() {

    /* Example derivatives of control points 控制点的导数 */
    vector<double> Aders = {1, 2, 3};

    /* Example derivatives of weights 权重的导数 */
    vector<double> wders = {2, 3};

    /* Example degree of the curve 弧形的度 */
    int d = 2;

    /* Initialize list to store derivatives of C(u) */
    vector<double> CK(d+1, 0.0);

    RatCurveDerivs(Aders, wders, d, CK);
    cout << "Derivatives of C(u): ";
    for (int i = 0; i <= d; i++)
    {
        cout << CK[i] << " ";
    }
    cout << std::endl;
    return 0;
}