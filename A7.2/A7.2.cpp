#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void MakeOneArc(vector<double>& P0, vector<double>& T0, vector<double>& P2, vector<double>& T2, vector<double>& P, vector<double>& P1, double& w1) {
    vector<double> V02(3);
    /* placeholder for dummy values */
    for (int i = 0; i < 3; i++)
    {
        V02[i] = P2[i] - P0[i];
    }

    vector<double> dummy(3);
    /* 
     * `p1`& `p2` are points on the lines.
     * `v1`& `v2` are direction vectors of the lines.
     * `s`& `t` are parameters that describe the position of the intersection point along each line.
     * `pt` is the intersection point.
     */

    int Intersect3DLines(const vector<double>& p1, const vector<double>& v1, const vector<double>& p2, const vector<double>& v2, double& s, double & t, vector<double>& pt);
    int i = Intersect3DLines(P0, T0, P2, T2, dummy, dummy, P1);
    if (i == 0) {
        vector<double> V1P(3);
        for (int i = 0; i < 3; i++)
        {
            V1P[i] = P[i] - P1[i];
        }

        double alf0, alf2;
        Intersect3DLines(P1, V1P, P0, V02, alf0, alf2, dummy);
        double a = sqrt(alf2 / (1.0 - alf2));
        double u = a / (1.0 + a);
        double num = (1.0 - u) * (1.0 - u) * Dot(P - P0, P1 - P) + u * u * Dot(P - P0, P1 - P);
        double den = 2.0 * u * (1.0 - u) * Dot(P1 - P, P1 - P);
        w1 = num / den;
        return;
    } else {
        w1 = 0.0;
        double alf0, alf2;
        Intersect3DLines(P, T0, P0, V02, alf0, alf2, dummy);
        double a = sqrt(alf2 / (1.0 - alf2));
        double b = 2.0 * u * (1.0 - u);
        b = -alf0 * (1.0 - b) / b;
        for (int i = 0; i < 3; i++)
        {
            P1[i] = b * T0[i];
        }
        return;
    }
}

int main() {
    vector<double> P0 = {0, 0, 0};
    vector<double> T0 = {1, 0, 0};
    vector<double> P2 = {1, 1, 0};
    vector<double> T2 = {0, 1, 0};
    vector<double> P = {0.5, 0.5, 0}
    vector<double> P1(3);
    double W1;

    MakeOneArc(P0, T0, P2, T2, P, P1, w1);

    /* Output P1 and w1 */
    cout << "Control point P1: (" << P1[0] << ", " << P1[1] << ", " << P1[2] << ")" << endl;
    cout << "Weight w1: " << w1 << endl;

    return 0;
}