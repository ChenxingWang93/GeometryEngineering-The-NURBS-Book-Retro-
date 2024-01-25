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

🚩***Ex1.1***

### n = 1. 
```
- C(u) = a_{0} + a_{1}u, 0<=u<=1,
```
为 点 
```
a_{0} &a_{0} + a_{1} 
```
间的直线 片段. (Figure 1.5)
```  
- C(u)‘ = a_{1}
```
给出了直线 的方向 gives the direction of the line.

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

🚩🚩***Ex1.2***

### n = 2.
```
- C(u) = a_{0} + a_{1}u + a_{2}u^2, 0<=u<=1,
```
为 点 
```
a_{0} &a_{0} + a_{1} + a_{2}
```
间 抛物线弧 parabolic arc
  
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

1. 变换
```
C(u)
```
到 xy 平面 transforming 
```
C(u)
```
into a xy plane 
```
(C(u)
```
does lie in a unique plane);
   
3. 设定
```
  x = x_{0} + x_{1}u + x_{2}u^2
  y = y_{0} + y_{1}u + y_{2}u^2, 0<=u<=1,
```

  & then eliminating u & u^2 from these equations 得到 2 度隐式等式 a second-degree implicit equation in x &y.

5. 仔细观察👀 隐式等式的形式 就是一个抛物线

🚩🚩🚩***Ex1.3***

### n = 3. 

The cubic, 三次
```
- C(u) = a_{0} + a_{1}u + a_{2}u^2 + a_{3}u^3
```
是非常通用的曲线 is a very general curve;

  it can be a truly _twisted_ three-dimensional curve 是一个 ***纯粹*** 的 _扭曲_ 三维曲线，

  not lying in a single plane 并不依附于一个单一的平面

  可以是 拐点 an inflection point(Figure 1.8b)
  
![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/4eeb86e9-8523-4b37-ae82-1928ab9c6cd7)

  可以是 奇异点 a cusp(Figure 1.8c)
  
![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/7bdc1487-8668-4cd8-9a35-8b5ad401e2f2)

  可以是 环 or a loop(Figure 1.8d)
  
![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/59fbf11f-a732-4049-bb11-52c3e2bd65be)

The basis(blending) functions, 基础 弯曲 函数 {Bi,,(u)}, 是经典的 nth-阶 伯恩斯坦多项式 the classical nth-degree Bernstein polynomials

([Bern12; Lore86])

🚩🚩🚩🚩***Ex1.4***

### n = 1

```
C(u)_>BZ,n(u)Pi 0 < u < 1 
```
(1.7)

<img width="350" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/8d842894-eaa9-45cd-8c8e-b167692646c3">
(1.8)

```
B_{0,1}(u) = 1 - u &
```

```
B_{1,1}(u) = u
```

取形式 
```
C(u) = (1-u)P_{0} + uP_{1}, 
```
从 
```
P_{0} 
```
到 
```
P_{1}
```
的直线片段

🚩🚩🚩🚩🚩***Ex1.5***

### n = 2.  

From Eqs. (1.7) &(1.8) we have

```
C(u) = (1-u)^2P_{0}+2u(1-u)P_{1}+u^2P_{2}
```

从
```
P_{0} 
```
到 
```
P_{2} 
```
的抛物线

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/8889d711-43b6-4b87-8d9f-5162746de74e)

the polygon formed by
```
{P_{0},P_{1},P_{2}}, 
```
called the control polygon, approximates the shape of the curve rather nicely;

```
P_{0} = C(0) &P_{2} = C(1);
```

- the tangent directions to the curve at its endpoints are parallel to
```
p_{1}-p_{0}
```

```
p_{2}-p_{1}
```
(this is derived later)

the curve is contained in the triangle formed by 

```
P_{0}
P_{1}
P_{2}
```

🚩🚩🚩🚩🚩🚩Ex1.6

### n = 3.

```
C(u) = (1-u)^3P_{0} + 3u(1-u)^2P_{1} + 3u^{2}(1-u)P_{2} + u^{3}P_{3}
```
![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/f6fa2a72-212c-4152-be1e-cc9db4fda4cb)

examples of cubic Bezier curves are shown above
- the control polygons approximates the shapes of the curves;
```
- P_{0} = C(0) & P_{3} = C(1)
```
- 端点的tangent 方向平行于
```
P_{1} - P_{0} & P_{3} - P_{2};
```

- convex hull property凸包属性: the curves are  contained in the convex hulls of their defining control pts
![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/18247197-7f24-4d44-8a42-bdd7c2624722)

- variation diminishing property:差异 减少 属性 no straight line intersects a curve more times than it intersects the curve's control polygon(for a three-dimensional Bezier curve, replace the words 'straight line' with the word 'plane'). This expresses the property that a Bezier curve follows its control polygon rather closely and does not wiggle more than its control polygon.

没有 直线 相交曲线的次数 多于曲线控制 多边形（对于 三维 贝塞尔曲线，替换 “直线” 为 “平面”）

这表达了 贝塞尔曲线相当紧密地 遵循其控制多边形

并且不会比其控制多边形摆动更多 的属性

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/cb66646a-a564-477f-a24e-7232020429d3)

- initially (at u = 0) the curve is turning in the same direction as
 
```
P_{0} P_{1} P_{2} 
```
at u = 1 it is turning in the direction 

```
P_{1} P_{2} P_{3} 
```
- a loop in the control polygon may or may not imply a loop in the curve. The transition between Figure 1.11e &Figure 1.11f is a curve with a cusp.

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/de0f7a6e-05ea-4941-85f7-9d5fd157379c)![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/de21600a-5db9-454f-a33e-5f2d5dfab61d)

🚩🚩🚩🚩🚩🚩🚩Ex1.7

### n = 6.

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/fc774b45-46d8-4595-b1c6-1d88ff9abe69)

Figure 1.12 shows a sixth-degree, closed Bezier curve. The curve is smooth at C(0)(=C(1)) P_{1} - P_{0} is parallel to P_{6} - P_{5}
在 u = 0 & u = 1 处的 tangent vectors 有相同方向。

in addition to the previously mentioned properties, Bezier curves are invariant under the usual transformation such as rotations, translations &scalings;

that is, one applies the transformation to the curve by applying it to the control polygon. We present this concept more rigorously in Chapter 3 for B-spline curve(of which Bezier curves are a special case.)
