``` C++
ALGORITHM A11.1
ConstBasedSurfMod1(n,m,p,q,U,V,Pw,CList,R,M,N,A,CpInd)
  {  /*  Build the A matrix for surface constraints 为 曲面 约束 建立 一个矩阵 */
     /*  Input:  n,m,p,q,U,V,Pw,CList,R 输入 */
     /*  Output: M,N,A,CpInd 输出 */
  Loop through the list CList and count constraints
    to obtain M.
  Nmax = Max((n+1)*(m+1),R*(p+1)*(q+1));  /* Max possible N 最大 可能 N */
  for (i=0; i<M; i++)
    for (j=0; j<Nmax; j++)  B[i][j] = 0.0;
for (i=0; i<=n; i++)
  for (j=0; j<=m; j++)     Map[i][j] = -1;
bow = 0;    N = 0;   /* N is computed in this loop 在 loop 中计算 N */
for (r=1; r<=R; r++)
  {
  Extract (u,v) value from the 𝑟th list node.
  FreeCtrlPts(u,v,FreeCp);
  uspan = FindSpan(n,p,u,U);
  vspan = FindSpan(m,q,v,V);
  for (i=0; i<=p; i++)
  for (j=0; j<=q; j++)
    if (FreeCp[i][j])
      {  /* This ctrl pt is free to move 该控制点 已能 自由移动 */
      iup = i+i+uspan-p; jvp = j+vspan-q;
      if (Map[iup][jvq] == -1)
        {  /* Ctrl pt not yet in Eq. system 控制点 不在 等式 系统 中 */
        Map[iup][jvq] = N;
        CpInd[N] = jvq*(n+1)+iup;
        N = N+1;
        }
      }
  /* Compute required functions 计算 所需 函数 */
  RatDersBasisFuns(u,v,Funs);
    Loop through each type of constraint for this (u,v) and do:
      {
      Set 𝑘 and 𝑙 indicating which derivative.
      for (i=0; i<=p; i++)
        for (j=0; j<=q; j++)
          {
          alf = Map[i+uspan-p][j+vspan-q];
          if (alf >= 0)  B[brow][alf] = Funs[k][l][i][j];
          }
      brow = brow+1;
      }  /* End of loop through each type of constraint */    
    }  /* End of for-loop: r=1,...,R */
  if (M > N)  return(1);   /* system overdetermined */
  if (M == N)
    if (𝐵 singular)    return(2);
      else
      {
      𝐴 = 𝐵^{-1};  return(0);
      }
  if (𝐵𝐵^{T} singular)   return(2);
    else
    {
    𝐴 = 𝐵^{𝑇}(𝐵𝐵^{𝑇})^{-1};  return(0);
    }
}
```
