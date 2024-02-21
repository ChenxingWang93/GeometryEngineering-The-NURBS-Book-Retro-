``` C++
ALGORITHM A6.2
  PowerToBezierMatrix(p,M,MI)
    {  /*  Compute inverse of pth-degree Bezier matrix  计算🧮 pth-阶 贝塞尔矩阵*/
       /*  Input:  p,M  */
       /*  Output: MI  */
for (i=0; i<p; i++)  /* Set upper triangle to zero 设定 上 三角 为 0 */
  for (j=i+1; j<=p; j++)   MI[i][j] = 0.0;
/* Set first col, last row, and diagonal 设定 第1☝ 列，最后 行，与对角 */
for (i=0; i<=p; i++)
  {
  MI[i][0] = MI[p][i] = 1.0;
  MI[i][i] = 1.0/M[i][i];
  }
/* Compute remaining elements 计算🧮 剩余 元素 */
k1 = (p+1)/2;   pk = p-1;
for (k=1; k<k1; k++)

  {
  for (j=k+1; j<=pk; j++)
    {
    d = 0.0;
    for (i=k; i<j; i++)  d = d-M[][]*MI[][];
    MI[j][k] = d/M[j][j];
    MI[pk][p-j] = MI[j][k];
    }
  pk = pk-1;
  }
}
```
