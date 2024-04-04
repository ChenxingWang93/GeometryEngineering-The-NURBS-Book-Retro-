``` C++
ALGORITHM A5.3
  SurfaceKnotIns(np,p,UP,mp,q,VP,Pw,dir,uv,k,s,r,nq,UQ,mq,VQ,Qw)
    {  /*  Surface knot insertion 曲面 结点 插入 */
       /*  Input:  np,p,UP,mp,q,VP,Pw,dir,uv,k,s,r 输入 */
       /*  Output: nq,UQ,mq,VQ,Qw 输出 */
    if (dir == U_DIRECTION)
{
load u-vector as in A5.1
copy v-vector into VQ
    /* Save the alphas 保存 阿尔法 */
for (j=1; j<=r; j++)
  {
  L = k-p+j;
  for (i=0; i<=p-j-s; i++)
    alpha[i][j] = (uv-UP[L+i])/(UP[i+k+1]-UP[L+i]);
  }
for (row=0; row<=mp; row++)   /* For each row do 每行 执行 */

{
      /* Save unaltered control points 保存 未改变的 控制点 */
for (i=0; i<=k-p; i++)   Qw[i][row] = Pw[i][row];
for (i=k-s; i<=np; i++)   Qw[i+r][row] = Pw[i][row];
      /* Load auxiliary control points 加载 辅助的 控制点 */
for (i=0; i<=p-s; i++)   Rw[i] = Pw[k-p+i][row];
for (j=1; j<=r; j++)   /* Insert the knot r times 插入 结点 r 次 */
  {
  L = k-p+j;    
  for (i=0; i<=p-j-s; i++)
  Rw[i] = alpha[i][j]*Rw[i+1] + (1.0-alpha[i][j])*Rw[i];
Qw[L][row] = Rw[0];
Qw[k+r-j-s][row] = Rw[p-j-s];
}
    /* Load the remaining control points 加载 剩余 控制点 */
for (i=L+1; i<k-s; i++) Qw[i][row] = Rw[i-L];
}
  }
if (dir == V_DIRECTION)
  {
  Similar code as above with u- and v-directional
    parameters switched.
  }
}
```