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
    }
```
