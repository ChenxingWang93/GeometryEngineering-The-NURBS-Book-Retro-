``` C++
ALGORITHM A9.3
  SurfMeshParams(n,m,Q,uk,vl)
    {  /*  Compute parameters for  */
       /*        global surface interpolation  */
       /*  Input:  n,m,Q  */
       /*  Output: uk,vl  */
    /*  First get the uk */
    num = m+1;   /* number of nondegenerate rows 不退化 行的数量 */
    uk[0] = 0.0;    uk[n] = 1.0;
    for (k=1; k<n; k++)   uk[k] = 0.0;
    for (l=0; l<=m; l++)
{
total = 0.0;   /* total chord length of row */
for (k=1; k<=n; k++)
  {
  cds[k] = Distance3D(Q[k][l],Q[k-1][l]);
  total = total + cds[k];
  }
if (total == 0.0)   num = num-1;
    else
      {
      d = 0.0;
      for (k=1; k<n; k++)
        {
        d = d + cds[k];
        uk[k] = uk[k] + d/total;
        }
      }
  }
if (num == 0)   return(error);
for (k=1; k<n; k++)   uk[k] = uk[k]/num;
   /* Now do the same for vl */ 
}
```
