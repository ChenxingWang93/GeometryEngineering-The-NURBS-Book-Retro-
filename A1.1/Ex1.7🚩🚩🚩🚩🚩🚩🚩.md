Ex1.7🚩🚩🚩🚩🚩🚩🚩

### n = 6.

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/fc774b45-46d8-4595-b1c6-1d88ff9abe69)

shows a sixth-degree, closed Bezier curve.

The curve is smooth at 

𝙲(𝟶) ( = 𝙲(𝟷)) because `P_{𝟷} - P_{𝟶}` is parallel to `P_{𝟼} - P_{𝟻}`

By smooth we mean that the tangent vectors at `𝚞 = 𝟶` &`𝚞 = 𝟷` have the same direction.

In addition to the previously mentioned properties, Bezier curves are invariant under the usual transformations 

such as rotations, translations, and scalings; that is, one applies the transformation to the curve by applying it to the control polygon.

We present this concept more rigorously in Chapter 𝟹 for B-spline curves(of which Bezier curves are a special case).

  In any curve(or surface) representation scheme, the choice of basis functions determines the geometric characteristics of the scheme. 

Figures 𝟷.𝟷𝟹𝚊-𝚍

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/a3c96c1c-807f-4a9e-b27c-2e14fe523c36)

Figures 𝟷.𝟷𝟹𝚊

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/3637e53b-af83-4a21-b63e-93a6f277a925)

Figures 𝟷.𝟷𝟹𝚋

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/cb673e33-f323-4377-b48c-510525ebb526)

Figures 𝟷.𝟷𝟹𝚌

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/00f86b4e-1ce5-4841-a75f-40fae1d620d2)

Figures 𝟷.𝟷𝟹𝚍

show the basis functions {𝘽_{𝚒,𝚗(𝚞)}} for 𝚗 = 𝟷,𝟸,𝟹,𝟿.

These functions have these properties:

***𝙿𝟷.𝟷***

nonegativity: 𝘽_{𝚒,𝚗(𝚞)} > 𝟶 for all 𝚒,𝚗 & 0<𝚞<𝟷;

***𝙿𝟷.𝟸***

partition of unity:

<img width="125" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/11449d14-9f86-4b66-9a41-5f62e1a1212f">

```
\sum_{i=0}^{n}B_{i,n}(u) = 1
```
for all 𝟶<𝚞<𝟷;

***𝙿𝟷.𝟹***
```
𝘽_{𝟶,𝚗(𝟶)} = 𝘽_{𝚗,𝚗(𝟷)} = 𝟷;
```

***𝙿𝟷.𝟺***
```
𝘽_{𝚒,𝚗(𝚞)}
```
attains exactly one maximum on the interval [𝟶,𝟷], that is, at 𝚞 = 𝚒/𝚗;

***𝙿𝟷.𝟻***

symmetry: for any 𝚗, the set of polynomial {𝙱_{𝚒,𝚗}(𝚞)} is symmetric with respect to 𝚞 = 𝟷/𝟸;

***𝙿𝟷.𝟼***

recursive definition: 𝙱_{𝚒,𝚗}(𝚞) = (1 - 𝚞)𝙱_{𝚒,𝚗-1}(𝚞) + 𝚞𝙱_{𝚒-1,𝚗-1}(𝚞)

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/7658ed1e-07d8-40dd-931a-07168b71bfaa);

we define 𝙱_{𝚒,𝚗}(𝚞) ≡ 𝟶 if 𝚒 < 𝟶 or 𝚒 > 𝚗;

***𝙿𝟷.𝟽***

derivatives:

<img width="350" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/c09e3a96-8668-45d0-a81c-8d891eecabb9">

```
{B_{i,n}(u)} = \frac{dB_{i,n}(u)}{du} = n(B_{i-1,n-1}(u)-B_{i,n-1}(u))
```

with 

<img width="250" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/8d842894-eaa9-45cd-8c8e-b167692646c3">

From Eq. (𝟷.𝟾)

Figure 𝟷.𝟷𝟻𝚊 shows the definition of `B'_{𝟸,𝟻}`,

and Figure 𝟷.𝟷𝟻𝚋 illustrates all the cubic derivative functions.

From Eq. (𝟷.𝟾)

<img width="250" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/8d842894-eaa9-45cd-8c8e-b167692646c3">

we have

```
B_{𝟶,𝟶}(𝚞) = 𝟷
```

