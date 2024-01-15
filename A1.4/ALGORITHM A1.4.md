``` Matlab
ALGORITHM A1.4
  PointOnBezierCurve(P, n, u, C)
    {  /*  Compute point on Bezier curve 🧮计算 贝塞尔曲线 上的点 */
       /*  Input: P,n,u  */
       /*  Output: C (a point)  */
    AllBernstein(n,u,B)  /* B is a local array B为 局部数组 */
    C = 0.0;
    for (k=0; k<=n; k++)  C = C + B[k]*P[k];
    }
```

```

```
