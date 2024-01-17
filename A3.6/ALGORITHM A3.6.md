```Matlab
ALGORITHM A3.6
  SurfaceDerivsAlg1(n,p,U,m,q,V,P,u,v,d,SKL)
    { /*  Compute surface derivatives 计算🧮曲面导数🔢 */
      /*  Input:  n,p,U,m,q,V,P,u,v,d 输入 */
      /*  Output: SKL 输出 */
    du = min(d,p);
    for (k=p+1; k<=d; k++)
      for (l=0; l<=d-k; l++)   SKL[k][l] = 0.0;
    dv = min(d,p);
    for (l=q+1; l<=d; l++)
  for (k=0; k<=d-l; k++)   SKL[k][l] = 0.0;
uspan = FindSpan(n,p,u,U);
DersBasisFuns(uspan,u,p,du,U,Nu);
vspan = FindSpan(n,q,v,V);
DersBasisFuns(vspan,v,q,dv,V,Nv);
for (k=0; k<=du; k++)
  {
  for (s=0; s<=q; s++)
    {
    temp[s] = 0.0;
    for (r=0; r<=p; r++)
      temp[s] = temp[s] + Nu[k][r]*P[uspan-p+r][vspan-q+s];
    }
    dd = min(d-k,dv);
    for (l=0; l<=dd; l++)
      {
      SKL[k][l] = 0.0;
      for (s=0; s<=q; s++)
        SKL[k][l] = SKL[k][l] + Nv[l][s]*temp[s];
      }
  }
}
```
