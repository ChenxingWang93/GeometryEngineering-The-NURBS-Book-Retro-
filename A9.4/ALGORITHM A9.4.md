``` C++
ALGORITHM A9.4
  GlobalSurfInterp(n,m,Q,p,q,U,V,P)
    {  /*  Global surface interpolation 全局 曲面 拟合 */
       /*  Input:  n,m,Q,p,q  */
       /*  Output: U,V,P  */
    SurfMeshParams(n,m,Q,uk,vl);  /* get parameters 获取 参数 */
    Compute U using Eq.(9.8);
    Compute V using Eq.(9.8);
    for (l=0; l<=n; l++)
  {
  Do curve interpolation through Q[0][l],...,Q[n][l];
  This yields R[0][l],...,R[n][l];
  }
for (i=0; i<=n; i++)
  {
  Do curve interpolation through R[i][0],...,R[i][m];
  This yields P[i][0],...,P[i][m];
  }
}
```
