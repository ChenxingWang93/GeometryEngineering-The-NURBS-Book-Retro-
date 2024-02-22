``` C++
ALGORITHM A7.3
  MakeOpenConic(P0,T0,P2,T2,P,n,U,Pw)
    {  /*  Construct open conic arc in 3D  */
       /*  Input:  P0,T0,P2,T2,P  */
       /*  Output: n,U,Pw  */
    MakeOneArc(P0,T0,P2,T2,P,P1,w1);
    if (w1 <= -1.0)     /* parabola or hyperbola 抛物线与双曲线 */
      return(error);    /* outside convex hull 凸包外 */
    if (w1 >= 1.0)   /* classify type & number of segments */
      nsegs = 1;     /* hyperbola or parabola, one segment */
      else
  {   /* ellipse, determine number of segments */
  if (w1 > 0.0 && Angle(P0,P1,P2) > 60.0)   nsegs = 1;
  else
  if (w1 < 0.0 && angle(P0,P1,P2) > 90.0)   nsegs = 4;
    else       nsegs = 2;
  }
n = 2*nsegs;
j = 2*nsegs+1;
for (i=0; i<3; i++)   /* load end knots */
  {  U[i] = 0.0;    U[i+j] = 1.0;  }
Pw[0] = P0;   Pw[n] = P2;   /* load end ctrl pts */
if (nsegs == 1)
  {
  Pw[1] = w1*P1;
  return;
  }
SplitArc(P0,P1,w1,P2,Q1,S,R1,wqr);
if (nsegs == 2)
  {
  Pw[2] = S;
  Pw[1] = wqr*Q1;    Pw[3] = wqr*R1;
  U[3] = U[4] = 0.5;
  return;
  }

  /* nsegs == 4 */
Pw[4] = S;
w1 = wqr;
SplitArc(P0,Q1,w1,S,HQ1,HS,HR1,wqr);
Pw[2] = HS;
Pw[1] = wqr*HQ1;    Pw[3] = wqr*HR1;
SplitArc(S,R1,w1,P2,HQ1,HS,HR1,wqr);
Pw[6] = HS;
Pw[5] = wqr*HQ1;    Pw[7] = wqr*HR1;
for (i=0; i<2; i++)   /* load the remaining knots */
  {
  U[i+3] = 0.25;   U[i+5] = 0.5;   U[i+7] = 0.75;
  }
return;
}
```
