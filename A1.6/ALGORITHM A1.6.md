``` C++
ALGORITHM A1.6
  Horner2(a,n,m,u0,v0,S)
    {  /*  Compute point on a power basis surface. 🧮计算 幂基函数 曲面 上的点 ∙  */
       /*  Input:  a, n, m, u0, v0 输入 */
       /*  Output: S 输出 */
    for (i=0; i<=n; i++)
      Horner1(a[i][],m,v0,b[i]);    /* a[i][] is the ith row 第 ith 行 执行霍纳法则 */
    Horner1(b,n,u0,S);
    }
```