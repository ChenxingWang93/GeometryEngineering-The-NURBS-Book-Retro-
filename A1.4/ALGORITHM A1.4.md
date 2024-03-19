``` C++
ALGORITHM A1.4
  PointOnBezierCurve(P, n, u, C)
    {  /*  Compute point on Bezier curve 🧮计算 贝塞尔曲线 上的点 */
       /*  Input: P,n,u 输入 */
       /*  Output: C (a point) 输出 */
    AllBernstein(n,u,B)  /* B is a local array B为 局部数组 */
    C = 0.0;
    for (k=0; k<=n; k++)  C = C + B[k]*P[k];
    }
```

```

```

<img width="200" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/698330f5-73b8-468e-ba6d-461efd4bde8b"> = <img width="100" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/af252ed7-2ffc-4a36-aed3-e01f61498ee3">

= <img width="250" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/69c4202a-aef6-4e3d-828c-08fa68affcf8">

= <img width="210" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/0686f254-60a0-4723-9bc1-4bf010dd2f71">    (𝟷.𝟿)

From Eq.(𝟷.𝟿) we easily obtain formulas for the end derivatives of a Bezier curve, e.g.

|||
|------------------------|-----------------------------------------|
|𝙲'(𝟶) = 𝚗(𝗣_{𝟷} - 𝗣_{𝟶})|𝙲''(𝟶) = 𝚗(𝚗 - 𝟷)(𝗣_{𝟶} - 𝟸𝗣_{𝟷} + 𝗣_{𝟸})|
|𝙲'(𝟷) = 𝚗(𝗣_{𝚗} - 𝗣_{𝚗 - 𝟷})|𝙲''(𝟷) = 𝚗(𝚗 - 𝟷)(𝗣_{𝚗} - 𝟸𝗣_{𝚗 - 𝟷}) + 𝗣_{𝚗 - 𝟸}|    (𝟷.𝟷𝟶)

Eqs.(𝟷.𝟿) &(𝟷.𝟷𝟶) that𝑷

- the derivative of an nth-degree Bezier curve is an (𝚗 - 𝟷)th-degree Bezier curve;
- the expressions for the end derivatives at 𝚞 = 𝟷 &𝚞 = 𝟶 are symmetric (due, of course, to the symmetry of the basis functions);
- the 𝚔th derivative at an endpoint depends(in a geometrically intuitive manner) solely on the 𝚔 + 𝟷 control point at the end.

```
𝙲(𝚞) = (𝟷 - 𝚞)^2𝗣_{𝟶} + 𝟸𝚞(𝟷 - 𝚞)𝗣_{𝟷} + 𝚞^2𝗣_{𝟸}
     = (𝟷 - 𝚞)((𝟷 - 𝚞)𝗣_{𝟶} + 𝚞𝗣_{𝟷}) + 𝚞((𝟷 - 𝚞)𝗣_{𝟷} + 𝚞𝗣_{2})
```
(𝟷.𝟷𝟶)

Thus, 𝙲(𝚞) is obtained as the linear interpolation of two first-degree Bezier curves;
in particular, any point on 𝙲(𝚞) is obtained by three linear interpolations.

Assuming a fixed 𝑢 = 𝑢_{𝟶} & letting

𝗣_{𝟷,𝟶} = (𝟷 - 𝑢_{𝟶})𝗣_{𝟶} + 𝑢_{𝟶}𝗣_{𝟷},

𝗣_{𝟷,𝟷} = (𝟷 - 𝑢_{𝟶})𝗣_{𝟷} + 𝑢_{𝟶}𝗣_{𝟸}, &

𝗣_{𝟸,𝟶} = (𝟷 - 𝑢_{𝟶})𝗣_{𝟷,𝟶} + 𝑢_{𝟶}𝗣_{𝟷,𝟷},

𝐂(𝑢_{𝟶}) = 𝗣_{𝟸,𝟶}.

The situation is depicted in Figure 𝟷.𝟷𝟼,

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/26959ac0-29b4-4018-8ae4-582c5a2a6de0)

  Denoting a general nth-degree Bezier curve by 
  
𝐂_{𝑛}(𝐏_{𝟶},...,𝐏_{𝑛}) = (𝟷 - 𝚞)𝑪_{𝑛 - 𝟷}(𝐏_{𝟶},...,𝐏_{𝑛 - 𝟷})

+ 𝚞𝐂_{𝑛 - 𝟷}(𝐏_{𝟷},...,𝐏_{𝑛})

(𝟷.𝟷𝟷)

![image](https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/82fe361b-e489-4398-9d81-ab79da3d7b29)

Figure 𝟷.𝟷𝟽. A point on a cubic Bezier curve by repeated linear interpolation at 𝑢𝟶 = 𝟸/𝟻

This follows from the recursive definition of the basis functions (see P𝟷.𝟼).Fixing 𝑢=𝑢𝟶

& denoting P𝑖 by P𝟶,Eq.(𝟷.𝟷𝟷) yields a recursive algorithm for computing the point 𝐂(𝑢𝟶) = P𝟶(𝑢𝟶) on an nth-degree Bezier curve, i.e.

<img width="400" alt="image" src="https://github.com/ChenxingWang93/GeometryEngineering/assets/31954987/2d9d62e8-2539-4430-a312-575d9c34d606"> (𝟷.𝟷𝟸)


𝗣_{𝑘,𝑖}(𝑢_{𝟶}) = (𝟷 - 𝑢_{𝟶})𝗣_{𝑘-𝟷,𝑖+𝟷}(𝑢_{𝟶}) for 𝑘 = 𝟷,...,𝑛

                                                  𝑖 = 𝟶,...,𝑛 - 𝑘


  Equation(𝟷.𝟷𝟸) is called deCasteljau Algorithm (see[Boeh84;deCa86;93]). It is a corner-cutting process(Figure 𝟷.𝟷𝟼 &Figure 𝟷.𝟷𝟽) which yields the triangular table of points shown in Table 𝟷.𝟷𝟹
