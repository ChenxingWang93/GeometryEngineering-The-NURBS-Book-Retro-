``` C++
ALGORITHM A9.12
  FitWithCubic(ks,ke,Q,Ts,Te,E,P1,P2)
    {  /*  Fit to tolerance E with cubic segment  */
       /*  Input:  ks,ke,Q,Ts,Te,E  */
       /*  Output: P1,P2  */
    if (ke-ks == 1)
      {  /* No interior points to interpolate */
      Compute 𝛼 and 𝛽 by Eqs.(9.93),(9.94).
      Set P_{1} = Q_{k_{s}} + 𝛼T_{s}
      and P_{2} = Q_{k_{e}} + 𝛽T_{e}
      return(1);
      }
    dk = ke-ks;
    line = Collinear(dk+1,Q[ks]);
    if (line == 1)
  {
  P1 = (2.0*Q[ks]+Q[ke])/3.0;
  P2 = (Q[ks]+2.0*Q[ke])/3.0;
  return(1);
  }
for (k=1; k<dk; k++)
  {  
  Get plane 𝜋 defined by Q[ks],Q[ke],Ts.
  if (Line(Q[k+ks],Te) lies in 𝜋)
    {  /* Coplanar case */
    Compute u_{k} by Eq.(9.103) and load into uh[k].
    Set up Eqs.(9.107) and (9.108) and solve for 𝛼_{𝒌} and 𝛽_{𝒌};
        (by least squares).
    if (𝛼_{𝒌}>0 && 𝛽_{𝒌}<0)
      {
      alfak[k] = 𝛼_{𝒌}; betak[k] = 𝛽_{𝒌};
      }
      else
        return(0);
    }
    else
  {
  }
  }
}
```
