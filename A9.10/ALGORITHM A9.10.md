``` C++
ALGORITHM A9.10
GlobalCurveApproxErrBnd(m,Q,p,E,n,U,P)
  {  /*  Global curve approximation to within bound E  */
     /*  Input:  m,Q,p,E  */
     /*  Output: n,U,P  */
  Compute u_{k} and load into ub[]  (Eq.[9.5]).
  Set U and P to be the degree 1 curve interpolating the Q_{k}:
      U = {0,0,u_{1},...,u_{m-1},1,1} and P_{k} = Q_{k}.
  Initialize the e_{k}:   ek[0],...,ek[m] = 0.
n = m;

}
```
