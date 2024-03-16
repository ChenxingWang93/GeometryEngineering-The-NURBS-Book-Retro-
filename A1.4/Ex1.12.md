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

Figure 1.19. representation of the unit circle.

(a) 

<img width="100" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/bae304e1-168a-45bf-b7d8-0d56fca3cb4e">


``` Latex
x(u) = \frac{1-u^{2}}{1+u^{2}}
```

<img width="100" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/93db0a3c-e587-4e69-9835-64919789348a">

``` Latex
y(u) = \frac{2u}{1+u^{2}}
```

for one quadrant;

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/4b97482f-6098-409d-9fb7-efd1255a18a1)

(b)

the Bezier representation corresponding to Figure 1.19a

<img width="50" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/055a98a0-601e-45fc-a0f1-d4eff075aead"> \\

<img width="50" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/91328ad5-15f9-453f-8174-56ec8ca8029e"> \\

<img width="50" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/766dc06f-648e-4ace-9253-bc60c7bd5ebb">

substituting 𝚞 = 𝟶 yields 𝚠_{𝟶} = 𝟷

𝚞 = 𝟷 yields 𝚠_{𝟸} = 𝟸

Finally, substituting 𝚞 = 𝟷/𝟸 yields 𝟻/𝟺 = 𝟷/𝟺𝚠_{𝟶} + 𝟷/𝟸𝚠_{𝟷} + 𝟷/𝟺𝚠_{𝟸}

using 𝚠_{𝟶} = 𝟷 &𝚠_{𝟸} = 𝟸 yields 𝚠_{𝟷} = 𝟷 (see Figure 1.19b)


This mapping, denoted by 𝑯, is a perspective map with center at the origin 

𝑷 = 𝑯{𝑷^{𝑤}} = 𝑯{(𝑿,𝒀,𝒁,𝑾)} = { (𝑿/𝑾,𝒀/𝑾,𝒁/𝑾)   if 𝑾 ≠ 0 

                                  direction (𝑿,𝒀,𝒁) if 𝑾 = 0 (𝟷.𝟷𝟼)

Notice that for arbitrary x,y,z, 𝐖1, 𝐰2, where 𝐰1 ∼ 𝐖2

𝑯{𝑷^{𝑤_{1}}} = 𝑯{(𝑤_{1}𝑥,𝑤_{1}𝑦,𝑤_{1}𝑧,𝑤_{1})} = (𝑥,𝑦,𝑧)

              = 𝑯{(𝑤_{2}𝑥,𝑤_{2}𝑦,𝑤_{2}𝑧,𝑤_{2})} = 𝑯{𝑷^{𝑤_{2}}}

  Now for a given set of control points, {𝑷𝑖}, and weights, {𝑤𝑖}, construct the weighted
control points, 𝑷𝑤 = (𝑤𝑖𝑥𝑖, 𝑤𝑖𝑦𝑖, 𝑤𝑖𝑧𝑖, 𝑤𝑖). Then define the nonrational (polynomial) Bezier
curve in four-dimensionl space 

<img width="200" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/5e842112-18de-421b-9fbb-9193b3d36c20"> (𝟷.𝟷𝟽)


``` Latex
C^{w}(u) = \sum_{i=0}^{n}B_{i,n}(u)P_{i}^{w}
```

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/5cc76ded-894e-4170-a5fa-0085e1f35ad9)

Figure 𝟷.𝟸𝟶 A representation of Euclidean points in homogeneous form.

  Then, applying the perspective map, 𝑯, to ~~𝑪(𝑢)^{0}~~ yields the corresponding rational Bezier curve of Eq.[(𝟷.𝟷𝟺)](https://github.com/ChenxingWang93/GeometryEngineering/blob/main/A1.4/Ex1.11.md) (see Figure 𝟷.𝟸𝟷), that is, writing out the coordinate functions of Eq.(𝟷.𝟷𝟽), we get

