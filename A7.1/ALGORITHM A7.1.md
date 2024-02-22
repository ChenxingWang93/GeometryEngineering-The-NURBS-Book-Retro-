``` C++
ALGORITHM A7.1
  MakeNurbsCircle(O,X,Y,r,ths,the,n,U,Pw)
    {  /*  Create arbitrary NURBS circular arc 创建 随机 NURBS 圆弧  */
       /*  Input:  O,X,Y,r,ths,the 输入： */
       /*  Output: n,U,Pw 输出： */
    if (the < ths)   the = 360.0 + the;
    theta = the-ths;                  
    if (theta <= 90.0)   narcs = 1;   /* get number of arcs 获取 弧 数量 */
      else
        if (theta <= 180.0)   narcs = 2;
          else
            if (theta <= 270.0)   narcs = 3;
              else
                narcs = 4;
    dtheta = theta/narcs;
    n = 2*narcs;    /* n+1 control points n+1 控制点 */
    w1 = cos(dtheta/2.0);   /* dtheta/2 is base angle 基 角度 */
    P0 = 0 + r*cos(ths)*X + r*sin(ths)*Y;
    T0 = -sin(ths)*X + cos(ths)*Y; /* Initialize start values 初始化 开始 值*/
    Pw[0] = P0;
index = 0;   angle = ths;
for (i=1; i<=narcs; i++)
  {
  angle = angle + dtheta;
  P2 = 0 + r*cos(angle)*X + r*sin(angle)*Y;
  Pw[index+2] = P2;
  T2 = -sin(angle)*X + cos(angle)*Y;
  Intersect3DLines(P0,T0,P2,T2,dummy,dummy,P1);
  Pw[index+1] = w1*p1;
  index = index + 2;
  if (i<narcs)     {  P0 = P2;   T0 = T2;  }
  }
j = 2*narcs+1;   /* load the knot vector 加载 结点 向量 */
for (i=0; i<3; i++)
  {  U[i] = 0.0;   U[i+j] = 1.0;  }
switch (narcs)
  {
  case 1:  break;
  case 2:  U[3] = U[4] = 0.5;
           break;
  case 3:  U[3] = U[4] = 1.0/3.0;
           U[5] = U[6] = 2.0/3.0;
           break; 
  case 4:  U[3] = U[4] = 0.25;
           U[5] = U[6] = 0.5;
           U[7] = U[8] = 0.75;
           break;
  }
}
```
