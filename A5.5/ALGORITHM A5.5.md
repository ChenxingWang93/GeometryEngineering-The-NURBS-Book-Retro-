```C++
ALGORITHM A5.5
  RefineKnotVectSurface(n,p,U,m,q,V,Pw,X,r,dir,Ubar,Vbar,Qw)
    {  /*  Refine surface knot vector 精炼 曲面 结点 向量 */
       /*  Input:  n,p,U,m,q,V,Pw,X,r,dir 输入 */
       /*  Output: Ubar,Vbar,Qw 输出 */
    if (dir == U_DIRECTION)
      {
      find indexes a and b;
      initialize Ubar;
      copy V into Vbar;
                /* Save unaltered ctrl pts 保存 不变的 控制点 */
      for (row=0; row<=m; row++)
        {
        for (k=0; k<=a-p; k++)  Qw[k][row] = Pw[k][row];
        for (k=b-1; k<=n; k++)  Qw[k+r+1][row] = Pw[k][row];
        }
      for (j=r; j>=0; j--)
        {
    while (X[j]<=U[i] && i>a)
      {
      compute Ubar;
      for ( row ... )   Qw[k-p-1][row] = Pw[i-p-1][row];
      k = k-1;   i = i-1;
      }
    for ( row ... )    Qw[k-p-1][row] = Qw[k-p][row];
    for (l=1; l<=p; l++)
      {
      ind = k-p+l;
      compute alfa;
      if (abs(alfa) == 0.0)
        for ( row ... )    Qw[ind-1][row] = Qw[ind][row];
      else
            {
            compute alfa;
            for ( row ...  )
              Qw[ind-1][row] =
                 alfa*Qw[ind-1][row]+(1.0-alfa)*Qw[ind][row];
            }
          }
        Ubar[k] = X[j];   k = k-1;
        }
      }
    if (dir == V_DIRECTION)
      {
      /* Similar code as above with u and v directional
        parameters switched */
      }
    }
```