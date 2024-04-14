#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* Function to compute 3D distance between two points */
double Distance3D(vector<double>& point1, vector<double>& point2) {
    double distance = 0.0;
    for (int i = 0; i < 3; ++i)
    {
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

/* Function to compute removal bound curve */
void GetRemovalBndCurve(int n, int p, vector<double>& U, vector<vector<double>>& P, double u, int r, int s, double& Br) {
    int ord = p + 1;
    int last = r - s;
    int first = r - p;
    /* difference in index between temp and P */
    int off = first - 1;
    vector<vector<double>> temp(last + 2 - off, vector<double>(3, 0.0));

    temp[0] = P[off];
    temp[last + 1 - off] = P[last + 1];

    int i = first;
    int j = last;
    int ii = 1;
    int jj = last - off;

    while (j - i > 0)
    {
        double alfi = (u - U[i]) / (U[i + ord] - U[i]);
        double alfj = (u - U[j]) / (U[j + ord] - U[j]);
        for (int k = 0; k < 3; ++k)
        {
            temp[ii][k] = (P[i][k] - (1.0 - alfi) * temp[ii - 1][k]) / alfi;
            temp[jj][k] = (P[j][k] - alfi * temp[jj + 1][k]) / (1.0 - alfi);
        }
        i = i + 1;
        ii = ii + 1;
        j = j - 1;
        jj = jj - 1;
    }

    if (j - i < 0)
    {
        /* now get bound */
        Br = Distance3D(temp[ii - 1], temp[jj + 1]);
    } else {
        double alfi = (u - U[i]) / (U[i + ord] - U[i]);
        for (int k = 0; k < 3; ++k)
        {
            temp[ii][k] = (P[i][k] - (1.0 - alfi) * temp[ii - 1][k]) / alfi;
        }
        Br = Distance3D(P[i], alfi * temp[ii + 1] + (1.0 - alfi) * temp[ii - 1]);   
    }   
}

int main() {
    /* Example usage */ 
    int n, p, r, s;
    double u, Br;
    std::vector<double> U;
    std::vector<std::vector<double>> P;

    /* Call GetRemovalBndCurve function */ 
    GetRemovalBndCurve(n, p, U, P, u, r, s, Br);
    
    /* Output the removal bound curve */ 
    std::cout << "Removal Bound Curve: " << Br << std::endl;

    return 0;
}