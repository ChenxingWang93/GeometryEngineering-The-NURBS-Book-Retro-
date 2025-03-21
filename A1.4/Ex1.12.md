Ex1.12🚩🚩🚩🚩🚩🚩🚩🚩🚩🚩🚩🚩

<img width="300" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/72084142-4f6b-41f6-8ef9-2f475bb4e4bb">

``` Latex
C(u) = (x(u),y(u)) = (\frac{1-u^{2}}{1+u^{2}},\frac{2u}{1+u^{2}})\\ 
0<=u<=1
```

<img width="500" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/4531dbd0-eca1-4011-a1a8-f241e05811df">

``` Latex
W(u) = 1+u^{2} = \sum_{i=0}^{2}B_{i,2}(u)w_{i} = (1-u)^{2}w_{0}+2u(1-u)w_{1}+u^{2}w_{2}
```


![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/34e84493-b88d-4ca3-a054-4638356512fc)

Figure 1.19. representation of the unit circle. 单位圆 表示法

(a) 

<img width="100" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/bae304e1-168a-45bf-b7d8-0d56fca3cb4e">


``` Latex
x(u) = \frac{1-u^{2}}{1+u^{2}}
```

<img width="100" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/93db0a3c-e587-4e69-9835-64919789348a">

``` Latex
y(u) = \frac{2u}{1+u^{2}}
```

for one quadrant; 1 象限

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/4b97482f-6098-409d-9fb7-efd1255a18a1)

(b)

the Bezier representation corresponding to Figure 1.19a （对应）单位圆 的贝塞尔 表示法

<img width="50" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/055a98a0-601e-45fc-a0f1-d4eff075aead"> \\

<img width="50" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/91328ad5-15f9-453f-8174-56ec8ca8029e"> \\

<img width="50" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/766dc06f-648e-4ace-9253-bc60c7bd5ebb">

substituting 𝚞 = 𝟶 yields 𝚠_{𝟶} = 𝟷

𝚞 = 𝟷 yields 𝚠_{𝟸} = 𝟸

Finally, substituting 𝚞 = 𝟷/𝟸 yields 𝟻/𝟺 = 𝟷/𝟺𝚠_{𝟶} + 𝟷/𝟸𝚠_{𝟷} + 𝟷/𝟺𝚠_{𝟸}

using 𝚠_{𝟶} = 𝟷 &𝚠_{𝟸} = 𝟸 yields 𝚠_{𝟷} = 𝟷 (see Figure 1.19b)


This mapping, denoted by 𝑯, is a perspective map with center at the origin 中心点 在原点 的透视 映射 标记为 𝑯

𝑷 = 𝑯{𝑷^{𝑤}} = 𝑯{(𝑿,𝒀,𝒁,𝑾)} = { (𝑿/𝑾,𝒀/𝑾,𝒁/𝑾)   if 𝑾 ≠ 0 

                                  direction (𝑿,𝒀,𝒁) if 𝑾 = 0 (𝟷.𝟷𝟼)

Notice that for arbitrary x,y,z, 𝐖1, 𝐰2, where 𝐰1 ∼ 𝐖2

𝑯{𝑷^{𝑤_{1}}} = 𝑯{(𝑤_{1}𝑥,𝑤_{1}𝑦,𝑤_{1}𝑧,𝑤_{1})} = (𝑥,𝑦,𝑧)

              = 𝑯{(𝑤_{2}𝑥,𝑤_{2}𝑦,𝑤_{2}𝑧,𝑤_{2})} = 𝑯{𝑷^{𝑤_{2}}}

  Now for a given set of control points, {𝑷𝑖},对于给定的 控制点集 and weights, {𝑤𝑖},权重 construct the weighted
control points,构造带权重的 控制点 𝑷𝑤 = (𝑤𝑖𝑥𝑖, 𝑤𝑖𝑦𝑖, 𝑤𝑖𝑧𝑖, 𝑤𝑖). Then define the nonrational (polynomial) Bezier
curve in four-dimensionl space 定义了 在四维空间 中的 非有理（多项式）贝塞尔 曲线

<img width="200" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/5e842112-18de-421b-9fbb-9193b3d36c20"> (𝟷.𝟷𝟽)


``` Latex
C^{w}(u) = \sum_{i=0}^{n}B_{i,n}(u)P_{i}^{w}
```

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/5cc76ded-894e-4170-a5fa-0085e1f35ad9)

Figure 𝟷.𝟸𝟶 A representation of Euclidean points in homogeneous form. 同质 形式 的欧几里德点 表示法

  Then, applying the perspective map, 𝑯, to ~~𝑪(𝑢)^{0}~~ yields the corresponding rational Bezier curve of Eq.[(𝟷.𝟷𝟺)](https://github.com/ChenxingWang93/GeometryEngineering/blob/main/A1.4/Ex1.11.md) (see Figure 𝟷.𝟸𝟷),运用 透视法 映射 推出对应的 有理 贝塞尔曲线 that is, writing out the coordinate functions of Eq.[(𝟷.𝟷𝟽)](https://github.com/ChenxingWang93/GeometryEngineering/blob/main/A1.4/Ex1.12.md), we get 

<img width="170" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/e10e1141-cf65-4f18-84c5-ec0c044a6396"> \\

<img width="170" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/fcde54a9-ced9-44bb-b577-886061b88108"> \\

<img width="170" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/d8b03bd6-b04a-49f5-940d-aeb305158888"> \\

<img width="170" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/202edef5-5f30-4a25-b400-c8c3f603341f">


Locating the curve in three-dimensional space yields 

<img width="300" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/1fa5cec6-69b1-47b8-a360-ed54c301c9b4"> \\

<img width="300" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/7cada52c-252d-495b-9d08-bc002e7644c0"> \\

<img width="300" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/b2828ceb-dddd-4c23-b247-6d2fca2058c0">

Using [vector normal 𝟷.𝟻](https://github.com/ChenxingWang93/GeometryEngineering/edit/main/A1.1/Ex1.1.md), we get 

<img width="450" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/01ca3b53-f105-4ec7-b2fc-7203cee9ca27"> \\

<img width="150" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/b5dad1b6-3b86-4c53-97c3-96ccc4b99970"> (𝟷.𝟷𝟾)

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/9a18c2e2-71de-444b-bbfe-a561f8f1a024)

Figure 𝟷.𝟸𝟷. A geometric construction of a rational Bezier curve. 有理 贝塞尔曲线 的几何构造
  For algorithms in this book we primarily use the form given by 对于本书中的 算法主要使用 形式Eq. [(𝟷.𝟷𝟽)](https://github.com/ChenxingWang93/GeometryEngineering/blob/main/A1.4/Ex1.13.md), and an analogous form for rational B-spline curves. Thus, nonrational forms are processed in four-dimensional space, and the results are located in three dimensional space using the map 𝑯. We refer interchangeably to either 𝑪'(𝑢) &𝑪(𝑢) as the rational Bezier (or B-spline) curve, although strictly speaking, 𝑪'(𝑢)is not a rational curve.
