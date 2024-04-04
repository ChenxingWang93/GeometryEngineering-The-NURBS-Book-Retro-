``` C++
ALGORITHM A4.2
  RatCurveDerivs(Aders,wders,d,CK)
    {  /* Compute C(u) derivatives from Cw(u) derivatives 从 Cw(u)导数 计算 C(u)导数 */
       /* Input:  Aders,wders,d 输入 */
       /* Output: CK 输出 */
    for  (k=0; k<=d; k++)
  {
  v = Aders[k];
  for (i=1; i<=k; i++)
    v = v - Bin[k][i]*wders[i]*CK[k-i];
  CK[k] = v/wders[0];
  }
}
```