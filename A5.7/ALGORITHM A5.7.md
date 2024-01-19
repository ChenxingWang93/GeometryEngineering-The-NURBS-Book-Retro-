```C++
ALGORITHM A5.7
  DecomposeSurface(n,p,U,m,q,V,Pw,dir,nb,Qw)
    {  /*  Decompose surface into Bezier patches 解构 曲面 贝塞尔补丁 */
       /*  Input:  n,p,U,m,q,V,Pw,dir 输入 */
       /*  Output: nb,Qw 输出 */
    if (dir == U_DIRECTION)
    {
    a=p;    b=p+1;
    nb=0;
    for (i=0; i<=p; i++)
      for (row=0; row<=m; row++)
        Qw[nb][i][row] = Pw[i][row];
    while (b<m)
    {
    get mult
    if ( mult<p )
      {
      get the numerator and the alfas;
      for (j=1; j<=p-mult; j++)
        {
        save = ...;
        s = ...;
        }
      for(k=p; k>=s; k--)
        {
        get alfa;
        for ( row ... )
          Qw[nb][k][row] = alfa*Qw[nb][k][row]
                             +(1.0-alfa)*Qw[nb][k-1][row];
        }
      if ( b<m )
        for ( row ... )
          Qw[nb+1][save][row] = Qw[nb][p][row];
      }
    }
        nb=nb+1;
        if ( b<m )
          {
          for (i=p-mult; i<=p; i++)
            for ( row ...  )
              Qw[nb][i][row] = Pw[b-p+i][row];
          a = b;    b = b+1;
          }
        }
      }
    if (dir == V_DIRECTION)
      {
      /* Similar code as above with u- and v-directional
        parameters switched */
      }
    }
```
