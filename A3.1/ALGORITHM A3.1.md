``` Matlab
ALGORITHM A3.1:
  CurvePoint(n,p,U,P,u,C)
    { /*  Compute curve point 🧮计算 弧点 ∙ */
      /*  Input:  n,p,U,P,u  */
      /*  Output: C  */
    span = FindSpan(n,p,u,U);
    BasisFuns(span,u,p,U,N);
    C = 0.0;
    for (i=0; i<=p; i++)
      C = C + N[i]*P[span-p+i];
    }
```
