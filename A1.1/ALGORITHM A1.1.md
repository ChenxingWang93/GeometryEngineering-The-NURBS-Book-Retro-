``` Matlab
ALGORITHM A1.1
  Horner1(a,n,u0,C)
    {   /*  Compute point on power basis curve. 在势函数曲线上 计算点 */
        /*  Input:  a,n,u0  */
        /*  Output: C  */
    C = a[n];
    for (i=n-1; i>=0; i--)
      C = C*u0 + a[i];
    }
```

```

```

Ex1.1

n = 1. 
- C(u) = a_{0} + a_{1}u, 0<=u<=1, 为 点 a_{0} &a_{0} + a_{1} 间的直线 片段. (Figure 1.5)
- C(u)‘ = a_{1} 给出了直线 的方向 gives the direction of the line.

```
       ◦ a_{0}+a_{1}
      ⩘
     ∕
    ∕
   ∕ a_{1} 
  ∕
 ∕
◦ a_{0}
```

Ex1.2

n = 2.
- C(u) = a_{0} + a_{1}u + a_{2}u^2, 0<=u<=1, 为 点 a_{0} &a_{0} + a_{1} + a_{2} 间 抛物线弧 parabolic arc
- (Figure 1.5)

```
       
      ⩘
     ∕ a_{1}
    ∕    ⎯ ◦  a_{0} + a_{1} + a_{2}
   ∕  /       ∖
  ∕ /           ∖      a_{1} + 2a_{2}
 ∕/               ∖
◦ a_{0}            ⩗

```
1. 变换 C(u) 到 xy 平面 transforming C(u) into a xy plane (C(u) does lie in a unique plane);
2. 设定
  x = x_{0} + x_{1}u + x_{2}u^2
  y = y_{0} + y_{1}u + y_{2}u^2, 0<=u<=1,
  & then eliminating u & u^2 from these equations 得到 2 度隐式等式 a second-degree implicit equation in x &y.
3. 仔细观察👀 隐式等式的形式 就是一个抛物线
