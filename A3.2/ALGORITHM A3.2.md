``` C++
ALGORITHM A3.2:
  CurveDerivsAlg1(n,p,U,P,u,d,CK)
    { /*  Compute curve derivatives 🧮计算 弧 导数 */
      /*  Input: n,p,U,P,u,d 输入 */
      /*  Output:CK 输出 */
    du = min(d,p);
    for (k=p+1; k<=d; k++)  CK[k]  = 0.0;
    span = FindSpan(n,p,u,U);
    DersBasisFuns(span,u,p,du,Unders);
    for (k=0; k<=du; k++)
  {
  CK[k] = 0.0;
  for (j=0; j<=p; j++)
    CK[k] = CK[k] + nders[k][j]*P[span-p+j];
  }
}
```