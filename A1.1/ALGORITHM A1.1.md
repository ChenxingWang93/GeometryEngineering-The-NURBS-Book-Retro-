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

🚩🚩🚩🚩🚩🚩🚩Ex1.7

### n = 6.

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/fc774b45-46d8-4595-b1c6-1d88ff9abe69)

Figure 1.12 shows a sixth-degree, closed Bezier curve. The curve is smooth at 

```
C(0)(=C(1)) P_{1} - P_{0} 
```

is parallel to 

```
P_{6} - P_{5}
```

在 u = 0 & u = 1 处的 tangent vectors 有相同方向。

in addition to the previously mentioned properties, Bezier curves are invariant under the usual transformation such as rotations, translations &scalings;

that is, one applies the transformation to the curve by applying it to the control polygon. We present this concept more rigorously in Chapter 3 for B-spline curve(of which Bezier curves are a special case.)

***P1.2***  partition of unity:

***P1.3*** 
```
B_{0,n}(0) = B_{n,n}(1) = 1;
```

***P1.4***
```
B_{i,n}(u)
```
attains exactly one maximum on the interval,
```
[0,1]
```
that is, at
```
_u_ = _i_/_u_
```
***P1.5***
symmetry: for any 
```
_n_,   
```
the set of polynomials
```
B_{i,n}(u)
```
is symmetric with respect to
```
 _u_ = 1/2;
```
Figure1.13.The Bernstein polynomials for 
```
(a)n = 1; (b)n = 2; (c)n = 3; (d)n = 9.
```

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/98b89ff9-fc5d-4d4d-93cd-34a798ce74c6)

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/6fbba15b-eb4a-4c9a-a11e-76ee3526030f)

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/497b1119-d719-4d3a-aa52-c3646af5f87f)

***P1.6*** recursive definition:
```
 B_{i,n}(u) = (1 - u)B_{i,n-1}(u) + uB_{i-1,n-1}(u)
```
(see Figure 1.14);

we define 
```
B_{i,n}(u) = 0 if i<0 or i>n;
```
***P1.7*** derivatives:
```
{B_{i,n}(u)} = \frac{dB_{i,n}(u)}{du} = n(B_{i-1,n-1}(u)-B_{i,n-1}(u))
```

with

```
B-1,n_1(u),n-1(u) - 0
```

with B-1,n_1(u) - Bn, n-1(u) - 0

the definition of B'_{2,5}

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/be9c29ba-9ac6-4630-aab8-8f8a5cae9574)
