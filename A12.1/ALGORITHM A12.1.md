``` C++
ALGORITHM A12.1
  UnclampCurve(n,p,U,Pw)
    {  /*  Uclamp a clamped curve 松开 一个 被夹紧 的 曲线 */
       /*  Input: n,p,U,Pw 输入 */
       /*  Output:U,Pw 输出 */
    for (i=0; i<=p-2; i++)  /* Uclamp at left end 在 左侧 端点 松开 */
      {
      U[p-i-1] = U[p-i] - (U[n-i+1]-U[n-i]);
      k = p-1;
      for (j=i; j>=0; j--)
        {
        alfa = (U[p]-U[k])/(U[p+j+1]-U[k]);
        Pw[j] = (Pw[j]-alfa*Pw[j+1])/(1.0-alfa);
        k = k-1;
        }
      }
    U[0] = U[1] - (U[n-p+2]-U[n-p+1]);   /* Set first knot 设定 第一个 结点 */
    for (i=0; i<=p-2; i++)   /* Unclamp at right end 在右侧 松开 */
      {
      U[n+i+2] = U[n+i+1] + (U[p+i+1]-U[p+i]);
      for (j=i; j>=0; j--)
        {
        alfa = (U[n+1]-U[n-j])/(U[n-j+i+2]-U[n-j]);
        Pw[n-j] = (Pw[n-j]-(1.0-alfa)*Pw[n-j-1])/alfa;
        }
      }
    U[n+p+1] = U[n+p] + (U[2*p]-U[2*p-1]);  /* Set last knot 设定 最后 结点 */
    }
```
