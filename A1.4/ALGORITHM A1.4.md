``` C++
ALGORITHM A1.4
  PointOnBezierCurve(P, n, u, C)
    {  /*  Compute point on Bezier curve 🧮计算 贝塞尔曲线 上的点 */
       /*  Input: P,n,u 输入 */
       /*  Output: C (a point) 输出 */
    AllBernstein(n,u,B)  /* B is a local array B为 局部数组 */
    C = 0.0;
    for (k=0; k<=n; k++)  C = C + B[k]*P[k];
    }
```

```

```

<img width="200" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/698330f5-73b8-468e-ba6d-461efd4bde8b"> = <img width="100" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/af252ed7-2ffc-4a36-aed3-e01f61498ee3">
