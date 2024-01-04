``` matlab
ALGORITHM A1.5
  deCasteljau1 (P,n,u,C)
    {  /*  Compute point on a Bezier curve 🧮计算 贝塞尔曲线上的 点 ⦁ */
       /*  using deCasteljau 德卡斯特里奥 算法 */
       /*  Input: P,n,u  */
       /*  Output: C (a point)  */
    for (i=0; i<=n; i++)  /* Use local array so we do not 使用 局部数组 */
      Q[i] = P[i];
    for (k=1; k<=n; k++)
      for (i=0; i<=n-k; i++)
        Q[i] = (1.0-u)*Q[i] + u*Q[i+1];
    C = Q[0];
    }
```
