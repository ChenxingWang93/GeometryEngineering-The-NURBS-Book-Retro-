```C++
ALGORITHM A5.6
  DecomposeCurve(n,p,U,Pw,nb,Qw)
    {  /*  Decompose curve into Bezier segments 分解曲线为 贝塞尔曲线 */
       /*  Input:    n,p,U,Pw 输入 */
       /*  Output:   nb,Qw 输出 */
    m = n+p+1;
    a = p;
    b = p+1;
    nb = 0;
    for (i=0; i<=p; i++)    Qw[nb][i] = Pw[i];
  
}
```