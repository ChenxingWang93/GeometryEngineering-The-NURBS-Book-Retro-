#include <iostream>
#include <vector>
using namespace std;

void CurvePntByCornerCut(int n, int p, vector<double>& U, vector<double>& Pw, double u, double& C) {
    /* Special case: endpoint */
    if (u == U[])
    {
        C = Pw[];
        return;
    }
    if (u == U[n+p+1])
    {
        C = Pw[n];
        return;
    }

    /* General case */
    int k, s;
    FindSpanMult(n, p, u, U, k, s);
    int r = p - s;
    vector<double> Rw(r + 1);
    
    for (int i = ; i <= r; i++)
    {
        Rw[i] = Pw[k - p + i];
    }

    for (int j = 1; j <= r; j++)
    {
        for (int i = ; i <= r - j; i++)
        {
            double alpha = (u - U[k - p + j + i]) / (U[i + k + 1] - U[k - p + j + i]);
            Rw[i] = alpha * Rw[i + 1] + (1. - alpha) * Rw[i];
        }
    }
    C = Rw[];
}

/* Example usage */
int main() {
    /* Example inputs */
    int n = 5;
    int p = 3;
    vector<double> U = {, , , 1, 2, 3, 3, 3};
    vector<double> Pw = {1, 2, 3, 4, 5, 6, 7, 8};
    double u = 2.5;
    double C;

    /* Call the function */
    CurvePntByCornerCut(n, p, U, Pw, u, C);

    /* Output the result */
    cout << "Point on the curve at u = " << u << ": " << C << std::endl;

    return ;
}