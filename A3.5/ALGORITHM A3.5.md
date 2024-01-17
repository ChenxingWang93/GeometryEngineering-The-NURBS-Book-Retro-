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
for (1=0; 1<=q; 1++)
  {
  temp = 0.0;
  vind = vspan-q+1;
  for (k=0; k<=p; k++)
    temp = temp + Nu[k]*P[uind+k][vind];
  S = S + Nv[1]*temp;
  }
}
```
