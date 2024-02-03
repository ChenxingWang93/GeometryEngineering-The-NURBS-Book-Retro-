``` C++
ALGORITHM A8.1 
  MakeRevolveSurf(S,T,theta,m,Pj,wj,n,U,Pij,wij)
    {  /*  Create NURBS surface of revolution  */
       /*  Input:  S,T,theta,m,Pj,wj  */
       /*  Output: n,U,Pij,wij  */
    if (theta <= 90.0)   narcs = 1;
      else
        if (theta <= 180.0)
          {  narcs = 2;   U[3] = U[4] = 0.5;  }
          else
if (theta <= 270.0)
  {
  narcs = 3;
  U[3] = U[4] = 1.0/3.0;
  U[5] = U[6] = 2.0/3.0;
  }
  else
  {
          narcs = 4;
          U[3] = U[4] = 0.25;
          U[5] = U[6] = 0.5;
          U[7] = U[8] = 0.75;
          }
dtheta = theta/narcs;
j = 3 + 2*(narcs-1);   /* load end knots */
for (i=0; i<3; j++, i++)  
    }
```
