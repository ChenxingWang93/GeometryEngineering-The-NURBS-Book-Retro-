``` C++
ALGORITHM A11.1
ConstBasedSurfMod1(n,m,p,q,U,V,Pw,CList,R,M,N,A,CpInd)
  {  /*  Build the A matrix for surface constraints  */
     /*  Input:  n,m,p,q,U,V,Pw,CList,R  */
     /*  Output: M,N,A,CpInd  */
  Loop through the list CList and count constraints
    to obtain M.
  Nmax = Max((n+1)*(m+1),R*(p+1)*(q+1));  /* Max possible N */
  for (i=0; i<M; i++)
    for (j=0; j<Nmax; j++)  B[i][j] = 0.0;
for (i=0; i<=n; i++)
  for (j=0; j<=m; j++)     Map[i][j] = -1;
bow = 0;    N = 0;   /* N is computed in this loop */
}
```
