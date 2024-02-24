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
  alfi = ()/();
  alfj = ()/();
  temp[ii] = 
  }
if
  {
  }
  else
  {
  }
}
```
