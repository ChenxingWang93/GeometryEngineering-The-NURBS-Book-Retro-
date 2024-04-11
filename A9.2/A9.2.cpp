#include <iostream>
#include <vector>
using namespace std;

/* Function to compute the basis functions */
void BasisFuns(int span, double u, int p, vector<double>& U, vector<double>& N) {
    /* Implementation of BasisFuns function goes here */
}

void SolveTridiagonal(int n, vector<double>& Q, vector<double>& U, vector<double>& P) {
    vector<double> R(n + 1);
    vector<double> abc(3);
    vector<double> dd(n + 1);

    for (int i = 3; i < n; i++)
    {
        R[i] = Q[i - 1];
    }

    BasisFuns(4, U[4], 3, U, abc);
    double den = abc[1];
    P[2] = (Q[1] - abc[0] * P[1]) / den;

    for (int i = 3; i < n; i++)
    {
        dd[i] = abc[2] /den;
        BasisFuns(i + 2, U[i + 2], 3, U, abc);
        den = abc[1] - abc[0] * dd[i];
        P[i] = (R[i] - abc[0] * P[i - 1]) / den;
    }

    dd[n] = abc[2] / den;
    BasisFuns(n + 2, U[n + 2], 3, U, abc);
    den = abc[1] - abc[0] * dd[n];
    P[n] = (Q[n - 1] - abc[2] * P[n + 1] - abc[0] * P[n - 1]) / den;

    for (int i = n - 1; i >= 2; i--)
    {
        P[i] = P[i] - dd[i + 1] * P[i + 1];
    }
}

int main() {
    /* Input parameters */
    int n = 5;
    vector<double> Q = {1.0,2.0,3.0,4.0,5.0,6.0};
    vector<double> U ={0.0,1.0,2.0,3.0,4.0,5.0,6.0};
    /* P[0], P[1], P[n+1], P[n+2] are included */
    vector<double> P(n + 3, 0.0);

    /* Call the SolveTridiagonal function */
    SolveTridiagonal(n, Q, U, P);

    /* Output the results */
    /* Print or use the computed values of P as needed */

    return 0;
}