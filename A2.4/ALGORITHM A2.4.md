``` C++
ALGORITHM A2.4
  OneBasisFun(p,m,U,i,u,Nip)
    {  /* Compute the basis function Nip 🧮 计算 基函数 Nip */
       /* Input: p,m,U,i,u */
       /* Output: Nip */
if ((i == 0 && u == U[0]) ||     /* Special 特殊 */
    (i == m-p-1 && u == U[m]))   /*  cases 情况 */
  {
  Nip = 1.0;    return;
  }
if (u < U[i] || u >= U[i+p+1])   /* Local property 本地属性 */
  {
  Nip = 0.0;    return;
  }
for (j=0; j<=p; j++)  /* Initialize zeroth-degree functs 初始化一个 0th-阶 函数 */
  if (u >= U[i+j] && u < U[i+j+1])   N[j] = 1.0;
    else          N[j] = 0.0;
for (k=1; k<=p; k++)  /* Compute triangular table  计算 三角 表格*/
  {
  if (N[0] == 0.0)  saved = 0.0;
    else       saved = ((u-U[i]*N[0])/U[i+k]-U[i]);
  for (j=0; j<p-k+1; j++)
  {
  Uleft = U[i+j+1];
  Uright = U[i+j+k+1];
  if (N[j+1] == 0.0)
    {
    N[j] = saved;   saved = 0.0;
    }
    else
    {
    temp = N[j+1]/(Uright-Uleft);
    N[j] = saved+(Uright-u)*temp;
    saved = (u-Uleft)*temp;
    }
  }
}
Nip = N[0];
}
```