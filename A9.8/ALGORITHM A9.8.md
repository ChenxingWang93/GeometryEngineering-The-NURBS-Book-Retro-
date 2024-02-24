``` C++
ALGORITHM A9.8
GetRemovalBndCurve(n,p,U,P,u,r,s,Br)
  {  /*  Get knot removal error bound (nonrational)  */
     /*  Input:  n,p,U,P,u,r,s  */
     /*  Output: Br  */
  ord = p+1;
  last = r-s;
  first = r-p;
  off = first-1;   /* difference in index between temp and P */
  temp[0] = P[off];     temp[last+1-off] = P[last+1];
  i = first;     j=last;
  ii = 1;     jj = last-off;
  while (j-i > 0)
  { /* Compute new control points for one removal step */
  alfi = (u-U[i])/(U[i+ord]-U[i]);
  alfj = (u-U[j])/(U[j+ord]-U[j]);
  temp[ii] = (P[i]-(1.0-alfi)*temp[ii-1])/alfi;
  temp[jj] = (P[j]-alfi*temp[jj+1])/(1.0-alfi);
  i = i+1;    ii = ii+1;
  j = j-1;    jj = jj-1;
  } /* End of while-loop */
if (j-i < 0)  /* now get bound */
  {   /* Eq.(9.82) */
  Br = Distance3D(temp[ii-1],temp[jj+1]);
  }
  else
  {   /* Eq.(9.80) */
  alfi = (u-U[i])/(U[i+ord]-U[i]);
  Br = Distance3D(P[i],alfi*temp[ii+1]+(1.0-alfi)
                                               *temp[ii-1]);
  }
}
```
