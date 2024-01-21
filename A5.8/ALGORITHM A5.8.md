```C++
ALGORITHM A5.8
RemoveCurveKnot(n,p,U,Pw,u,r,s,num,t)
  {  /*  Remove knot u(index r) num times. 移除 节点 u */
     /*  Input: n,p,U,Pw,u,r,s,num 输入 */
     /*  Output:t, new knots & ctrl pts in U & Pw 输出 */
  m = n+p+1;
  ord = p+1;
  fout = (2*r-s-p)/2;  /* First control point out */
  last = r-s;
  first = r-p;
  for (t=0; t<num; t++)
{ /* This loop is Eq.(5.28) */
off = first-1;  /* Diff in index between temp and P */
temp[0] = Pw[off];   temp[last+1-off] = Pw[last+1];
i = first;     j=last;
ii = 1;     jj = last-off;
remflag = 0;
while (j-i > t)
  {}

  }
```
