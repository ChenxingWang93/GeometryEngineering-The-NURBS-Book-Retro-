``` C++
ALGORITHM A3.4
  CurveDerivsAlg2(n,p,U,P,u,d,CK)
    { /*  Compute curve derivatives 🧮计算 弧形 导数 */
      /*  Input:  n,p,U,P,u,d 输入 */
      /*  Output: CK 输出 */
    du = min(d,p);
for (k=p+1; k<=d; k++)  CK[k] = 0.0;
span = FindSpan(n,p,u,U);
AllBasisFuns(span,u,p,U,N);
CurveDerivCpts(n,p,U,P,du,span-p,span,PK);
for (k=0; k<=du; k++)
  {
  CK[k] = 0.0;
  for (j=0; j<p-k; j++)
    CK[k] = CK[k] + N[j][p-k]*PK[k][j];
  }
    }
```