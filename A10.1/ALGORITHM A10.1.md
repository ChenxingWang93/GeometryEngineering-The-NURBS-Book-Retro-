``` C
ALGORITHM A10.1
  SweepSurface1(T,C,Bv,sv,K,V,Pw)
    {  /*  Swept surface.  Trajectory interpolated.  */
       /*  Input:  T,C,Bv,sv,K  */
       /*  Output: V,Pw  */
    q = degree of 𝐓(𝑣).
    ktv = number of knots of 𝐓(𝑣).
    nsect = K+1;
    if (ktv <= nsect+q)
      {  /* Must refine 𝐓(𝑣)'s knot vector */
      m = nsect+q-ktv+1;
      Insert m more knots into 𝐓(𝑣)'s knot vector.  Locations
        are not critical, recursively insert at the midpoint of
        the longest span will do.  New control points do not
        have to be computed, as we only require a refined
        set of knots.
      The resulting knot vector V is inherented by Ŝ(𝑢,𝑣).
      }
      else
      {  /* 𝐓(𝑣)'s knot vector will do */
      V = 𝐓(𝑣)'s knot vector.
      if (ktv > nsect+q+1)   /* Must increase number of */
        nsect = ktv-q-1;     /* instances of 𝐶(𝑢) */
      }
    ṽ_{0} = 𝐓(𝑣)'s minimum parameter value.
    ṽ_{nsect-1} = 𝐓(𝑣)'s maximum parameter value.
    for (k=1; k<nsect-1; k++)        /* Compute parameters by */
      ṽ_{k} = (𝚟_{k+1}+...+𝚟_{k+q})/q/* averaging knots */
    for (k=0; k<nsect; k++)
      {  /* Transform and position section control points  */
      Let 𝑸_{𝑖} and 𝜔_{𝑖} be the control points and weights
        of 𝐶(𝑢), 𝑖 = 𝟶,...,𝑛.
      Scale the control points 𝑸_{𝑖} by sv.
      Compute {𝒐,𝒙,𝒚,𝒛}(ṽ_{k}) from Eqs.(𝟷𝟶.𝟸𝟶)-(𝟷𝟶.𝟸𝟸).
      Compute the transformation matrix 𝑨(ṽ_{k}) transforming the
        global system into {𝒐,𝒙,𝒚,𝒛}(ṽ_{k}).
      Apply 𝑨(ṽ_{k}) to the scaled 𝑸_{𝑖}.
      Reapply the weights 𝑤_{𝑖}, and denote the resulting
        weighted control points by 𝑸_{𝒌,𝒊}^{𝑤}.
      }
  Determine ṽ_{0},...,ṽ_{k}, the v-parameters for the
    v-directional interpolations (Eqs.[𝟷𝟶.𝟾] or [𝟷𝟶.𝟷𝟺]).
  Given 𝑞 and the ṽ_{k}, compute the knot vector 𝑽 by averaging
    (Eq.[𝟿.𝟾]).
  for (i = 0 i<=n; i++)
    {
    interpolate across 𝑸_{𝟶,𝒊}^{𝑤},...,𝑸_{nsect-1,𝒊}^{𝑤} to obtain 𝑷_{𝟶,𝒊}^{𝑤},...,𝑷_{nsect-1,𝒊}^{𝑤}.
    }
}
```
