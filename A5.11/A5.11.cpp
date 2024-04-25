void DegreeReduceCurve(int n, int p, double* U, double* Qw, int nh, double* Uh, double* Pw) {
    int ph = p - 1;
    int mh = ph;
    int kind = ph + 1;
    int r = -1;
    int a = p;
    int b = p + 1;
    int cind = 1;
    int mult = p;
    int m = n + p + 1;
    Pw[0] = Qw[0];

    double Uh[ph+1];
    double bpts[p+1];
    double e[m];
    double alphas[p];
    double rbpts[p];

    for (int i = 0; i <= ph; i++)
        Uh[i] = U[0];

    for (int i = 0; i <= p; i++)
        bpts[i] = Qw[i];
    
    for (int i = 0; i < m; i++)
        e[i] =  0.0;
    
    while (b < m)
    {
        int i = b;
        while (b < m && U[b] == U[b + 1])
            b = b + 1;
        
        int mult = b - i + 1;
        mh = mh + mult - 1;
        int oldr = r;
        r = p - mult;

        if (oldr > 0)
            lbz = (oldr + 2) / 2;
        else
            lbz = 1;

        if (r > 0)
        {
            double numer = U[b] - U[a];
            for (int k = p; k >= mult; k--)
                alphas[k - mult - 1] = numer / (U[a + k] - U[a]);
            for (int j = 1; j <= r; j++)
            {
                int save = r - j;
                int s = mult + j;
                for (int k = p; k >= s; k--)
                    bpts[k] = alphas[k - s] * bpts[k] + (1.0 - alphas[k - s]) * bpts[k - 1];
                Nextbpts[save] = bpts[p];
            }
        }

        /* Degree reduce Bezier segment 贝塞尔线段的度数减少 */
        BezDegreeReduce(bpts, rbpts, MaxErr);
        e[a] = e[a] + MaxErr;

        if (e[a] > TOL)
            /* Curve not degree reducible 曲线不是度可约 */
            return 1;
        
        /* Remove knot U[a] older times */
        if (oldr > 0)
        {
            int first = kind;
            int last = kind;
            for (int k = 0; k < oldr; k++)
            {
                int i = first;
                int j = last;
                int kj = j - kind;
                while (j - i > k)
                {
                    double alfa = (U[a] - Uh[i - 1]) / (U[b] - Uh[i - 1]);
                    double beta = (U[a] - Uh[j - k - 1]) / (U[b] - Uh[j - k - 1]);
                    Pw[i - 1] = (Pw[i - 1] - (1.0 - alfa) * Pw[i - 2]) / alfa;
                    rbpts[kj] = (rbpts[kj] - beta * rbpts[kj + 1]) / (1.0 - beta);
                    i = i + 1;
                    j = j - 1;
                    kj = kj - 1;
                }

                /* Compute knot removal error bounds (Br) */
                double Br;
                if (j - i < k)
                    Br = Distance4D(Pw[i - 2], rbpts[kj + 1]);
                else {
                    double delta = (U[a] - Uh[i - 1]) / (U[b] - Uh[i - 1]);
                    double A = delta * rbpts[kj + 1] + (1.0 - delta) * Pw[i - 2];
                    Br = Distance4D(Pw[i - 1], A);
                }
                
                /* Update the error vector */
                int K = a + oldr - k;
                int q = (2 * q - k + 1) / 2;
                int L = K - q;
                for (int ii = L; ii <= a; ii++)
                {
                    e[ii] = e[ii] + Br;
                    if (e[ii] > TOL)
                        return 1;
                }

                first = first - 1;
                last = last + 1;
            }
            cind = i - 1;
        }

        /* Load knot vector and control points */
        if (a != p)
        {
            for (int i = 0; i < ph - oldr; i++)
            {
                Uh[kind] = U[a];
                kind = kind + 1;
            }
        }
        
        for (int i = lbz; i <= ph; i++)
        {
            Pw[cind] = rbpts[i];
            cind = cind + 1;
        }

        if (b < m)
        {
            for (int i = 0; i < r; i++)
                bpts[i] = Nextbpts[i];
                cind = cind + 1;
            for (int i = r; i <= p; i++)
                bpts[i] = Qw[b - p + i];

            a = b;
            b = b + 1;
        } else {
            for (int i = 0; i <= ph; i++)
                Uh[kind + i] = U[b];
        }
    }

    nh = mh - ph - 1;
    return 0;
}

