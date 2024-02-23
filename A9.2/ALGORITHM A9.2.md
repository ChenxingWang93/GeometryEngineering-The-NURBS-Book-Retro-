``` C++
ALGORITHM A9.2
  SolveTridiagonal(n,Q,U,P)
    {  /*  Solve tridiagonal system for C2 cubic spline  */
       /*  Input:  n,Q,U,P[0],P[1],P[n+1],P[n+2]  */
       /*  Output: P  */
    for (i=3; i<n; i++)   R[i] = Q[i-1];
    BasisFuns(4,U[4],3,U,abc);
    den = abc[1];
    P[2] = (Q[1]-abc[0]*P[1])/den;
    for (i=3; i<n; i++)
      {
  dd[i] = abc[2]/den;
  BasisFuns(i+2,U[i+2],3,U,abc);
  den = abc[1]-abc[0]*dd[i];
  P[i] = (R[i]-abc[0]*P[i-1])/den;
  }
dd[n] = abc[2]/den;
BasisFuns(n+2,U[n+2],3,U,abc);
den = abc[1]-abc[0]*dd[n];
P[n] = (Q[n-1]-abc[2]*P[n+1]-abc[0]*P[n-1])/den;
for (i=n-1; i>=2; i--)   P[i] = P[i]-dd[i+1]*P[i+1];
}
```
