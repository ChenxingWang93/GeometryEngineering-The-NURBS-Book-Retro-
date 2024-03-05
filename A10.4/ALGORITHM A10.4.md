``` C++
ALGORITHM A10.4
  BicubicBlendCoons(Ck,Cl,Dk,Dl,n,m,p,q,U,V,Pij)
    {  /*  Create bicubically blended Coons surface. 创建 双三次 混合 浣熊 曲面 */
       /*  Input:  Ck,Cl,Dk,Dl 输入 */
       /*  Output: n,m,p,q,U,V,Pij 输出 */
    Compute the ctrl pts of 𝑺_{𝟷}(𝑢,𝑣) (Eq.10.40)
    Compute the ctrl pts of 𝑺_{𝟸}(𝑢,𝑣) (Eq.10.41)
    Compute the ctrl pts of 𝑇_(𝑢,𝑣) (Eq.10.42)
    pcd = degree of the Ck curves and Dk derivatives.
    qcd = degree of the Cl curves and Dl derivatives.
    p = max(3,pcd);
    q = max(3,qcd);
    Degree elevate 𝑺_{𝟷}(𝑢,𝑣), 𝑺_{𝟸}(𝑢,𝑣) and 𝑇_(𝑢,𝑣) to (p,q)
        if necessary.
    U = u-knot vector of 𝑺_{𝟷}(𝑢,𝑣).
    V = v-knot vector of 𝑺_{𝟸}(𝑢,𝑣).
  Knot refine 𝑺_{𝟷}(𝑢,𝑣), 𝑺_{𝟸}(𝑢,𝑣) and 𝑇_(𝑢,𝑣) to
      𝑈 and 𝑉 if necessary.
  𝑛 = (number of 𝑢-knots)-p-2.
  𝑚 = (number of 𝑣-knots)-q-2.
  Compute surface control points Pij by Eq.(10.43).
}
```
