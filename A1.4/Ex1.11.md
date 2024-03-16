Ex1.11🚩🚩🚩🚩🚩🚩🚩🚩🚩🚩🚩

***Parabola***, vertex at the origin; the y-axis is the axis of symmetry 

<img width="350" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/2e610207-faf7-4448-a750-97535ef6d0d5"> \\

``` Latex
(x(u))^{2} + (y(u))^{2} = (\frac{1-u^{2}}{1+u^{2}})^{2} + (\frac{2u}{1+u^{2}})^{2}
```

<img width="150" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/66debdbf-5eef-4b4e-b94d-ec368600059e"> \\

``` Latex
\frac{1-2u^{2}+u^{4}+4u^{2}}{(1+u^{2})^{2}}
```

<img width="110" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/9c62160f-5902-45a8-82a4-65229947edac">

``` Latex
\frac{(1+u^{2})^{2}}{(1+u^{2})^{2}} = 1
```

Define an nth-degree rational Bezier curve by (see[Forr68;Pieg86;Fari83,89])

<img width="300" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/ff175e17-f85a-4af8-9db0-0083a0476bf8"> (𝟷.𝟷𝟺)

``` Latex
C(u)=\frac{\sum_{i=0}^{n}B_{i,n}(u)w_{i}P_{i}}{\sum_{i=0}^{n}B_{i,n}(u)w_{i}} 0<=u<=1
```

The Pi = (xi, yi, zi) and Bi,n(u) are as before; the wi are scalars, called the weights, Thus, W(u) = E oBi,n(u)wi is the common denominator function. Except where explicitly stated otherwise, we assume that wi > 0 for all i. This ensures that W(u) > 0 for all u c[0,1]. We
write 

<img width="250" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/750a21fa-9094-4187-9bd7-92860adc1b06"> (𝟷.𝟷𝟻) 


``` Latex
C(u)=\sum_{i=0}^{n}R_{i,n}(u)P_{i} 0<=u<=1
```

where 

<img width="200" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/8eefdb0a-6d57-41be-9cdc-3fa2e9cc3f26">

The Ri,n(u) are the rational basis functions for this curve form. Figure 1.18a shows an example of cubic basis functions, and Figure 1.18b a corresponding cubic rational Bezier curve.

  The Ri,n(u) have properties which can be easily derived from Eq.(1.15) and the corresponding properties of the Bi,n(u):

P𝟷.𝟾 nonnegativity: Ri,n(u) > 0 for all i,n and 0<u<1;

P𝟷.𝟿 partition of unity: o Ri,n(u) = 1 for all 0<u<1;

P𝟷.𝟷𝟶 Ro,n(0) = Rn,n(1) = 1;

P𝟷.𝟷𝟷 Ri,n(u) attains exactly one maximum on the interval [0,1];

P𝟷.𝟷𝟸 if wi = 1 for all i, then Ri,n(u)

These yield the following geometric properties of rational Bezier curves:

P𝟷.𝟷𝟹 convex hull property: the curves are contained in the convex hulls of their defining control points(the Pi);

P𝟷.𝟷𝟺 Transformation invariance: rotations, translations, and scaling are applied to the curve by applying them to the control points;

P𝟷.𝟷𝟻 variation diminishing property: same as for polynomial Bezier curves (see previous section);

P𝟷.𝟷𝟼 endpoint interpolation: C(0) = Po and C(1) = Pn;

P𝟷.𝟷𝟽 the kth derivative at u = 0 (u = 1) depends on the first (last) k + 1 control points and weights; in particular, C'(0) and C'(1) are parallel to P1 - P0 and P. - Pn_li respectively;

P𝟷.𝟷𝟾 Polynomial Bezier curves are a special case of rational Bezier curves.

Figure 1.18

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/31abb5ce-5cf8-4c5a-873c-ec4a299658bd) (a)Basis functions;

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/8059ac96-18e4-4000-8b05-d61c988e2043) (b)Bezier curve.
