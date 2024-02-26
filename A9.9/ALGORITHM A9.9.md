``` C++
ALGORITHM A9.9
RemoveKnotBoundCurve(n,p,U,P,ub,ek,E,nh,Uh,Ph)
  {  /*  Remove knots from curve, bounded 从曲线中移除 结点，形成的边界 */
     /*  Input:  n,p,U,P,ub,ek,E 输入 */
     /*  Output: ek,nh,Uh,Ph 输出 */
  Inf = ∞;    /* Big number */
  Get the values Br for all distinct interior knots (A9.8)
  For each basis function, get range of parameter indices.
  while (1)
    {
    Find knot with the smallest Br bound.  Set r and s.
  if (Br == Inf)  break;   /* Finished */
  Using Eqs.(9.81),(9.83), and Algorithm A2.4 to compute
      NewError[k], from temp[k] = ek[k]+NewError[k] at
      all ub[k] values falling within the relevant domain.
  If knot is removable   /* All temp[k] <= E */
    {
    Update ek[] :  ek[k] = temp[k] for relevant range.
    Call routine similar to A5.8 to remove knot
        (remove without tolerance check).
    If no more internal knots, break.   /* Finished */
    Using Eq.(9.84), compute new index ranges for
        affected basis functions.
    Using Eq.(9.85), compute new error bounds for the
        relevant knots.
    }
    else
    {
    Set this Br to Inf
    }
  }
}
```
