```C++
ALGORITHM A5.11
DegreeReduceCurve(n,p,U,Qw,nh,Uh,Pw)
  {  /*  Degree reduce a curve from p to p-1.  */
     /*  Input:  n,p,U,Qw  */
     /*  Output: nh,Uh,Pw  */
  ph = p-1;   mh = ph;   /* Initialize some variables 初始化 一些 变量 */
  kind = ph+1;   r = -1;   a = p;
  b = p+1;   cind = 1;   mult = p;
  m = n+p+1;   Pw[0] = Qw[0];
  for (i=0; i<=ph; i++)  /* Compute left end of knot vector */
    Uh[i] = U[0];
  for (i=0; i<=p; i++)   /* Initialize first Bezier segment */
    bpts[i] = Qw[i];
for (i=0; i<m; i++)   /* Initialize error vector */
  e[i] = 0.0;
    /* Loop through the knot vector */
while (b < m)
  {  /* First compute knot multiplicity */
  i = b;
  while (b < m && U[b] == U[b+1])   b = b+1;
  mult = b-i+1;   mh = mh+mult-1;
  oldr = r;   r = p-mult;
  if (oldr > 0)  lbz = (oldr+2)/2;  else  lbz = 1;
      /* Insert knot U[b] r times */
  if (r > 0)
    {
    numer = U[b]-U[a];
    for (k=p; k>=mult; k--)
    alphas[k-mult-1] = numer/(U[a+k]-U[a]);
  for (j=1; j<=r; j++)
    {
    save = r-j;   s = mult+j;
    for (k=p; k>=s; k--)
      bpts[k] = alphas[k-s]*bpts[k]
                            + (1.0-alphas[k-s])*bpts[k-1];
    Nextbpts[save] = bpts[p];
    }
  }
    /* Degree reduce Bezier segment */
BezDegreeReduce(bpts,rbpts,MaxErr);
e[a] = e[a]+MaxErr;
if (e[a] > TOL)

  return(1);    /* Curve not degree reducible */
    /* Remove knot U[a] oldr times */
if (oldr > 0)
  {
  first = kind;   last = kind;
  for (k=0; k<oldr; k++)
    {
    i = first;   j = last;   kj = j-kind;
    while (j-i > k)
      {
      alfa = (U[a]-Uh[i-1])/(U[b]-Uh[i-1]);
      beta = (U[a]-Uh[j-k-1])/(U[b]-Uh[j-k-1]);
      Pw[i-1] = (Pw[i-1]-(1.0-alfa)*Pw[i-2])/alfa;
      rbpts[kj] = (rbpts[kj]-beta*rbpts[kj+1])/(1.0-beta);
      i = i+1;   j = j-1;   kj = kj-1;
      }
    /* Compute knot removal error bounds (Br) */
  if (j-i < k) Br = Distance4D(Pw[i-2],rbpts[kj+1]);
    else
    {
    delta = (U[a]-Uh[i-1])/(U[b]-Uh[i-1]);
    A = delta*rbpts[kj+1]+(1.0-delta)*Pw[i-2];
    Br = Distance4D(Pw[i-1],A);
    }
      /* Update the error vector */
  K = a+oldr-k;    q = (2*q-k+1)/2;
  L = K-q;
  for (ii-L; ii<=a; ii++)
    {  /* These knot spans were affected */
    e[ii] = e[ii] + Bar;
    if (e[ii] > TOL)
      return(1);  
    }
  first = first-1;    last = last+1;    
    }/* End for (k=0; k<oldr; k++) loop*/
cind = i-1;
}  /* End if (oldr > 0) */
  /* Load knot vector and control points */
if(a != p)
  for (i=0; i<ph-oldr; i++)
    {  Uh[kind] = U[a];   kind = kind+1;  }
for (i=lbz; i<=ph; i++)
  {  Pw[cind] = rbpts[i];   cind = cind+1;  }
    /* Set up for next pass through */

  if (b < m)
    {
    for (i=0; i<r; i++)    bpts[i] = Nextrbpts[i];
    for (i=r; i<=p; i++)   bpts[i] = Qw[b-p+i];
    a = b;    b = b+1;
    }
  else
    for (i=0; i<=ph; i++)   Uh[kind+i] = U[b];
}    /* End of while (b < m) loop */
nh = mh-ph-1;
return(0);
}
```
