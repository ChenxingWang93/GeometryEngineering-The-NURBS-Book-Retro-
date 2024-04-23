void deCasteljau1(double* P, int n, double u, double* C) {
    double Q[n+1];

    /* Copy P into Q */
    for (int i = 0; i <= n; i++)
    {
        /* Copy P into Q */
        Q[i] = P[i];
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <= n - k; i++)
        {
            Q[i] = (1.0 - u) * Q[i] + u * Q[i + 1];
        }
    }
    
    C[0] = Q[0];
}