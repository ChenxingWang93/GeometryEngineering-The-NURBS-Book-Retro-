``` Matlab
ALGORITHM A1.7
  deCasteljau2(P,n,m,u0,v0,S)
    {  /*  Compute a point on a Bezier surface 贝塞尔曲面上 🧮计算一个点 ∙  */
       /*  by the deCasteljau. deCasteljau 递推 */
       /*  Input:  P,n,m,u0,v0  */
       /*  Output: S*/
    if (n <= m)
      {
      for (j=0; j<=m; j++)   /* P[j][] is jth row 第 jth 行 */
        deCasteljau1(P[j][],n,u0,Q[j]);
      deCasteljau1(Q,m,v0,S)
      }
    else
      {
      for (i=0; i<=n; i++)
        deCasteljau1(P[][i],m,v0,Q[i]);
      deCasteljau1(Q,n,u0,S);
      }
    }
```
