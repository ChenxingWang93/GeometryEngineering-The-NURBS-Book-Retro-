#include <iostream>
#include <cmath>
using namespace std;

void MakeOneArc(double P0, double T0, double P2, double T2, double P, double& P1, double w1) {
    double V02 = P2 - P0;
    /* placeholder for dummy values */
    double dummy = 0.0;
    double alf0, alf2, a, u, num, den;

    int i = Intersect3DLines(P0, T0, P2, T2, dummy, dummy, P1);
    a = sqrt(alf2 / (1.0 - alf2));

    if (i == 0)
    {
        double V1P = P - P1;
        Intersect3DLines();
        a = sqrt(alf2 / (1.0 - alf2));
        u = a / (1.0 + a);
        num = (1.0 - u) * (1.0 - u) * Dot(P - P0, P1 - P) + u * u * Dot(P - P0, P1 - P);
        den = 2.0 * u * (1.0 - u) * Dot(P1 - P, P1 - P);
        w1 = num / den;
    } else {
        w1 = 0.0;
        Intersect3DLines(P, T0, P0, V02, alf0, alf2, dummy);
        a = sqrt(alf2 / (1.0 - alf2));
        double b = 2.0 * u * (1.0 - u);
        b = -alf0 * (1.0 - b) / b;
        P1 = b * T0;
    }
}

int main() {
    double P0 = 0.0, T0 = 1.0, P2 = 2.0, T2 = 3.0, P = 4.0, P1 = 0.0, w1 = 0.0;

    MakeOneArc(P0, T0, P2, T2, P, P1, w1);

    /* Output P1 and w1 */
    cout << "P1: " << P1 << endl;
    cout << "w1: " << w1 << endl;

    return 0;
}