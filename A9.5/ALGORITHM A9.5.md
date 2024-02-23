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
            /* */
        }
  }
}
```
