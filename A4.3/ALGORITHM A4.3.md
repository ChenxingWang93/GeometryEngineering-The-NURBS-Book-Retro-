``` C++
ALGORITHM A4.3
  SurfacePoint(n,p,U,m,q,V,Pw,u,v,S)
    { /*  Compute point on rational B-spline surface 计算🧮 在有理 B-样条 曲面上 的点 */
      /*  Input:  n,p,U,m,q,V,Pw,u,v 输入 */
      /*  Output: S 输出 */
    uspan = FindSpan(n,p,u,U);
    BasisFuns(uspan,u,p,u,U);
    vspan = FindSpan(m,q,v,v);
    BasisFuns(vspan,v,q,v,Nv);
    for (l=0; l<=q; l++)

  {
  temp[l] = 0.0;
  for (k=0; k<=p; k++)
    temp[l] = temp[l] + Nu[k]*Pw[uspan-p+k][vspan-q+l];
  }
Sw = 0.0;
for (l=0; l<=q; l++)
  Sw = Sw + Nv[l]*temp[l];
S = Sw/w;
}
```