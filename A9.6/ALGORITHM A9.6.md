``` C++
ALGORITHM A9.6
  WCLeastSquaresCurve(Q,r,Wq,D,s,I,Wd,n,p,U,P)
    {  /*  Weighted & constrained least squares curve fit   */
       /*  Input:  Q,r,Wq,D,s,I,Wd,n,p  */
       /*  Output: U,P  */
    ru = -1;    rc = -1;
    for (i=0; i<=r; i++)
      if (Wq[i] > 0.0)   ru = ru+1;
        else             rc = rc+1;
    su = -1;    sc = -1;
for (j=0; j<=s; j++)
  if (Wd[j] > 0.0)   su = su+1;
    else             sc = sc+1;
mu = ru+su+1;    mc = rc+sc+1;
if (mc >= n || mc+n >= mu+1)      return(error);
Compute and load parameters u_{k} into ub[] (Eq.[9.5]);
Compute and load the knots into U[] (Eqs.[9.68],[9.69]);
      /* Now set up array N,W,S,T,M */

}
```
