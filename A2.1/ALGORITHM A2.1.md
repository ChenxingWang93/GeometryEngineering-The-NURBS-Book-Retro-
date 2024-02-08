``` C++
ALGORITHM A2.1
  int FindSpan(n,p,u,U)
    { /*  Determine the knot span index 决定 节跨度的 指数 */
      /*  Input:  n,p,u,U  */
      /*  Return: the knot span index 节跨度 指数 */
    if (u == U[n+1])  return(n);    /* Special case 特殊情况 */
    low = p;  high = n+1;   /* Do binary search 做 二进制搜索🔍 */
    mid = (low+high)/2;
    while (u < U[mid] || u >= U[mid+1])
  {
  if (u < U[mid])   high = mid;
    else            low = mid;
  mid = (low+high)/2
  }
    return(mid);
    }
```
