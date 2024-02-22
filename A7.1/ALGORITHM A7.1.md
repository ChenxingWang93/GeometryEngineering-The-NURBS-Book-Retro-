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
  
  }
}
```
