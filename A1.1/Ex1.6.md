Ex1.6🚩🚩🚩🚩🚩🚩

### n = 3.

```
𝙲(𝚞) = (𝟷-𝚞)^𝟹𝙿_{𝟶} + 𝟹𝚞(𝟷-𝚞)^𝟸𝙿_{𝟷} + 𝟹𝚞^{𝟸}(𝟷-𝚞)𝙿_{𝟸} + 𝚞^{𝟹}𝙿_{𝟹}
```

Examples of cubic Bézier curves are shown in 

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/b6145ddd-728e-4892-9edf-0c946f05c6a7)

Figures 1.11a

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/94c55c9c-530a-4d7d-a7c2-b1e262dd4123)

Figures 1.11b

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/92bdee0b-8845-42ea-8592-f6a078d91222)

Figures 1.11c

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/5247511e-7426-477a-87b4-431c35766c96)

Figures 1.11d

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/39590fa6-2426-4671-9fe7-6c868ea3397e)

Figures 1.11e

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/ff8bb153-ea74-4300-aec3-1c7221fc540c)

Figures 1.11f

- the control polygons approximate the shapes of the curves;

```
- 𝙿_{𝟶} = 𝙲(𝟶) & 𝙿_{𝟹} = 𝙲(𝟷)
```
- the endpoint tangent directions are parallel to `𝙿_{1} - 𝙿_{𝟶}` & `𝙿_{𝟹} - 𝙿_{𝟸}`;
- convex hull property: the curves are contained in the convex hulls of their defining control points

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/92bdee0b-8845-42ea-8592-f6a078d91222)

Figures 1.11c

- variation diminishing property: no straight line intersects a curve more times than it intersects the curve's control polygon(for a three-dimensional Bezier curve, replace the word 'straight-line' with the word 'plane').
  This expresses the property that a Bezier curve follows its control polygon rather closely and does not wiggle more than its control polygon

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/ff8bb153-ea74-4300-aec3-1c7221fc540c)

Figures 1.11f;

- initially (at 𝚞 = 𝟶) the curve is turning in the same direction as `𝙿_{𝟶}𝙿_{1}𝙿_{𝟸}`. At 𝚞 = 𝟷 it is turning in the direction `𝙿_{1}𝙿_{𝟸}𝙿_{𝟹}`;
- a loop in the control polygon may or may not imply a loop in the curve. The transition between

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/39590fa6-2426-4671-9fe7-6c868ea3397e)

Figures 1.11e

&

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/ff8bb153-ea74-4300-aec3-1c7221fc540c)

Figures 1.11f

is a curve with a cusp.
