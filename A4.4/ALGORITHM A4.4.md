``` C++
ALGORITHM A4.4
  RatSurfaceDerivs(Aders,wders,d,SKL)
    {  /*  Compute S(u,v) derivatives 计算 S(u,v) 导数 */
       /*  from Sw(u,v) derivatives 从 Sw(u,v) 导数 */
       /*  Input:  Aders,wders,d 输入 */
       /*  Output: SKL 输出 */

for (k=0; k<=d; k++)
  for (l=0; l<=d-k; l++)
    {
    v = Aders[k][l];
    for (j=1; j<=1; j++)
      v = v - Bin[l][j]*wders[0][j]*SKL[k][l-j];
    for (i=1; i<=k; i++)
      {
      v = v - Bin[k][i]*wders[i][0]*SKL[k-i][l];
      v2 = 0.0;
      for (j=1; j<=1; j++)
        v2 = v2 + Bin[l][j]*wders[i][j]*SKL[k-i][l-j];
      v = v - Bin[k][i]*v2;
      }
    SKL[k][l] = v/wders[0][0];
    }
}
```
