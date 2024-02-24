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
      /* Now set up arrays N,W,S,T,M */
j = 0;   /* current index into I[] */
mu2 = 0;   mc2 = 0;   /* counters up to mu and mc */
for (i=0; i<=r; i++)
  {
  span = FindSpan(n,p,ub[i],U);
  dflag = 0;
  if (j <= s)
    if (i == I[j])   dflag = 1;
if (dflag == 0)   BasisFuns(span,ub[i],p,U,funs);
  else            DersBasisFuns(span,ub[i],p,1,U,funs);
if (Wq[i] > 0.0)
  {  /* Unconstrained point */
  W[mu2] = Wq[i];
  Load the mu2th row of N[][] from funs[0][];
  S[mu2] = W[mu2]*Q[i];
  mu2 = mu2+1;
  }
  else
  {  /* Constrained point */
  Load the mc2th row of M[][] from funs[0][];
  T[mc2] = Q[i];
  mc2 = mc2+1;
  }

}
}
```
