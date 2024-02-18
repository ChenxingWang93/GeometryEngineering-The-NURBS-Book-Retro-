```C++
ALGORITHM A5.9
DegreeElevateCurve(n,p,U,Pw,t,nh,Uh,Qw)
  {  /*  Degree elevate a curve t times. 梯度 提升 t 次 */
     /*  Input:  n,p,U,Pw,t 输入 */
     /*  Output: nh,Uh,Qw 输出 */
  m = n+p+1;
  ph = p+t;    ph2 = ph/2;
   /* Compute Bezier degree elevation coefficients 计算🧮 贝塞尔 梯度 提升 系数 */
  bezalfs[0][0] = bezalfs[ph][p] = 1.0;
  for (i=1; i<=ph2; i++)
    {
    inv = 1.0/Bin(ph,i);
    mpi = Min(p,i);


    for (j=Max(0,i-t); j<=mpi; j++)
      bezalfs[i][j] = bezalfs[ph-i][p-j];
    }
  mh = ph;   kind = ph + 1;
  r = -1;   a = p;
  b = p+1;   cind = 1;
  ua = U[0];
  Qw[0] = Pw[0];
  for (i=0; i<=ph; i++)   Uh[i] = ua;
    /* Initialize first Bezier seg 初始化 第一个☝️ 贝塞尔 片段 */
  for (i=0; i<=ph; i++)  bpts[i] = Pw[i];
  while (b < m)    /* Big loop thru knot vector 结点 向量 大循环 ♻️ */
    {
  i = b;
  while (b < m && U[b] == U[b+1])    b = b+1;
  mul = b-i+1;
  mh = mh+mul+t;
  ub = U[b];
  oldr = r;    r = p-mul;
     /* Insert knot u(b) r times 插入 结点 knot u(b) r 次 */
  if (oldr > 0)   lbz = (oldr+2)/2;    else   lbz = 1;


if (r > 0)  rbz = ph-(r+1)/2;   else   rbz = ph;
if (r > 0)
  {  /* Insert knot to get Bezier segment 插入 结点 获得 贝塞尔 片段 */
  numer = ub-ua;
  for (k=p; k>mul; k--)
    alfs[k-mul-1] = numer/(U[a+k]-ua);
  for (j=1; j<=r; j++)
    {
    save = r-j;   s = mul+j;
    for (k=p; k>=s; k--)
      {
      bpts[k] = alfs[k-s]*bpts[k] +
                (1.0-alfs[k-s])*bpts[k-1];
      }
    Nextbpts[save] = bpts[p];
    }
  }  /* End of "insert knot" “插入结点” */
for (i=lbz; i<=ph; i++)   /* Degree elevate Bezier 贝塞尔曲线 度数 提升*/
  {  /* Only points lbz,...,ph are used below 只有 点 lbz,...,ph 被使用*/
  ebpts[i] = 0.0;
  mpi = Min(p,i);
  for (j=Max(0,i-t); j<=mpi; j++)
    ebpts[i] = ebpts[i] + bezalfs[i][j]*bpts[j];
  }  /* End of degree elevating Bezier */
if (oldr > 1)
  {  /* Must remove knot u=U[a] oldr times */
  first = kind-2;   last = kind;
  den = ub-ua;

bet = (ub-Uh[kind-1])/den;
for (tr=1; tr<oldr; tr++)
  {  /* Knot removal loop */
  i = first;    j = last;    kj = j-kind+1;
  while (j-i > tr)  /* Loop and compute the new */
    {   /* control points for one removal step */
    if (i < cind)
      {
      alf = (ub-Uh[i])/(ua-Uh[i]);
      Qw[i] = alf*Qw[i] + (1.0-alf)*Qw[i-1];
      }
    if( j >= lbz)
      {
      if( j-tr <= kind-ph+oldr )
        {
        gam = (ub-Uh[j-tr])/den;
        ebpts[kj] = gam*ebpts[kj]+(1.0-gam)*ebpts[kj+1];
        }
        else
        {
        ebpts[kj] = bet*ebpts[kj]+(1.0-bet)*ebpts[kj+1];
        {
      }
    i = i+1;   j = j-1;   kj = kj-1;
    }
  first = first-1;    last = last+1;
  }
}  /* End of removing knot, u=U[a] */
if (a != p)/* Load the knot ua */
  for(i=0; i<=ph-oldr; i++)

     {  Uh[kind] = ua;    kind = kind+1;  }
  for(j=lbz; j<=rbz; j++)   /* Load ctrl pts into Qw */
    { Qw[cind] = ebpts[j];    cind = cind+1;  }
  if (b < m)
    {  /* Set up for next pass thru loop */
    for (j=0; j<r; j++)    bpts[j] = Nextbpts[j];
    for (j=r; j<=p; j++)   bpts[j] = Pw[b-p+j];
    a = b;   b = b+1;   ua = ub;
    }
    else
        /* End knot */
      for (i=0; i<=ph; i++)  Ub[kind+i] = ub;
}    /* End of while-loop (b < m) */
nh = mh-ph-1;
}
```
