```
ALGORITHM A4.2
  RatCurveDerivs(Aders,wders,d,CK)
    {  /* Compute C(u) derivatives from Cw(u) derivatives */
       /* Input:  Aders,wders,d  */
       /* Output: CK  */
    for  (k=0; k<=d; k++)
  {
  v = Aders[k];
  for (i=1; i<=k; i++)
    v = v - Bin[k][i]*wders[i]*CK[k-i];
  CK[k] = v/wders[0];
  }
}
```
