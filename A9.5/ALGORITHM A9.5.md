``` C++
ALGORITHM A9.5
  LocalSurfInterp(n,m,Q,U,V,P)
    {  /*  Local surface interpolation */
       /*  through (n+1)(m+1) points  */
       /*  Input:  n,m,Q  */
       /*  Output: U,V,P  */
    total = 0.0;   /* get ub[], r[] and u direction tangents */
    for (k=0; k<=n; k++)   ub[k] = 0.0;
    for (l=0; l<=m; l++)
      {
      Compute and load T^u_{0,l} into td[0][l][0];
      r[l] = 0.0;
      for (k=1; k<=n; k++)
        {
        Compute and load T^u_{k,l} into td[k][l][0]
            /* Eqs.(9.31) and (9.33) */
        d = |Q_{k,l}-Q_{k,l-1}|;
        vb[l] = vb[l]+d;
        s[k] = s[k]+d;
        }
      total = total + s[k];
      }
      for (l=1; l<m; l++)   vb[l] = vb[l-1]+vb[l]/total;
      vb[m] = 1.0;
      Load the U knot vector;
      Load the V knot vector;
      Compute all Bezier control points along each row and
          column of data points.
      for (k=0; k<=n; k++)
        for (l=0; l<=m; l++)
          {
          Compute the D^{uv}_{k,l} by Eq.(9.59) and load into td[k][l][2].
          }
      for (k=0; k<n; k++)
        for (l=0; l<m; l++)
          {
          Compute the four inner control points of the  (k,l)th
              Bezier patch and load them into P.
          }
      Load the NURBS control points by discarding Bezier points
          along inner rows and columns    /* Figure 9.32c */
      }
```
