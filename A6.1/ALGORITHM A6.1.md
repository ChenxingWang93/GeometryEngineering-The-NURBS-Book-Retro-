``` C++
ALGORITHM A6.1
  BezierToPowerMatrix(p,M)
    {  /*  Compute pth degree Bezier matrix  计算 pth 度 贝塞尔曲线  */
       /*  Input:  p  */
       /*  Output: M  */
    for (i=0; i<p; i++)  /* Set upper triangle to zero 设定 上三角 为0⃣️ */
      for (j=i+1; j<=p; j++)   M[i][j] = 0.0;
    M[0][0] = M[p][p] = 1.0;  /* Set corner elements 设定 角 元素 */
    if (p mod 2)  M[p][0] = -1.0;
      else        M[p][0] = 1.0;
    sign = -1.0;
    for (i=1; i<p; i++)  /* Compute first column, last row, 计算 ☝️1st 列，最后 行，*/
      {           /* and the diagonal */
  M[i][i] = bin[p][i];
  M[i][0] = M[p][p-i] = sign*M[i][i];
  sign = -sign;
  }
/* Compute remaining elements 计算🧮 剩余 元素 */
k1 = (p+1)/2;    pk = p-1;
for (k=1; k<k1; k++)
  {
  sign = -1.0;
  for (j=k+1; j<pk; j++)
    {
    M[j][k] = M[pk][p-j] = sign*bin[p][k]*bin[p-k][j-k];
    sign = -sign;
    }
  pk = pk-1;
  }
}
```