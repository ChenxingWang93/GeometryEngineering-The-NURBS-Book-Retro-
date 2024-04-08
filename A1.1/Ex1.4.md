<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.3.2/jquery.min.js"></script>
<script src="jquery.jslatex.js"></script>
<script>
$(function () {
    $(".latex").latex();
});
</script>
<p>
    Ex1.4🚩🚩🚩🚩
</p>
<p>
    n = 1
</p>
<p>
    An nth-degree Bezier curve is defined by
</p>

~~![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/0b07e0f6-e31a-4530-b094-b1f4099400f3)~~

Figure 1.8. Cubic curves. (a) Three-dimensional twisted;

~~![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/a54b2f8e-22e2-461e-9d21-67e50538acad)~~

(b) Inflection point;

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/33f1ecc1-53e4-414b-9c12-520470d2a298)

(c) Cusp;

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/ccd9fbad-22c8-403f-80b0-dde92a454b6d)

(d) Loop.

该形式的几何系数 the geometric coefficients of this form, are called control points.

<img width="250" alt="image" src="https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/8d842894-eaa9-45cd-8c8e-b167692646c3">

Eq.(𝟷.𝟾)

𝑢 ∊ [𝟶,𝟷].

𝙱_{𝟶,𝟷}(𝚞) = 𝟷 - 𝚞
𝙱_{𝟷,𝟷}(𝚞) = 𝚞;

Eq.(𝟷.𝟽)

𝙲(𝚞) = (𝟷 - 𝚞)𝚸_{𝟶}+𝚞𝚸_{𝟷}

![image](https://github.com/ChenxingWang93/ComputationalGeometry/assets/31954987/cfd54eb8-cbcb-489f-a9ac-5bdca306da0d)

a straight line segment from 𝚸_{𝟶} to 𝚸_{𝟷}