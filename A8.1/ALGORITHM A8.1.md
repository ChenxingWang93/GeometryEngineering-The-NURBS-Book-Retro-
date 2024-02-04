![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/bcf7a715-f21d-445b-a9c3-8a8d67be7872)

``` C++
ALGORITHM A8.1 
  MakeRevolveSurf(S,T,theta,m,Pj,wj,n,U,Pij,wij)
    {  /*  Create NURBS surface of revolution 创建 NURBS 曲面 */
       /*  Input:  S,T,theta,m,Pj,wj 输入： */
       /*  Output: n,U,Pij,wij 输出： */
    if (theta <= 90.0)   narcs = 1;
      else
        if (theta <= 180.0)
          {  narcs = 2;   U[3] = U[4] = 0.5;  }
          else
if (theta <= 270.0)
  {
  narcs = 3;
  U[3] = U[4] = 1.0/3.0;
  U[5] = U[6] = 2.0/3.0;
  }
  else
  {
          narcs = 4;
          U[3] = U[4] = 0.25;
          U[5] = U[6] = 0.5;
          U[7] = U[8] = 0.75;
          }
dtheta = theta/narcs;
j = 3 + 2*(narcs-1);   /* load end knots 加载 端 结点 */
for (i=0; i<3; j++, i++)
  {  U[i] = 0.0;  U[j] = 1.0;  }
n = 2*narcs
wm = cos(dtheta/2.0);  /* dtheta/2 is base angle dtheta/2 是 base 角 */
angle = 0.0;   /* Compute sines and cosines only once 只计算🧮 正弦余弦 一次*/
for (i=1; i<=narcs; i++)
  {
  angle = angle + dtheta;
  cosines[i] = cos(angle);
  sines[i] = sin(angle);
  }
for (j=0; j<=m; j++)
  /* Loop and compute each u row of ctrl pts and weights 循环 &计算 每 u 行 的控制点 &权重*/
  {
PointToLine(S,T,Pj[j],0);
X = Pj[j]-0;
r = VecNormalize(X);    VecCrossProd(T,X,Y);
Pij[0][j] = P0 = Pj[j];   /* Initialize first 初始化 */
wij[0][j] = wj[j];       /* ctrl pt & weight 控制点 &权重 */
T0 = Y;   index = 0;   angle = 0.0;
for (i=1; i<=narcs; i++)   /* compute u row */
  {
  P2 = 0 + r*cosines[i]*X + r*sines[i]*Y;
  Pij[index+2][j] = P2;
  wij[index+2][j] = wj[j];
    T2 = -sines[i]*X + cosines[i]*Y;
    Intersect3DLines(P0,T0,P2,T2,Pij[index+1][j]);
    wij[index+1][j] = wm*wj[j];
    index = index + 2;
    if (i < narcs)   {  P0 = P2;   T0 = T2;  }
    }
  }  
}
```


