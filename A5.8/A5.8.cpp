#include <iostream>
#include <vector>
using namespace std;

/* Define tolerance */
const double TOL = 0.0001;

/* Function to compute distance in 4D space */
double Distance4D() {
    /* Implement distance calculation for 4D space */
    /* (Assuming implementation of Distance4D function) */

    /* Placeholder, replace with actual calculation */
    return 0.0;
}

void RemoveCurveKnot(int n, int p, vector<double>& U, vector<vector<double>>& Pw, double u, int r, int s, int num, int& t) {
    int m = n + p + 1;
    int ord = p + 1;
    int fout = (2 * r - s - p) / 2;
    int last = r - s;
    int first = r - p;

    for (t = 0; t < num; t++)
    {
        int off = first - 1;
        
        /* 4 is assumed for the dimension */
        vector<vector<double>> temp(last + 2 - off, vector<double>(4));
        temp[0] = Pw[off];
        temp[last + 1 - off] = Pw[last + 1];
        int i = first;
        int j = last;
        int ii = 1;
        int jj = last - off;
        int remflag = 0;

        while (j - i > t)
        {
            double alfi = (u - U[i]) / (U[i + ord + t] - U[i]);
            double alfj = (u - U[j - t]) / (U[j + ord] - U[j - t]);

            temp[ii] = {(Pw[i][0] - (1.0 - alfi) * temp[ii - 1][0]) / alfi,
                        (Pw[i][1] - (1.0 - alfi) * temp[ii - 1][1]) / alfi,
                        (Pw[i][2] - (1.0 - alfi) * temp[ii - 1][2]) / alfi,
                        (Pw[i][3] - (1.0 - alfi) * temp[ii - 1][3]) / alfi};
            temp[jj] = {(Pw[j][0] - alfj * temp[jj + 1][0]) / (1.0 - alfj),
                        (Pw[j][1] - alfj * temp[jj + 1][1]) / (1.0 - alfj),
                        (Pw[j][2] - alfj * temp[jj + 1][2]) / (1.0 - alfj),
                        (Pw[j][3] - alfj * temp[jj + 1][3]) / (1.0 - alfj)};
            i = i + 1;
            ii = ii + 1;
            j = j - 1;
            jj = jj - 1;
        }
        if (j - i < t)
        {
            if (Distance4D(temp[ii - 1], temp[jj + 1]) <= TOL)
                remflag = 1;
        } else {
            double alfi = (u - U[i]) / (U[i + ord + t] - U[i]);
            if (Distance4D(Pw[i], {alfi * temp[ii + t + 1][0] + (1.0 - alfi) * temp[ii - 1][0],
                                   alfi * temp[ii + t + 1][1] + (1.0 - alfi) * temp[ii - 1][1],
                                   alfi * temp[ii + t + 1][2] + (1.0 - alfi) * temp[ii - 1][2],
                                   alfi * temp[ii + t + 1][3] + (1.0 - alfi) * temp[ii - 1][3]}) <= TOL)
                remflag = 1;
        }
        if (remflag == 0)
            break;
        else {
            i = first;
            j = last;
            while (j - i > t)
            {
                Pw[i] = temp[i - off];
                Pw[j] = temp[j - off];
                i = i + 1;
                j = j - 1;
            }
        }
        first = first - 1;
        last = last + 1;
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