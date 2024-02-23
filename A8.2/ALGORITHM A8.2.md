``` C++
ALGORITHM A8.2
  MakeCornerFilletSurf(C1,C2,C3,Pwij)
    {  /*  Create NURBS corner fillet surface 创建 NURBS 角  */
       /*  Input:  C1,C2,C3 输入 */
       /*  Output: Pwij 输出 */
    1.Compute the common radius and center point of the three boundary arcs.
    2.Using translation, rotation and possibly curve reversal(see Chapter6),position and orient the boundary arcs as in Figure 8.18. Note that, in fact, only C2 must actually be positioned and oriented, as only it is required in order to compute the three control points PT

3.Compute the as described above.
    4.Convert SZ(s,t) from Bezier to power basis form (Eq.[8.17]).
    5.Compute the power basis form of the fillet patch S D = Si o S2(Eqs.[8.277-[8.317)
    6.Convert S'(s,t) to rational Bezier form (Eq.[8.32]and Algorithm A6.2).
    7.Rotate/translate S(s,t) back to the correct location in three- dimensional space(the inverse transformation of Step 2).
}
```
