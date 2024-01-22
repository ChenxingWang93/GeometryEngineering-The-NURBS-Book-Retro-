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
    /* Initialize first Bezier seg */
  for (i=0; i<=ph; i++)  bpts[i] = Pw[i];
  while (b < m)    /* Big loop thru knot vector */
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
  {  /* Insert knot to get Bezier segment */
  numer = ub-ua;
  for (k=p; k>mul; k--)
    alfs[k-mul-1] = numer/(U[a+k]-ua);
  for (j=1; j<=r; j++)
    {
    save = r-j;   s = mul+j;
    for (k=p; k>=s; k--)
      {
      bpts[k] = alfs
      }
    Nextbpts[save] = bpts[p];
    }
  }

}
}
```
