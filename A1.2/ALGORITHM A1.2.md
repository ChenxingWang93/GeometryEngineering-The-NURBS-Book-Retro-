``` Matlab
ALGORITHM A1.2
  Bernstein(i,n,u,B)
    {  /*  compute the value of a Bernstein polynomial 🧮计算 伯恩斯坦多项式的 值 */
       /*  Input:  i,n,u  */
       /*  Output: B  */
    for (j=0; j<=n; j++)   /*  compute the columns 🧮计算 列 */
      temp[j] = 0.0;       /*  of Table 1.1  */
    temp[n-i] = 1.0;       /*  in a temporary array 在临时数组 中 */
    u1 = 1.0-u;
    for (k=1; k<=n; k++)
      for (j=n; j>=k; j--)
        temp[j] = u1*temp[j] + u*temp[j-1];
    B = temp[n];
    }
```

```

```
