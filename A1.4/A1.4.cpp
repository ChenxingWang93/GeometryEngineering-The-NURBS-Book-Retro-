void PointOnBezierCurve(double* P, int n, double u, double* C) {
    double B[n+1];
    AllBernstein(n, u, B);
    C[0] = 0.0;
    for (int k = 0; k <= n; k++)
    {
        /* code */
        C[0] += B[k] * P[k];
    }
}