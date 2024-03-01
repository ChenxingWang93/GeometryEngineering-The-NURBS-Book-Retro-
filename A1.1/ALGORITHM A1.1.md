``` C++
ALGORITHM A1.1
  Horner1(a,n,u0,C)
    {   /*  Compute point on power basis curve. 在势函数曲线上 计算点 */
        /*  Input:  a,n,u0 输入 */
        /*  Output: C 输出 */
    C = a[n];
    for (i=n-1; i>=0; i--)
      C = C*u0 + a[i];
    }
```

```

```
