``` C++
ALGORITHM A12.2
  if (C is rational and System B only represents polynomial)
    {
    Approximate 𝐶;
    return;
    }
  if (𝑝>𝑝_𝑚𝑎𝑥)
    {
    Approximate 𝐶;
    return;
    }
  if (𝑝<𝑝_𝑚𝑖𝑛)
    {
    DegreeElevateCurve(𝐶);      /* to degree 𝑝_𝑚𝑖𝑛 */
    return;
    }
  Let 𝑚 be the minimum order continuity allowed in System B
    for a degree 𝑝 curve.
  Determine the minimum order, 𝑘, of continuity at any
    breakpoint of 𝐶
  if(𝑘<𝑚)
    {
    Approximate 𝐶;
    return;
    }
  Extract the segments of 𝐶 (knot insertion), and convert them
    to the segment coefficients required by System B
    (reparameterization may be necessary).
  If applicable, load the global breakpoints into System B.
  
```
