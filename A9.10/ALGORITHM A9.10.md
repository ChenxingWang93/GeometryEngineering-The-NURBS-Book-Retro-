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
for (deg=1; deg<=p; deg++)
  {
  RemoveKnotsBoundCurve(n,p,U,P,ub,ek,E,nh,Uh,Ph);
  if (deg == p)   break;
  Let U be the knot vector obtained by degree elevating Uh
      from deg to deg+1 (increase all multiplicities by 1).
      Reset n (Eq.[5.32]).
  Fit a least squares curve to the Q_{k}, using n, ub, degree
      deg+1, and knot vector U; this yields new ctrl pts P.
  Using Eqs.(6.4),(6.5), project all Q_{k} to current curve
      to get R_{k} = C(u_{k}).  Then update ek[] and ub[]:
      e_{k} = |Q_{k},R_{k}| and u_{k} = u_{k}.
  }  /* End of for-loop */
if (n == nh)   return(n,U,P);
Set U = Uh and n = nh, and fit one final time with degree p
    and knots U.
Project the Q_{k} and update ek[] and ub[].
RemoveKnotsBoundCurve(n,p,U,P,ub,ek,E,nh,Uh,Ph);
return(nh,Uh,Ph);
}
```
