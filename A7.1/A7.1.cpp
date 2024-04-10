#include <iostream>
#include <cmath>
using namespace std;

void MakeNurbsCircle(double O, double X, double Y, double r, double ths, double the, int& n, double* U, double* Pw) {
    if (the < ths) the = 360.0 + the;
    double theta = the - ths;
    int narcs;
    if (theta <= 90.0) narcs = 1;
    else if (theta <= 180.0) narcs = 2;
    else if (theta <= 270.0) narcs = 3;
    else narcs = 4;
    double dtheta = theta / narcs;
    n = 2 * narcs;
    double w1 = cos(dtheta / 2.0);
    double P0 = O + r * cos(ths) * X + r * sin(ths) * Y;
    double T0 = -sin(ths) * X + cos(ths) * Y;
    Pw[0] = P0;
    int index = 0;
    double angle = ths;
    for (int i = 1; i <= narcs; i++)
    {
        angle = angle + dtheta;
        double P2 = O + r * cos(angle) * X + cos(angle) * Y;
        Pw[index + 2] = P2;
        double T2 = 0 + r * cos(angle) * Y;
        /* Implement Intersect3DLines function here */
        /* Placeholder for dummy values */
        double dummy = 0.0;
        /* Placeholder for P1 */
        double P1 = 0.0;
        Pw[index + 1] = w1 * P1;
        index = index + 2;
        if (i < narcs)
        {
            P0 = P2;
            T0 = T2;
        }
    }
    int j = 2 * narcs + 1;
    for (int i = 0; i < 3; i++)
    {
        U[i] = 0.0;
        U[i + j] = 1.0;
    }
    switch (narcs)
    {
    case 1:
        break;
    case 2:
        U[3] = U[4] = 0.5;
        break;
    case 3:
        U[3] = U[4] = 1.0 / 3.0;
        U[5] = U[6] = 2.0 / 3.0;
        break;
    case 4:
        U[3] = U[4] = 0.25;
        U[5] = U[6] = 0.5;
        U[7] = U[8] = 0.75;
        break;
    }
}

int main() {
    double O = 0.0, X = 1.0, Y = 0.0, r = 1.0, ths = 0.0, the = 90.0;
    int n = 0;
    double U[10] = {0.0};
    double Pw[20] = {0.0};

    MakeNurbsCircle(O, X, Y, r, ths, the, n, U, Pw);

    /* Output n, U, and Pw arrays */
    cout << "n: " << n << endl;
    cout << "U array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << U[i] << " ";
    }
    cout << endl;
    cout << "Pw array: ";
    for (int i = 0; i < 20; i++)
    {
        cout << Pw[i] << " ";
    }
    cout << endl;

    return 0;
}