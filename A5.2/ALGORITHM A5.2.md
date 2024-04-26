``` C++
ALGORITHM A5.2
  CurvePntByCornerCut(n,p,U,Pw,u,C)
    {  /*  Compute point on rational b- spline curve 計算🧮 在有理b- 樣條曲線上的點 */
       /*  Input:  n,p,U,Pw,u 輸入 */
       /*  Output: C 輸出 */
    if (u == U[0])  /* Endpoints are special cases 終點 爲 特殊情況 */
      {
      C = Pw[0]/w;   return;
      }
    if (u == U[n+p+1])
  {
  C = Pw[n]/w;   return;
  }
FindSpanMult(n,p,u,U,&k,&s);    /* General case 普遍情況 */
r = p-s;
for (i=0; i<=r; i++)   Rw[i] = Pw[k-p+i];
for (j=1; j<=r; j++)
  for (i=0; i<=r-j; i++)
    {
    alfa = (u-U[k-p+j+i])/(U[i+k+1]-U[k-p+j+i]);
    Rw[i] = alfa*Rw[i+1] + (1.0-alfa)*Rw[i];
    }
C = Rw[0]/w
}
```