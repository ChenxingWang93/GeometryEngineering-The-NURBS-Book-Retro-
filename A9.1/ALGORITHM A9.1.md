``` C++
ALGORITHM A9.1
  GlobalCurveInterp(n,Q,r,p,m,U,P)
    {  /*  Global interpolation through n+1 points 全局拟合 n+1 个点 */
       /*  Input:  n,Q,r,p 输入 */
       /*  Output: m,U,P 输出 */
    m = n+p+1;
Compute the uk;    /* Eq.(9.5) or (9.6) */
Compute the knot vector U;   /* Eq.(9.8) */
Initialize array A to zero;
for (i=0; i<=n; i++)
  {  /* Set up coefficient matrix 设置 系数 矩阵 */
  span = FindSpan(n,p,uk[i],U);
  BasisFuns(span,uk[i],p,U,A[i][span-p]); /* Get ith row 获取 第i行 */
  }
LUDecomposition(A,n+1,p-1);
for (i=0; i<r; i++)   /* r is the number of coordinates r 为 坐标数量 */
  {
  for (j=0; j<=n; j++)   rhs[j] = ith coordinate of Q[j];
  ForwardBackward(A,n+1,p-1,rhs,sol);
  for (j=0; j<=n; j++)   ith coordinate of P[j] = sol[j];
  }
}
```
