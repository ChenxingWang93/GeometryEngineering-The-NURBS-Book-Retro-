#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* Define tolerance 定义容差 */
const double TOL = 0.0001;

/* Function to compute distance in 4D space 计算 4D 空间中距离 的函数 */
double Distance4D(vector<double> p1, vector<double> p2) {
    /* Implement distance calculation for 4D space 实施 4D 空间中的 距离计算 */
    /* (Assuming implementation of Distance4D function) 假设 Distance4D 函数的 实施 */

    /* Placeholder, replace with actual calculation 占位符 */
    double distance = 0;
    for (int i = 0; i < 4; i++)
    {
        distance += pow(p2[i] - p1[i], 2);
    }
    return sqrt(distance);
}

void RemoveCurveKnot(int n, int p, vector<double>& U, vector<vector<double>>& Pw, double u, int r, int s, int num, int &t) {
    int m = n + p + 1;
    int ord = p + 1;
    int fout = (2 * r - s - p) / 2;
    int last = r - s;
    int first = r - p;

    for (t = 0; t < num; (t)++)
    {
        int off = first - 1;
        
        /* 4 is assumed for the dimension */
        double* temp = new double[n + 1];

        temp[0] = Pw[off][0];
        temp[last + 1 - off] = Pw[last + 1][0];
        int i = first;
        int j = last;
        int ii = 1;
        int jj = last - off;
        int remflag = 0;

        while (j - i > t)
        {
            double alfi = (u - U[i]) / (U[i + ord + t] - U[i]);
            double alfj = (u - U[j - t]) / (U[j + ord] - U[j - t]);
            
            temp[ii] = (Pw[i][0] - (1.0 - alfi) * temp[ii - 1]) / alfi;
            temp[jj] = (Pw[j][0] - alfj * temp[jj + 1]) / (1.0 - alfj);
            i++;
            ii++;
            j--;
            jj--;
        }
        if (j - i < t)
        {
            if (Distance4D(temp[ii - 1], temp[jj + 1]) <= TOL)
                remflag = 1;
        } else {
            double alfi = (u - U[i]) / (U[i + ord + t] - U[i]);
            if (Distance4D(Pw[i], alfi * temp[ii + t + 1] + (1.0 - alfi) * temp[ii - 1]) <= TOL)
                remflag = 1;
        }
        if (remflag == 0)
            break;
        else {
            i = first;
            j = last;
            while (j - i > t)
            {
                Pw[i][0] = temp[i - off];
                Pw[j][0] = temp[j - off];
                i = i + 1;
                j = j - 1;
            }
        }
        first--;
        last++;
    }
    if (t == 0)
        return;

    for (int k = r + 1; k <= m; k++)
        U[k - t] = U[k];

    int j = fout;
    int i = j;

    for (int k = 1; k < t; k++)
    {
        if (k % 2 == 1)
            i = i + 1;
        else
            j = j - 1;
    }
    for (int k = i + 1; k <= n; k++)
    {
        Pw[j] = Pw[k];
        j = j + 1;
    }
}

int main() {
    int n = 5;
    int p = 2;
    vector<double> U = {0, 0, 0, 1, 2, 3, 3, 3};
    vector<vector<double>> Pw = {{0.0, 0.0, 0.0, 1.0},
                                 {1.0, 2.0, 1.0, 1.0},
                                 {3.0, 3.0, 0.0, 1.0},
                                 {4.0, 2.0, 2.0, 1.0},
                                 {6.0, 3.0, 3.0, 1.0},
                                 {7.0, 0.0, 2.0, 1.0},
                                 {8.0, 1.0, 0.0, 1.0}};
    double u = 2.0;
    int r = 3;
    int s = 2;
    int num = 2;
    int t = 1;

    RemoveCurveKnot(n, p, U, Pw, u, r, s, num, t);

    cout << "New Knot Vector U: ";
    for (double knot : U) {
        cout << knot << " ";
    }
    cout << endl;

    cout << "New Control Point Pw: " << endl;
    for (int i = 0; i < Pw.size(); i++)
    {
        for (double coord : Pw[i])
        {
            cout << coord << " ";
        }
        cout << endl;
    }
    
    return 0;
}