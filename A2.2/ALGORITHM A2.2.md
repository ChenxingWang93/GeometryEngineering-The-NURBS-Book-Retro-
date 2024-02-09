``` C++
ALGORITHM A2.2
  BasisFuns(i,u,p,U,N)
    { /*  Compute the nonvanishing basis functions 🧮计算 非消失 基函数 */
      /*  Input:  i,u,p,U 输入 */
      /*  Output: N 输出 */
    N[0]=1.0;
    for (j=1; j<=p; j++)
      {
  left[j] = u-U[i+1-j];
  right[j] = U[i+j]-u;
  saved = 0.0;
  for (r=0; r<j; r++)
    {
    temp = N[r]/(right[r+1]+left[j-r]);
    N[r] = saved+right[r+1]*temp;
    saved = left[j-r]*temp; 
    }
  N[j] = saved;
      }
    }
```
