``` C++
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
        of 𝐶(𝑢)
      }
}
```
