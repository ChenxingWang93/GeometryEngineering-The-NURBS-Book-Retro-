
void deCasteljau2(double** P, int n, int m, double u0, double v0, double S) {
    double Q[m+1];
    if (n <= m)
    {
        /* code */
        for (int j = 0; j <= m; j++)
        {
            /* code */
            deCasteljau1(P[j], n, u0, Q[j]); //P[j][] is jth row 
        }
        deCasteljau1(Q, m, v0, S);
        
    } else {
        double* Q = new double[n+1];
        for (int i = 0; i <= n; i++)
        {
            /* code */
            deCasteljau1(P[i], m, v0, Q[i]); //P[][i] is ith column
        }
        deCasteljau1(Q, n, u0, S);
        delete[] Q;
    }
}