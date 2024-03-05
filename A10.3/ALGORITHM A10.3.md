``` C++
ALGORITHM A10.3
  GordonSurface(Ck,Cl,ul,vk,r,s,pl,ql,pt,qt,n,m,p,q,U,V,Pij)
    {  /*  Create Gordon surface.  */
       /*  Input:  Ck,Cl,ul,vk,r,s,pl,ql,pt,qt  */
       /*  Output: n,m,p,q,U,V,Pij  */
    pc = degree of the Ck curves.
    qc = degree of the Cl curves.
    Choose a suitable U1 and loft to obtain L1(u,v)
      (degree (pl,qc)).
    Choose a suitable V1 and loft to obtain L2(u,v)
  (degree (pc,ql)).
Choose suitable UT and VT, and interpolate to obtain T(u,v)
  (degree (pt,qt)).
p = max(pc,pl,pt).
q = max(qc,ql,qt).
Degree elevate L1(u,v), L2(u,v), and T(u,v) to (p,q)
  as necessary.
U = Merge(U1,U2,UT).
V = Merge(V1,V2,VT).
Refine knot vectors of L1(u,v), L2(u,v) and T(u,v)
  as necessary.
n = (number of u-knots)-p-2.
m = (number of v-knots)-q-2.
Compute surface control points Pij by Eq.(10.33).
}
```
