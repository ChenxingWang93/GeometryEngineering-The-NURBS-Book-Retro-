```Matlab
ALGORITHM A5.3
  SurfaceKnotIns(np,p,UP,mp,q,VP,Pw,dir,uv,k,s,r,nq,UQ,mq,VQ,Qw)
    {  /*  Surface knot insertion  */
       /*  Input:  np,p,UP,mp,q,VP,Pw,dir,uv,k,s,r  */
       /*  Output: nq,UQ,mq,VQ,Qw  */
    if (dir == U_DIRECTION)
{
load u-vector as in A5.1
copy v-vector into VQ
    /* Save the alphas */
for (j=1; j<=r; j++)
  {
  L = k-p+j;
  for (i=0; i<=p-j-s; i++)
    alpha[i][j] = (uv-UP[L+i])/(UP[i+k+1]-UP[L+i]);
  }
for (row=0; row<=mp; row++)   /* For each row do */

{
      /* Save unaltered control points */
for (i=0; i<=k-p; i++)   Qw[i][row] = Pw[i][row];
for (i=k-s; i<=np; i++)   Qw[i+r][row] = Pw[i][row];
      /* Load auxiliary control points */
for (i=0; i<=p-s; i++)   Rw[i] = Pw[k-p+i][row];
for (j=1; j<=r; j++)   /* Insert the knot r times */
  {
  L = k-p+j;    
  for (i=0; i<=p-j-s; i++)
  Rw[i] = alpha[i][j]*Rw[i+1] + (1.0-alpha[i][j])*Rw[i];
Qw[L][row] = Rw[0];
Qw[k+r-j-s][row] = Rw[p-j-s];
}
    /* Load the remaining control points */
for (i=L+1; i<k-s; i++) Qw[i][row] = Rw[i-L];
}
  }
if (dir == V_DIRECTION)
  {
  Similar code as above with u- and v-directional
    parameters switched.
  }
}
```
