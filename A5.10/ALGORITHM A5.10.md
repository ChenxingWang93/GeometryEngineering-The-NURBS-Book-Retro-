``` C++
ALGORITHM A5.10
DegreeElevateSurface(n,p,U,m,q,V,Pw,dir,t,nh,Uh,mh,Vh,Qw)
  {  /*  Degree elevate a surface t times.  */
     /*  Input:  n,p,U,m,q,V,Pw,dir,t  */
     /*  Output: nh,Uh,mh,Vh,Qw  */
if (dir == U_DIRECTION)
  {
  allocate memory for Bezier and NextBezier strips;
  initialize knot vectors and first row of control points;
  initialize Bezier strip;
  set variables;
  while(b<m)
    {
    get multiplicity;
    get ub, r, oldr, etc;
    save alfas
    }
  for (j=0; j<=m; j++)
    {
    insert knot;
    degree elevate Bezier row[j];
    remove knot;
    save new control points;
    initialize for next pass through;
    }
  update knot vector;
  update variables;
  get end knots;
  }
if (dir == U_DIRECTION)
  {
  /* Similar code as above with u- and v-directional
    parameters switched */
  }
}
```
