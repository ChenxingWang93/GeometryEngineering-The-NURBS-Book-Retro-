void AllBernstein(int n, double u, double B[]) {
    B[0] = 1.0;
    double u1 = 1.0 - u;

    for (int j = 1; j <= n; j++)
    {
        double saved = 0.0;
        for (int k = 0; k < j; k++)
        {
            double temp = B[k];
            B[k] = saved + u1 * temp;
            saved = u * temp;
        }
        B[j] = saved;
    }
}