```C++
ALGORITHM A5.4
  RefineKnotVectCurve(n,p,U,Pw,X,r,Ubar,Qw)
    {  /*  Refine curve knot vector 细化 曲线 结向量 */
       /*  Input:  n,p,U,Pw,X,r 输入 */
       /*  Output: Ubar, Qw  */
    m = n+p+1;
    a = FindSpan(n,p,X[0],U);
    b = FindSpan(n,p,X[r],U);
    b = b+1;
    for (j=0; j<=a-p; j++)   Qw[j] = Pw[j];  
    for (j=b-1; j<=n; j++)   Qw[j+r+1] = Pw[j];
    for (j=0; j<=a; j++)     Ubar[j] = U[j];
    for (j=b+p; j<=m; j++)   Ubar[j+r+1] = U[j];
    i = b+p-1;    k = b+p+r;
    for (j=r; j>=0; j--)
    {
}
}
```
