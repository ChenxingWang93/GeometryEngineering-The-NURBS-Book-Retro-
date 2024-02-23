``` C++
ALGORITHM A9.6
  WCLeastSquaresCurve(Q,r,Wq,D,s,I,Wd,n,p,U,P)
    {  /*  Weighted & constrained least squares curve fit   */
       /*  Input:  Q,r,Wq,D,s,I,Wd,n,p  */
       /*  Output: U,P  */
    ru = -1;    rc = -1;
    for (i=0; i<=r; i++)
      if (Wq[i] > 0.0)   ru = ru+1;
        else             rc = rc+1;
    su = -1;    sc = -1;
}
```
