``` C++
SweepSurface2(T,C,Bv,sv,q,K,V,Pw)
  {  /*  Swept surface.  Trajectory not interpolated. 扫掠。 轨迹 未插值  */
     /*  Input:  T,C,Bv,sv,q,K 输入 */
     /*  Output: V,Pw 输出 */
  Determine values ṽ_{0},...,ṽ_{k} at which to place the
    instance of 𝐶(𝑢).       A reasonable choice is to select the
    𝑣_{𝑘} so that the 𝐓(𝑣_{𝑘}) are approximately evenly
    spaced.
  for (k=0; k<=K; k++)
    {  /* Transform and position section control points 变换 &定位 截面 控制 点 */
    Let 𝑸_{𝑖} and 𝑤_{𝑖} be the control points and weights
      of 𝐶(𝑢), 𝑖 = 𝟶,...,𝑛.
    Scale the control points 𝑸_{𝑖} by sv.
    Compute {𝒐,𝒙,𝒚,𝒛}(ṽ_{k}) from Eqs.(𝟷𝟶.𝟸𝟶)-(𝟷𝟶.𝟸𝟸).
    Compute the transformation matrix 𝑨(ṽ_{k}) transforming the
  global system into global system into {𝒐,𝒙,𝒚,𝒛}(ṽ_{k}).
  Apply 𝑨(ṽ_{k}) to the scaled 𝑸_{𝑖}.
  Reapply the weights 𝑤_{𝑖}, and denote the resulting
    weighted control points by 𝑸_{𝒌,𝒊}^{𝑤}.
  }
Determine ṽ_{0},...,ṽ_{k}, the v-parameters for the
  v-directional interpolations (Eqs.[𝟷𝟶.𝟾] or [𝟷𝟶.𝟷𝟺]).
Given 𝑞 and the ṽ_{k}, compute the knot vector 𝑽 by averaging
  (Eq.[𝟿.𝟾]).
for (i = 0 i<=n; i++)
  {
  Interpolate across 𝑸_{𝟶,𝒊}^{𝑤},...,𝑸_{𝑲,𝒊}^{𝑤} to obtain 𝑷_{𝟶,𝒊}^{𝑤},...,𝑷_{𝑲,𝒊}^{𝑤}.
  }
}
```
