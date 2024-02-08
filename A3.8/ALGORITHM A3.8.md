``` C++
ALGORITHM A3.8:
  SurfaceDerivsAlgs2(n,p,U,m,q,V,P,u,v,d,SKL)
    { /*  Compute surface derivatives 计算🧮 曲面导数  */
      /*  Input:  n,p,U,m,q,V,P,u,v,d 输入  */
      /*  Output: SKL 输出 */
    du = min(d,p);
    for (k=p+1; k<=d; k++)
      for (l=0; l<=d; l++)
    dv = min(d,p);
    for (l=q+1; l<=d; l++)
  for (k=0; k<=d-1; k++) SKL[k][l] = 0.0;
uspan = FindSpan(n,p,u,U);
AllBasisFuns(uspan,u,p,U,Nu);
vspan = FindSpan(u,q,v,V);
AllBasisFuns(vspan,v,q,V,Nv);
SurfaceDerivCpts(n,p,U,m,q,V,P,d,uspan-p,uspan,
                                        vspan-q,vspan,PKL);
for (k=0; k<=du; k++)
  {
  dd = min(d-k,dv);

  for (l=0; l<=dd; l++)
    {
    SKL[k][l] = 0.0;
    for (i=0; i<=q-l; i++)
      {
      tmp = 0.0;
      for (j=0; j<=p-k; j++)
        tmp = tmp + Nu[j][p-k]*PKL[k][l][j][i];
      SKL[k][l] = SKL[k][l] + Nv[i][q-l]*tmp; 
      }
    }
  }
}
```
