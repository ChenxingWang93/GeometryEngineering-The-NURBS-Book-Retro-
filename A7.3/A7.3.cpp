#include <iostream>
#include <cmath>
using namespace std;

void MakeOpenConic(double P0, double T0, double P2, double T2, double P, int& n, double* U, double* Pw) {
    double P1, w1;
    MakeOneArc(P0,T0,P2,T2,P,P1,w1);

    if (w1 <= -1.0)
    {
        cout << "Error: outside convex hull" << endl;
        return;
    }

    int nsegs;
    if (w1 >= -1.0)
    {
        nsegs = 1;
    } else {
        if (w1 > 0.0 && Angle(P0, P1, P2) > 60.0)
        {
            nsegs = 1;
        } else if (w1 < 0.0 && Angle(P0, P1, P2) > 90.0)
        {
            nsegs = 4;
        } else {
            nsegs = 2;
        }
    }

    n = 2 * nsegs;
    int j = 2 * nsegs + 1;

    for (int i = 0; i < 3; i++)
    {
        U[i] = 0.0;
        U[i + j] = 1.0;
    }

    Pw[0] = P0;
    Pw[n] = P2;

    if (nsegs ==1)
    {
        Pw[1] = w1 * P1;
        return;
    }

    double Q1, S, R1, wqr;
    SplitArc(P0, P1, w1, P2, Q1, S, R1, wqr);

    if (nsegs == 2)
    {
        Pw[2] = S;
        Pw[1] = wqr * Q1;
        Pw[3] = wqr * R1;
        U[3] = U[4] = 0.5;
        return;
    }

    Pw[4] = S;
    w1 = wqr;
    SplitArc(P0, P1, w1, P2, Q1, S, R1, wqr);
    Pw[2] = HS;
    Pw[1] = wqr * HQ1;
    Pw[3] = wqr * HR1;

    SplitArc(S, R1, w1, P2, HQ1, HS, HR1, wqr);
    Pw[6] = HS;
    Pw[5] = wqr * HQ1;
    Pw[7] = wqr * HR1;

    for (int i = 0; i < 2; i++)
    {
        U[i + 3] = 0.25;
        U[i + 5] = 0.5;
        U[i + 7] = 0.75;
    }
}

int main() {
    double P0 = 0.0, T0 = 1.0, P2 = 2.0, T2 = 3.0, P = 4.0;
    int n;
    double U[9], Pw[8];

    MakeOpenConic(P0, T0, P2, T2, P, n, U, Pw);

    /* Output n, U, and Pw */
    cout << "n: " << n << endl;
    cout << "U: ";
    for (int i = 0; i < 9; i++)
    {
        cout << U[i] << " ";
    }
    cout << endl;

    cout << "Pw: ";
    for (int i = 0; i < 8; i++)
    {
        cout << Pw[i] << " ";
    }
    cout << endl;

    return 0;
}