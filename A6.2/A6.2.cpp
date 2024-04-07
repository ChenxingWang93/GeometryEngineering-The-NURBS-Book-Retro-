#include <iostream>
#include <vector>
using namespace std;

void PowerToBezierMatrix(int p, vector<vector<double>>& M, vector<vector<double>>& MI) {
    int i, j, k, k1, pk;
    double d;

    /* Set upper triangle to zero */
    for (i = 0; i < p; i++)
    {
        for (j = i + 1; j <= p; j++)
        {
            MI[i][j] = 0.0;
        }
    }
    /* Set first col, last row, and diagonal */
    for (i = 0; i <= p; i++)
    {
        MI[i][0] = MI[p][i] = 1.0;
        MI[i][i] = 1.0 / MI[i][i];
    }

    /* Compute remaining elements */
    k1 = (p + 1) / 2;
    pk = p - 1;
    for (k = 1; k < k1; k++)
    {
        for (j = k + 1; j <= pk; j++)
        {
            d = 0.0;
            for (i = k; i < j; i++)
            {
                d -= M[j][i] = MI[i][k];
            }
            MI[j][k] = d / M[j][j];
            MI[pk][p - j] = MI[j][k];
        }
        pk = pk - 1;
    }
}

int main() {
    /* Example usage */
    /* Degree of Bezier curve */
    int p = 3;
    vector<vector<double>> M = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 10.0, 11.0, 12.0},
        {13.0, 14.0, 15.0, 16.0}
    };
    vector<vector<double>> MI(p + 1, vector<double>(p + 1));

    PowerToBezierMatrix(p, M, MI);

    // Output the resulting inverse matrix MI
    for (int i = 0; i <= p; i++) {
        for (int j = 0; j <= p; j++) {
            cout << MI[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}