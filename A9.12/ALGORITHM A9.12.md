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
  {  /* Noncoplanar case */
  Pd = Intersection of 𝜋 with Line(Q[k+ks],Te);
  Pc = Intersection of Line (Q[ks],Q[ke]-Q[ks]) with
      Line(Pd,Ts);
  gama = Distance3D(Pc,Q[ke])/Distance3D(Q[ks],Q[ke]);
  if (gamma < 0.0 || gamma > 1.0)  return(0);
  Use Newton iteration to solve Eq.(9.102) for uh[k].
  if (uh[k] < 0.0 || uh[k] > 1.0)   return(0);
    else
    }
    a = Distance3D(Pc,Pd);     b = -Distance3D(Pd,Q[k+ks]);
    Evaluate Bernstein polynomials and use Eq.(9.99)
      to get alfak[k] and betak[k].
    }
  }
}  /* End of for-loop: k=1,...,dk-1 */
  /* Step 2: average the 𝛼_{𝒌}𝑠 */
alpha = beta = 0.0;
for (k=1; k<dk; k++)
  {  alpha = alpha+alfak[k];   beta = beta+betak[k];
alpha = alpha/(dk-1);    beta = beta/(dk-1);
P1 = Q[ks]+alpha*Ts;    P2 = Q[ke]+beta*Te;
    /* Step 3: check deviations */
  }
for (k=1; k<dk; k++)
  {
  u = uh[k];
  if (Eq.[9.110] less than E)   continue;
    else
    {  /* Must do Newton iterations. u is start value */
    Project Q[k+ks] to curve to get error ek.
    if (ek > E)   break;
    }
  }
if (k == dk)   return(1);   /* segment within tolerance */
  else         return(0);   /* not within tolerance */
}
```
