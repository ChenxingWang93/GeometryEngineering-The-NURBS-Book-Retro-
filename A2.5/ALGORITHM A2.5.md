``` C++
ALGORITHM A2.5
  DersOnBasisFun(p,m,U,i,u,n,ders)
    { /* Compute derivatives of basis function Nip 🧮计算 基函数Nip 的导数 */

  /*  Input: p,m,U,i,u,n  */
  /*  Output: ders */
if (u < U[i] || u >= U[i+p+1])  /* Local property 本地 属性 */
  {
  for (k=0; k<=n; k++)  ders[k] = 0.0;
  return;
  }
for (j=0; j<=p; j++)  /* Initialize zeroth-degree functs 初始化 0-th 阶 函数 */
  if (u >= U[i+j] && u < U[i+j+1])  N[j][0] = 1.0;
    else                N[j][0] = 0.0;
for (k=1; k<=p; k++)   /* Compute full triangular table 计算 全 三角 表格 */
  {
  if (N[0][k-1] == 0.0)  saved = 0.0;
    else    saved = ((u-U[i]*N[0][k-1])/U[i+k]-U[i]);
  for (j=0; j<p-k+1; j++)
    {
  Uleft = U[i+j+1];
  Uright = U[i+j+k+1]
  if (N[j+1][k-1] == 0.0)
    {
    N[j][k] = saved;   saved = 0.0;
    }
    else
    {
    temp = N[j+1][k-1]/(Uright-Uleft);
    N[j][k] = saved+(Uright-u)*temp;
    saved = (u-Uleft)*temp;
    }
    }
  }
ders[0] = N[0][p];   /* The function value 函数 值 */
for (k=1; k<=n; k++)   /* Compute the derivatives 计算 导数 */
  {
  for (j=0; j<=k; j++)   /* Load appropriate column 加载 适当的 栏目 */
    ND[j] = N[j][p-k];
  for (jj=1; jj<=k; jj++)   /* Compute table of width k 🧮计算表格宽度 k 值 */
    {
    if (ND[0] == 0.0)  saved = 0.0;
      else     saved = ND[0]/(U[i+p-k+jj]-U[i]);
    for (j=0; j<k-jj+1; j++)
      {
      Uleft = U[i+j+1];
      Uright = U[i+j+p+jj+1];
      if (ND[j+1] == 0.0)
        {
        ND[j] = (p-k+jj)*saved;   saved = 0.0;
        }
        else
        {
        temp = ND[j+1]/(Uright-Uleft);
        ND[j] = (p-k+jj)*(saved-temp);
        saved = temp;
        }
      }
    }
  ders[k] = ND[0];    /* kth derivative kth阶 导数 */
  }
    }
```
