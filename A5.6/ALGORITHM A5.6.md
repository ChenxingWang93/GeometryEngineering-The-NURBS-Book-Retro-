```C++
ALGORITHM A5.6
  DecomposeCurve(n,p,U,Pw,nb,Qw)
    {  /*  Decompose curve into Bezier segments 分解曲線爲 貝塞爾曲線 */
       /*  Input:    n,p,U,Pw 輸入 */
       /*  Output:   nb,Qw 輸出 */
    m = n+p+1;
    a = p;
    b = p+1;
    nb = 0;
    for (i=0; i<=p; i++)    Qw[nb][i] = Pw[i];
    while (b < m)
      {
        i = b;
        while (b < m && U[b+1] == U[b])    b++;
        mult = b-i+1;
        if (mult < p)
          {
            numer = U[b] - U[a];    /* Numerator of alpha */
            /* Compute and store alphas */
            for (j=p; j>mult; j--)
              alphas[j-mult-1] = numer/(u[a+j]-U[a]);
            r = p-mult;    /* Insert knot r times */
            for (j=1; j<=r; j++)
              {
                save = r - j;
                s = mult+j;    /* This many new points */
                for (k=p; k>=s; k--)
                  {
                    alpha = alphas[k-s];
                    Qw[nb][k] = alpha*Qw[nb][k] + (1.0-alpha)*Qw[nb][k-1];
                  }
                      if (b < m)          /* Control point of */
                        Qw[nb+1][save] = Qw[nb][p];  /* next segment */    
              }
          }
                nb = nb + 1;   /* Bezier segment completed */
                if (b < m)
                  {   /* Initialize for next segment */
                  for (i=p-mult; i<=p; i++)   Qw[nb][i] = Pw[b-p+i];
                  a = b;
                  b = b+1;
                  }
      }
    }
```