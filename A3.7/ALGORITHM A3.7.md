```Matlab
ALGORITHM A3.7
  SurfaceDerivCpts(n,p,U,m,q,V,P,d,r1,r2,s1,s2,PKL)
    { /*  Compute control points of derivative surfaces  */
      /*  Input:  n,p,U,m,q,V,P,d,r1,r2,s1,s2  */
      /*  Output: PKL  */
    du = min(d,p);    dv = min(d,q);
    r = r2-r1;    s = s2-s1;
    for (j=s1; j<=s2; j++)
      {
  CurveDerivCpts(n,p,U,&P[][j],du,r1,r2,temp);
  for (k=0; k<=du; k++)
    for (i=0; i<=r-k; i++)
      PKL[k][0][i][j-s1] = temp[k][i];
  }
for (i=0; k<du; k++)
  for (i=0; i<=r-k; i++)
    {
    dd = min(d-k,dv);
    CurveDerivCpts(m,q,&V[s1],&PKL[k][0][i][],dd,0,s,temp);
    for (l=1; l<=dd; l++)
      for (j=0; j<=s-l; j++)
        PKL[k][l][i][j] = temp[l][j];
    }
}
```
