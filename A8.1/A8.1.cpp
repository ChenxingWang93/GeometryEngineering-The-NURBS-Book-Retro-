#include <iostream>
#include <cmath>
using namespace std;

void MakeRevolveSurf(double S, double T, double theta, int m, double* Pj, double* wj, int& n, double* U, double** Pij, double** wij) {
    int narcs;
    double dtheta, wm, angle;
    double cosines[5], sines[5];

    if (theta <= 90.0)
    {
        narcs = 1;
    } else if (theta <= 180.0) {
        narcs = 2;
        U[3] = U[4] = 0.5;
    } else if (theta <= 270.0)
    {
        narcs = 3;
        U[3] = U[4] = 1.0/3.0;
        U[5] = U[6] = 2.0/3.0;
    } else {
        narcs = 4;
        U[3] = U[4] = 0.25;
        U[5] = U[6] = 0.5;
        U[7] = U[8] = 0.75;
    }

    dtheta = theta / narcs;
    int j = 3 + 2 * (narcs - 1);

    for (int i = 0; i < 3; j++, i++)
    {
        U[i] = 0.0;
        U[j] = 1.0;
    }

    wm = cos(dtheta / 2.0);
    angle = 0.0;

    for (int i = 0; i <= narcs; i++)
    {
        angle = angle + dtheta;
        cosines[i] = cos(angle);
        sines[i] = sin(angle);
    }
    
    for (int j = 0; j <= m; j++)
    {
        double X, r;
        double Y[3];
        PointToLine(S, T, Pj[j], 0);
        X = Pj[j] - 0;
        r = VecNormalize(X);
        VecCrossProd(T, X, Y);
        Pij[0][j] = Pj[j];
        wij[0][j] = wj[j];
        double T0[3] = {Y[0], Y[1], Y[2]};
        int index = 0;

        for (int i = 1; i <= narcs; i++)
        {
            double P2[3] = {0 + r * cosines[i] * X + r * sines[i] * Y[0], r * cosines[i] * X + r * sines[i] * Y[i], r * cosines[i] * X + r * sines[i] * Y[2]};
            Pij[index + 2][j] = P2;
            wij[index + 2][j] = wj[j];

            double T2[3] = {-sines[i] * X + cosines[i] * Y[0], -sines[i] * X + cosines[i] * Y[1], -sines[i] * X + cosines[i] * Y[2]};
            Intersect3DLines();
            wij[index + 1][j] = wm * wj[j];

            index = index + 2;

            if (i < narcs)
            {
                for (int k = 0; k < 3; k++)
                {
                    Pj[j][k] = P2[k];
                    T0[k] = T2[k];
                }
            }
        }
    }
}

int main() {
    double S = 0.0, T = 1.0, theta = 180.0;
    int m = 3;
    double Pj[4] = {1.0,2.0,3.0,4.0};
    double wj[4] = {0.1,0.2,0.3,0.4};
    int n;
    double U[9], **Pij, **wij;

    /* Allocate memory for Pij and wij */
    Pij = new double*[8];
    wij = new double*[8];

    for (int i = 0; i < 8; i++)
    {
        Pij[i] = new double[4];
        wij[i] = new double[4]; 
    }

    MakeRevolveSurf(S, T, theta, m, Pj, wj, n, U, Pij, wij);

    /* Output n, U, Pij, and wij */
    cout << "n: " << n << endl;
    cout << "U: ";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << wij[i][j] << " ";
        }
    }
    cout << endl;

    /* Deallocate memory for Pij and wij */
    for (int i = 0; i < 8; i++)
    {
        delete[] Pij[i];
        delete[] wij[i];
    }
    delete[] Pij;
    delete[] wij;

    return 0;
}