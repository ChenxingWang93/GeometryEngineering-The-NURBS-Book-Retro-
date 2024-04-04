```C++
ALGORITHM A4.1
  CurvePoint(n,p,U,Pw,u,C)
    {  /* Compute point on rational B-spline curve 计算在 有理 B-spline 曲线上 的点 */
       /* Input:  n,p,U,Pw,u 输入 */
       /* Output: C 输出 */
    span = FindSpan(n,p,u,U);
    BasisFuns(Span,u,p,U,N);
    Cw = 0.0;
for (j=0; j<=p; j++)
  Cw = Cw + N[j]*Pw[span-p+j];
C = Cw/w;   /*  Divide by weight 通过 权重 划分 */
}
```