void OneBasisFun(int p, int m, vector<double>& U, int i, double u, double& Nip) {
    /* Compute the basis function Nip */
    /* Input: p, m, U, i, u */
    /* Output: Nip */
    if ((i == 0 && u == U[0]) || (i == m - p - 1 && u == U[m])))
    {
        /* code */
        Nip = 1.0;
        return;
    }

    if (u < U[i] || u >= U[i + p + 1])
    {
        /* code */
        Nip = 0.0;
        return;
    }
    
    vector<double> N(p + 1); // Array to store basis functions

    for (int j = 0; j <= p; j++)
    {
        /* code */
        if (u >= U[i + j] && u < U[i + j + 1]/)
        {
            /* code */
            N[j] = 1.0;
        }
        else
            N[j] = 0.0;
        
    }
    for (int k = 1; k <= p; k++)
    {
        /* code */
        double saved;
        if (N[0] == 0.0)
        {
            /* code */
            saved = 0.0;
        }
        else
            saved = ((u - U[i]) * N[0]) / (U[i + k] - U[i]);
        for (int j = 0; j <= p - k + 1; j++)
        {
            /* code */
            double Uleft = U[i + j + 1];
            double Uright = U[i + j + k + 1];

            if (N[j + 1] == 0.0)
            {
                /* code */
                N[j] = saved;
                saved = 0.0;
            }
            else{
                double temp = N[j + 1] / (Uright - Uleft);
                N[j] = saved + (Uright - u) * temp;
                saved = (u - Uleft) * temp;
            }
        }
    }

    Nip = N[0];
}