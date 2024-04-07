#include <iostream>
#include <vector>

using namespace std;

void DecomposeCurve(int n, int p, vector<double> U, vector<vector<double>> & Pw, int& nb, vector<vector<double>>& Qw) {
    int m = n + p + 1;
    int a = p;
    int b = p + 1;
    nb = 0;
    for (int i = 0; i <= p; i++)
    {
        /* Assuming Pw is a 2D vector containing control points as [x, y, z, ...] */
        Qw[nb][i] = Pw[i][0];
    }
}

int main() {
    /* Example usage */
    int n = 3;
    int p = 2;

    /* Example knot vector */
    vector<double> U = {0, 0, 0, 1, 1, 1};

    /* Example control points */
    vector<vector<double>> Pw = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int nb;

    /* Assuming maximum 10 Bezier segments with 10 control points each */
    vector<vector<double>> Qw(10, vector<double>(10));

    DecomposeCurve(n, p, U, Pw, nb, Qw);

    /* Display the resulting Bezier segments */

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