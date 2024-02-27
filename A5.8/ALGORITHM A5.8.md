```C++
ALGORITHM A5.8
RemoveCurveKnot(n,p,U,Pw,u,r,s,num,t)
  {  /*  Remove knot u(index r) num times. 移除 节点 u */
     /*  Input: n,p,U,Pw,u,r,s,num 输入 */
     /*  Output:t, new knots & ctrl pts in U & Pw 输出 */
  m = n+p+1;
  ord = p+1;
  fout = (2*r-s-p)/2;  /* First control point out 第 1 控制点 出 */
  last = r-s;
  first = r-p;
  for (t=0; t<num; t++)
{ /* This loop is Eq.(5.28) */
off = first-1;  /* Diff in index between temp and P temp & P 之间 索引的不同 */
temp[0] = Pw[off];   temp[last+1-off] = Pw[last+1];
i = first;     j=last;
ii = 1;     jj = last-off;
remflag = 0;
while (j-i > t)
  { /* Compute new control points for one removal step 为 1 个移除的步骤 计算 新的控制点  */
  alfi = (u-U[i])/(U[i+ord+t]-U[i]);
  alfj = (u-U[j-t])/(U[j+ord]-U[j-t]);

  temp[ii] = (Pw[i]-(1.0-alfi)*temp[ii-1])/alfi;
  temp[jj] = (Pw[j]-alfj*temp[jj+1])/(1.0-alfj);
  i = i+1;    ii = ii+1;
  j = j-1;    jj = jj-1;
  } /* End of while-loop 结束 while 循环 */
if (j-i < t)  /* Check if knot removable 检查 是否 结点 可移除 */
  {
  if (Distance4D(temp[ii-1],temp[jj+1]) <= TOL)
    remflag = 1;
  }
else
  {
  alfi = (u-U[i]/U[i+ord+t]-U[i]);
  if (Distance4D(Pw[i],alfi*temp[ii+t+1]
                           +(1.0-alfi)*temp[ii-1]) <= TOL)
    remflag = 1;
  }
if (remflag == 0)   /* Cannot remove any more knots 不能移除 更多 结点 */
  break;           /* Get out of for-loop 跳出 for 循环 */
else
    {   /* successful removal. Save new cont.pts. 成功 移除！保存 控制点 */
    i = first;   j = last;
    while (j-i > t)
      {
      Pw[i] = temp[i-off];   Pw[j] = temp[j-off];
      i = i+1;    j = j-1;
      }
    }
  first = first-1;    last = last+1;
  } /* End of for-loop 结束 for 循环 */
if (t == 0)   return;

for (k=r+1; k<=m; k++) U[k-t] = U[k];  /* Shift knots 偏移 结点 */
j = fout;   i=j;   /* Pj thru Pi will be overwritten */
for (k=1; k<t; k++)
  if (Mod(k,2) == 1)    /* k modulo 2 */
    i = i+1;    else    j = j-1;
for (k=i+1; k<=n; k++)    /* Shift 偏移 */
  {  Pw[j] = Pw[k];   j = j+1;  }
return;
}
```
