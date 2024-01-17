```Matlab
ALGORITHM A4.4
  RatSurfaceDerivs(Aders,wders,d,SKL)
    {  /*  Compute S(u,v) derivatives  */
       /*  from Sw(u,v) derivatives  */
       /*  Input:  Aders,wders,d  */
       /*  Output: SKL  */

for (k=0; k<=d; k++)
  for (l=0; l<=d-k; l++)
    {
    v = Aders[k][l];
    for (j=1; j<=1; j++)
      v = v - Bin[l][j]*wders[0][j]*SKL[k][l-j];
    for (i=1; i<=k; i++)
      {
      v = v - Bin[k][i]*wders[i][0]*SKL[k-i][l];
      v2 = 0.0;
      for (j=1; j<=1; j++)
        v2 = v2 + Bin[l][j]*wders[i][j]*SKL[k-i][l-j];
      v = v - Bin[k][i]*v2;
      }
    SKL[k][l] = v/wders[0][0];
    }
}
```
