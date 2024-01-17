```Matlab
ALGORITHM A3.5
  SurfacePoint(n,p,U,m,q,V,P,u,v,S)
    { /* Compute surface point */
      /* Input:  n,p,U,m,q,V,P,u,v */
      /* Output: S */
    uspan = FindSpan(n,p,u,U);
    BasisFuns(uspan,u,p,U,Nu);
    vspan = FindSpan(m,q,v,V);
    BasisFuns(vspan,v,q,V,Nv);
    uind = uspan-p;

S = 0.0;
for (l=0; l<=q; l++)
  {
  temp = 0.0;
  vind = vspan-q+l;
  for (k=0; k<=p; k++)
    temp = temp + Nu[k]*P[uind+k][vind];
  S = S + Nv[l]*temp;
  }
}
```
