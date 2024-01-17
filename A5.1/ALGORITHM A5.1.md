```Matlab
ALGORITHM A5.1
  CurveKnotIns(np,p,UP,Pw,u,k,s,r,nq,UQ,Qw)
    {  /*  Compute new curve from knot insertion  */
       /*  Input:  np,p,UP,Pw,u,k,s,r   */
       /*  output: nq,UQ,Qw  */
    mp = np+p+1;
    nq = np+r;
       /*  Load new knot vector  */
    for(i=0; i<=k-p; i++)  Qw[i] = Pw[i];
    for(i=k-s; i<=np; i++)  Qw[i+r] = Pw[i];
    for(i=0; i<=p-s; i++)  Rw[i] = Pw[k-p+i];
    for(j=1; j<=r; j++)   /* Insert the knot r times */
      {
  }
}
```
