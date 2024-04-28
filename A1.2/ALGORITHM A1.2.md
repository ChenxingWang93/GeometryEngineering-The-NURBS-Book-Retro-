``` C++
ALGORITHM A1.2
  Bernstein(i,n,u,B)
    {  /*  compute the value of a Bernstein polynomial 🧮計算 伯恩斯坦多項式的 值 */
       /*  Input:  i,n,u 輸入 */
       /*  Output: B 輸出 */
    for (j=0; j<=n; j++)   /*  compute the columns 🧮計算 列 */
      temp[j] = 0.0;       /*  of Table 1.1  */
    temp[n-i] = 1.0;       /*  in a temporary array 在臨時數組 中 */
    u1 = 1.0-u;
    for (k=1; k<=n; k++)
      for (j=n; j>=k; j--)
        temp[j] = u1*temp[j] + u*temp[j-1];
    B = temp[n];
    }
```