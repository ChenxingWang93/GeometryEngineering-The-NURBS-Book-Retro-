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

🚩🚩***Ex1.2***

### n = 2.
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
   
3. 设定
  x = x_{0} + x_{1}u + x_{2}u^2
  y = y_{0} + y_{1}u + y_{2}u^2, 0<=u<=1,
  
  & then eliminating u & u^2 from these equations 得到 2 度隐式等式 a second-degree implicit equation in x &y.

5. 仔细观察👀 隐式等式的形式 就是一个抛物线

🚩🚩🚩***Ex1.3***

### n = 3. 

The cubic, 三次 
- C(u) = a_{0} + a_{1}u + a_{2}u^2 + a_{3}u^3 是非常通用的曲线 is a very general curve;

  it can be a truly _twisted_ three-dimensional curve 是一个 ***纯粹*** 的 _扭曲_ 三维曲线，

  not lying in a single plane 并不依附于一个单一的平面

  可以是 拐点 an inflection point(Figure 1.8b)
  
![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/4eeb86e9-8523-4b37-ae82-1928ab9c6cd7)

  可以是 奇异点 a cusp(Figure 1.8c)
  
![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/7bdc1487-8668-4cd8-9a35-8b5ad401e2f2)

  可以是 环 or a loop(Figure 1.8d)
  
![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/59fbf11f-a732-4049-bb11-52c3e2bd65be)
