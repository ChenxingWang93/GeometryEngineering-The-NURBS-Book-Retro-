``` C++
ALGORITHM A3.3
  CurveDerivCpts(n,p,U,P,d,r1,r2,PK)
    { /*  Compute control points of curve derivatives 🧮计算 弧形 导数 的控制点  */
      /*  Input:  n,p,U,P,d,r1,r2 输入 */
      /*  Output: PK 输出 */
    r = r2-r1;
for (i=0; i<=r; i++)
  PK[0][i] = P[r1+i]
for (k=1; k<=d; k++)
  {
  tmp = p-k+1;
for (i=0; i<=r-k; i++)
  PK[k][i] = tmp*(PK[k-1][i+1]-PK[k-1][i])/
      (U[r1+i+p+1]-U[r1+i+k]);
  }
}
```
