``` C++
ALGORITHM A5.1
  CurveKnotIns(np,p,UP,Pw,u,k,s,r,nq,UQ,Qw)
    {  /*  Compute new curve from knot insertion 从 结点插入 计算🧮新曲线 */
       /*  Input:  np,p,UP,Pw,u,k,s,r 输入 */
       /*  output: nq,UQ,Qw 输出 */
    mp = np+p+1;
    nq = np+r;
       /*  Load new knot vector  */
    for(i=0; i<=k-p; i++)  Qw[i] = Pw[i];
    for(i=k-s; i<=np; i++)  Qw[i+r] = Pw[i];
    for(i=0; i<=p-s; i++)  Rw[i] = Pw[k-p+i];
    for(j=1; j<=r; j++)   /* Insert the knot r times */
      {
      L = k-p+j;
      for(i=0; i<=p-j-s; i++)
        {
        alpha = (u-UP[L+i])/(UP[i+k+1]-UP[L+i]);
        Rw[i] = alpha*Rw[i+1] + (1.0-alpha)Rw[i];
        }
      Qw[L] = Rw[0];
      Qw[k+r-j-s] = Rw[p-j-s];
      }
    for(i=L+1; i<k-s; i++)  /* Load remaining control points */
      Qw[i] = Rw[i-L];
    }
```
