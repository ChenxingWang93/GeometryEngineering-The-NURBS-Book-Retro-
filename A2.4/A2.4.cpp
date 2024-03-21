void OneBasisFun(int p, int m, vector<double>& U, int i, double u, double& Nip)
    /* Compute the basis function Nip */
    /* Input: p, m, U, i, u */
    /* Output: Nip */
    if ((i == 0 && u == U[0]) || (i == m - p - 1 && u == U[m])))
    {
        /* code */
        Nip = 1.0;
        return;
    }
    