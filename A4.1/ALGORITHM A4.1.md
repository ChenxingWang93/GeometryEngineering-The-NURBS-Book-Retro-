```C++
ALGORITHM A4.1
  CurvePoint(n,p,U,Pw,u,C)
    {  /* Compute point on rational B-spline curve  */
       /* Input:  n,p,U,Pw,u  */
       /* Output: C  */
    span = FindSpan(n,p,u,U);
    BasisFuns(Span,u,p,U,N);
    Cw = 0.0;
for (j=0; j<=p; j++)
  Cw = Cw + N[j]*Pw[span-p+j];
C = Cw/w;   /*  Divide by weight  */
}
```
