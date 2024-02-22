``` C++
ALGORITHM A7.2
  MakeOneArc(P0,T0,P2,T2,P,P1,w1)
    {  /*  Create one Bezier conic arc 创建 1 个贝塞尔 锥 弧 */
       /*  Input:  P0,T0,P2,T2,P  */
       /*  Output: P1,w1  */
    V02 = P2-P0;
    i = Intersect3DLines(P0,T0,P2,T2,dummy,dummy,P1);
    if (i == 0)
      {  /* finite control point 有限 控制点 */
      
      }
}
```
