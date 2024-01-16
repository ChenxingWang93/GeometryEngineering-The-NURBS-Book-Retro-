``` Matlab
ALGORITHM A1.3
   AllBernstein(n,u,B)
   {  /* compute all nth-degree Bernstein polynomials. 🧮计算 n-th 度 伯恩斯坦多项式 */
      /* Input: n,u */
      /* Output: B (an array, B[0],... B[n]) */
   B[0] = 1.0
   u1 = 1.0-u;
   for (j=1; j<=n; j++)
     {
     saved = 0.0;
     for (k = 0; k<j; k++)
       {
       temp = B[k];
       B[k] = saved+u1*temp;
       saved = u*temp;
       }
     B[j] = saved;
     }
   }
``` 
algorithm a1.3 computes the n+1 degree Bernstein polynomials 计算🧮 n+1 度的 伯恩斯坦多项式 which are nonzero at fixed u 在固定 u 处为 非0⃣️, avoids unnecessary computation of zero terms 避免了对 0 项的 不必要计算

```
Table 1.1. The computation of B_{1,3}.
-----------------------------------------
0=B_{-2,0}            B_{-1,2}
            ⬊
            B_{-1,1}              B_{0,3}
            ⬈         ⬊
0=B_{-1,0}            B_{0,2}
            ⬊         ⬈           ⬊
            B_{0,1}               B_{1,3}
            ⬈         ⬊           ⬈
1=B_{0,0}             B_{1,2}
            ⬊         ⬈
            B_{1,1}               B_{2,3}
            ⬈
0=B_{1,0}             B_{2,2}
-----------------------------------------
```
table 1.2 depicted its cubic case.

```

            B_{-1,1}              B_{0,3}
                                  ⬈
B_{-1,0}              B_{0,2}
                      ⬈           ⬊
            B_{0,1}               B_{1,3}
            ⬈         ⬊           ⬈
1=B_{0,0}             B_{1,2}
            ⬊         ⬈           ⬊
            B_{1,1}               B_{2,3}
                      ⬊           ⬈
B_{1,0}               B_{2,2}
                                  ⬊
            B_{2,1}               B_{3,3}

```

```
            z
            ⩘↑
           ⧸ ↑
          ⧸  ↑         Twisted cubic
         ⧸   ↑       ⩘
        ⧸   ↙︎ ↘︎     ⧸
       ⧸  ↙︎⎯    ↘︎ ⧸
     ∙↙︎⧸      \   /↘︎
   ↙︎           ⎯∙    ↘︎
x                        y
```

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/b20df49e-cf22-4da2-b012-1692b4f1a3bc)
