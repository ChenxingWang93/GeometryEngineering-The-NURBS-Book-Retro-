``` C++
ALGORITHM A9.7
  GlobalSurfApproxFixednm(r,s,Q,p,q,n,m,U,V,P)
    {  /*  Global surface approx with fixed num of ctrl pts 以 固定 数量 的控制点 全局 曲面 近似 */
       /*  Input:  r,s,Q,p,q,n,m 输入 */
       /*  Output: U,V,P 输出 */
    SurfMeshParams(r,s,Q,ub,vb);
    Compute knots U by Eqs.(9.68),(9.69);
    Compute knots V by Eqs.(9.68),(9.69);
    Compute Nu[][] and NTNu[][] using Eq.(9.66);
    LUDecomposition(NTNu,n-1,p);
for (j=0; j<=s; j++)
  {  /* u direction fits u 方向 适配 */
  Temp[0][j] = Q_{0,j}; Temp[n][j] = Q_{r,j};
  Compute and local Ru[](Eqs.[9.63],[9.67]);
  Call ForwardBackward() to get the control points
      Temp[1][j],...,Temp[n-1][j];
  }
Compute Nv[][] and NTNv[][] using Eq.(9.66);
LUDecomposition(NTNv,m-1,q);
for (i=0; i<=n; i++)
  {  /* v direction fits v 方向 适配 */
  P[i][0] = Temp[i][0];    P[i][m] = Temp[i][s];
  Compute and load Rv[] (Eqs.[9.63],[9.67]);
  Call ForwardBackward() to get the control points
      P[i][1],...,P[i][m-1];
  }
}
```
