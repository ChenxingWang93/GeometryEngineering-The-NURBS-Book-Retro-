``` C++
ALGORITHM A2.3
  DersBasisFuns(i,u,p,n,U,ders)
    { /*  compute nonzero basis functions and their 计算 非零 基函数 */
      /*  derivatives.  First section is A2.2 modified 与 它的倒数 */
      /*  to store functions and knot differences. 存储函数 &节点差异 */
      /*  Input:  i,u,p,n,U  */
      /*  Output: ders  */
    ndu[0][0]=1.0;
    for (j=1; j<=p; j++)
{
left[j] = n-U[i+1-j];
right[j] = U[i+j]-u;
saved = 0.0;
for (r=0; r<j; r++)
  {                                    /* Lower triangle 下三角 */
  ndu[j][r] = right[r+1]+left[j-r];
  temp = ndu[r][j-1]/ndu[j][r];
                                       /* Upper triangle 上三角 */
  ndu[r][j] = saved+right[r+1]*temp;
  saved = left[j-r]*temp;
  }
ndu[j][r] = saved;
}
for (j=0; j<=p; j++)   /* Load the basis functions */
  ders[0][j] = ndu[j][p];
/* This section computes the derivatives (Eq. [2.9]) */
for (r=0; r<=p; r++)   /* Loop over function index */
    {
    s1=0; s2=1;   /* Alternate rows in array a */
    a[0][0] = 1.0;
    /* Loop to compute kth derivative */
    for (k=1; k<=n; k++)
      {
    d = 0.0;
    rk = r-k;    pk = p-k;
    if (r >= k)
      {
      a[s2][0] = a[s1][0]/ndu[pk+1][rk];
      d = a[s2][0]*ndu[rk][pk];
      }
    if (rk >= -1)   j1 = 1;
      else          j1 = -rk;
    if (r-1 <= pk)   j2 = k-1;
      else           j2 = p-r;
    for (j=j1; j<=j2; j++)
      {
      
      a[s2][j] = (a[s1][j]-a[s1][j-1])/ndu[pk+1][rk+j];
      d += a[s2][j]*ndu[rk+j][pk];
      }
    if (r <= pk)
      {
      a[s2][k] = -a[s1][k-1]/ndu[pk+1][r];
      d += a[s2][k]*ndu[r][pk];
      }
    ders[k][r] = d;
    j=s1;   s1=s2;   s2=j;   /* Switch rows */
    }
      }
    /* Multiply through by the correct factors */
    /* (Eq. [2.9]) */
    r = p;
    for (k=1; k<=n; k++)
      {
      for (j=0; j<=p; j++)   ders[k][j] *= r;
      r *= (p-k);
      }
    }
```