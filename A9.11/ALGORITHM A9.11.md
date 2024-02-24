``` C++
ALGORITHM A9.11
  FitWithConic(ks,ke,Q,Ts,Te,E,Rw)
    {  /*  Fit to tolerance E with conic segment  */
       /*  Input:  ks,ke,Q,Ts,Te,E  */
       /*  Output: Rw  */
    if (ke-ks == 1)
      {  /* No interior points to interpolate */
      Fit an interpolating segment as in Section 9.3.3.
      return(1);
      }
    i = Intersect3DLines(Q[ks],Ts,Q[ke],Te,alf1,alf2,R);
    if (i != 0)
      {  /* No intersection */
      if (Q_{k_{s}},...,Q_{k_{e}} not collinear)  return(0);
    else
      {
      Rw = (Q[ks]+Q[ke])/2.0;
      return(1);
      }
  }
if (alf1 <= 0.0 || alf2 >= 0.0)    return(0);
s = 0.0;    V = Q[ke]-Q[ks];
for (i=ks+1; i<=ke-1; i++)
  {  /* Get conic interpolating each interior point */
  V1 = Q[i] - R;
  j = Intersect3DLine(Q[ks],V,R,V1,alf1,alf2,dummy);
  if (j != 0 || alf1 <= 0.0 || alf1 >= 1.0 || alf2 <= 0.0)
    return(0);
  Compute the weight wi.   /* Algorithm A7.2 */
  s = s + wi/(1.0+wi);
  }
s = s/(ke-ks-1);    w = s/(1.0-s);
if (w < WMIN || w > WMAX)   /* system bounds on weights */
  return(0);
Create Bezier segment with Q[ks],R,Q[ke] and w.
for (i=ks+1; i<=ke-1; i++)
  {
  Project Q[i] onto the Bezier segment.
  if (distance > E)   return(0);
  }
Rw = w*R;
return(1);
}
```
