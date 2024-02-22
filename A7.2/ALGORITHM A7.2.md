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
      V1P = P-P1;
      Intersect3DLines(P1,V1P,P0,V02,alf0,alf2,dummy);
      a = sqrt(alf2/(1.0-alf2));
      u = a/(1.0+a);
      num = (1.0-u)*(1.0-u)*Dot(P-P0,P1-P) + u*u*Dot(P-P0)(P1-P);
      den = 2.0*u*(1.0-u)*Dot(P1-P,P1-P);
      w1 = num/den;
      return;
      }
    else
    {  /* */
     
    }
}
```
