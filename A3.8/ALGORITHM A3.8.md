```Matlab
ALGORITHM A3.8:
  SurfaceDerivsAlgs2(n,p,U,m,q,V,P,u,v,d,SKL)
    { /*  Compute surface derivatives   */
      /*  Input:  n,p,U,m,q,V,P,u,v,d   */
      /*  Output: SKL  */
    du = min(d,p);
    for  (k=p+1; k<=d; k++)
      for  (l=0; l<=d; l++)
    dv = min(d,p);
    for  (l=q+1; l<=d; l++)
  for  (k=0; k<=d-1; k++) SKL[k][l] = 0.0;

}
```
