``` Matlab
ALGORITHM A1.3
   AllBernstein(n,u,B)
   {  /* compute all nth-degree Bernstein polynomials. 🧮计算 n-th级 伯恩斯坦多项式 */
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

```

```
