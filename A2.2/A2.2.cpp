void BasisFuns(int i, double u, int p, double* U, double* N) {
    double* left = new double[p+1];
    double* right = new double[p+1];
    double saved, temp;
    N[0] = 1.0;
    for (int j = 1; j <= p; j++)
    {
        /* code */
        left[j] = u - U[i+1-j];
        right[j] = U[i+j] - u;
        saved = 0.0;
        for (int r = 0; r < j; r++)
        {
            /* code */
            temp = N[r] / (right[r+1] + left[j-r]);
            N[r] = saved + right[r+1] * temp;
            saved = left[j-r] * temp;
        }
        N[j] = saved;
    }
    delete[] left;
    delete[] right;
}