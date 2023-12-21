# ComputationalGeometry

|No|Content             |Theme                 |
|--|--------------------|----------------------|
|1 |编程基础、架构师抽象思维|Intro, Programming     |
|2 |图像初步、图像处理     |Image, Image Processing|
|3 |平面图形光栅化        |Rasterization         |
|4 |数据拟合、重心坐标、Poisson图像编辑|Fitting, BarycentricCoord, PoissonImageEditing|
|5 |连续信号的离散采样     |Sampling& Meshes     |
|6 |三角剖分、离散网格曲面  |Meshes-Programming    |
|7 |微分坐标、网格曲面参数化、编程框架介绍  |LaplacianCoordinates, MeshParameterization   |
|8 |离散微分几何、数字几何处理|DiscreteDifferentialGeometry, DigitalGeometryProcessing  |
|9 |计算机动画、仿真动画简介|ComputerAnimation, Animation&Simulation  |
|10|质点-弹簧系统仿真      |Mass-Spring           |
|11|有限元仿真、流体仿真|FEM FluidSimulation       |
|12|其他仿真方法、渲染介绍|MoreSimulation, RenderingBasics|
|13|渲染管线Taichi        |RenderingPipeline     |
|14|OpenGLIntro 明暗着色 纹理映射|OpenGL Shading TextureMapping|
|15|环境映射、法向映射、偏置映射、阴影映射|TextureMapping-2|
|16|可编程渲染管线、GPU着色器|ShaderProgram1|
|17|真实感渲染、渲染方程、光线追踪|RenderingEquation, RayTracing|
|18|光路追踪方法|PathTracing|
|19|辐射度方法、真实感渲染加速方法|Radiosity, Real-timeRendering|
|20|坐标变换、坐标变换复合||
|21|投影变换、四元数、多视点几何|TransformationBasics, Transformation, Projection, Quaternion, Multi-view geometry|
|22|几何建模、计算机辅助几何设计、总结|3DModeling, CAGD, Summary|


[《The NURBS Book 2nd Edition》](https://link.springer.com/book/10.1007/978-3-642-97385-7)
### TOC 
- ***Chapter ONE:*** Curve &Surface Basics ***曲线 与 曲面基础***
  - 1.1[Implicit & Parametric Forms](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.1/1.Implicit%20%26Parametric%20Form.md)
  - 1.2[Power Basis Form of a Curve](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.2/1.2Power%20Basis%20Form%20of%20a%20Curve.md)
  - 1.3[Bezier Curves](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.3/1.3Bezier%20Curves.md)
  - 1.4[Rational Bezier Curves](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.4/1.4Rational%20Bezier%20Curves.md)
  - 1.5[Tensor Product Surfaces](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.5/1.5Tensor%20Product%20Surfaces.md)
    - Exercises
- ***Chapter TWO:*** B-Spline Basis Functions ***B-样条 基础函数***
  - 2.1[Introduction](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A2.1/2.1Introduction.md)
  - 2.2Definition and Properties of B-spline Basis Functions
  - 2.3Derivatives of B-spline Basis Functions
  - 2.4Further Properties of the Basis Functions
  - 2.5Computational Algorithms 
- ***Chapter THREE:*** B-Spline Curves and Surfaces ***B-样条 曲线与曲面***
  - 3.1Introduction
  - 3.2The Definition and Properties of B-spline Curves
  - 3.3The Derivatives of a B-spline Curve
  - 3.4Definition and Properties of B-spline Surfaces
  - 3.5Derivatives of a B-spline Surface
    - Exercises
- ***Chapter FOUR:*** Rational B-spline Curves and Surfaces ***有理B-样条 曲线与曲面***
  - 4.1Introduction
  - 4.2Definition and Properties of NURBS Curves
  - 4.3Derivatives of a NURBS Curve
  - 4.4Definition and Properties of NURBS Surfaces
  - 4.5Derivatives of a NURBS Surface
    - Exercises
- ***Chapter FIVE:*** Fundamental Geometric Algorithms ***基础几何算法***
  - 5.1Introduction
  - 5.2Knot Insertion
  - 5.3Knot Refinement
  - 5.4Knot Removal
  - 5.5Degree Elevation
  - 5.6Degree Reduction
    - Exercises
- ***Chapter SIX:*** Advanced Geometric Algorithms ***高级几何算法***
  - 6.1Point Inversion and Projection for Curves and Surfaces
  - 6.2Surface Tangent Vector Inversion
  - 6.3Transformations and Projections of Curves and Surfaces
  - 6.4Reparameterization of NURBS Curves and Surfaces
  - 6.5Curve and Surface Reversal
  - 6.6Conversion Between B-spline and Piecewise Power Basis Forms
    - Exercises
- ***Chapter SEVEN:*** Conics and Circles ***圆锥曲线与圆***
  - 7.1Introduction
  - 7.2Various Forms for Representing Conics
  - 7.3The Quadratic Rational Bezier Arc
  - 7.4Infinite Control Points
  - 7.5Construction of Circles
  - 7.6Construction of Conics
  - 7.7Conic Type Classification and Form Conversion
  - 7.8Higher Order Circles
    - Exercises 
- ***Chapter EIGHT:*** Construction of Common Surfaces ***共面的构造***
  - 8.1Introduction
  - 8.2Bilinear Surfaces
  - 8.3The General Cylinder
  - 8.4The Ruled Surface
  - 8.5The Surface of Revolution
  - 8.6Nonuniform Scaling of Surfaces
  - 8.7A Three-sided Spherical Surface
- ***Chapter NINE:*** Curve and Surface Fitting ***曲线与曲面拟合***
  - 9.1Introduction
  - 9.2Global Interpolation
  - 9.2.1Global Curve Interpolation to Point Data
  - 9.2.2Global Curve Interpolation with End Derivatives Specified
  - 9.2.3Cubic Spline Curve Interpolation
  - 9.2.4Global Curve Interpolation with First Derivatives Specified
  - 9.2.5Global Surface Interpolation
  - 9.3Local Interpolation
  - 9.3.1Local Curve Interpolation Preliminaries
  - 9.3.2Local Parabolic Curve Interpolation
  - 9.3.3Local Rational Quadratic Curve Interpolation
  - 9.3.4Local Cubic Curve Interpolation
  - 9.3.5Local Bicubic Surface Interpolation
  - 9.4Global Approximation
  - 9.4.1Least Squares Curve Approximation
  - 9.4.2Weighted and Constrained Least Squares Curve Fitting
  - 9.4.3Least Squares Surface Approximation
  - 9.4.4Approximation to Within a Specified Accuracy
  - 9.5Local Approximation
  - 9.5.1Local Rational Quadratic Curve Approximation
  - 9.5.2Local Nonrational Cubic Curve Approximation
    - Exercises
- ***Chapter TEN:*** Advanced Surface Construction Techniques ***高级曲面构造技术***
  - 10.1Introduction
  - 10.2Swung Surfaces
  - 10.3Skinned Surfaces
  - 10.4Swept Surfaces
  - 10.5Interpolation of a Bidirectional Curve Network
  - 10.6Coons Surfaces
- ***Chapter ELEVEN:*** Shape Modification Tools ***形态修改/编辑❓工具🔧***
  - 11.1Introduction
  - 11.2Control Point Repositioning
  - 11.3Weight Modification
  - 11.3.1Modification of One Curve Weight
  - 11.3.2Modification of Two Neighboring Curve Weights
  - 11.3.3Modification of One Surface Weight
  - 11.4Shape Operators
  - 11.4.1Warping
  - 11.4.2Flattening
  - 11.4.3Bending
  - 11.5Constraint-based Curve and Surface Shaping
  - 11.5.1 Constraint-based Curve Modification
  - 11.5.2 Constraint-based Surface Modification
- ***Chapter TWELVE:*** Standards and Data Exchange ***标准 与 数据交换***
  - 12.1Introduction
  - 12.2Knot Vectors
  - 12.3Nurbs Within the Standards
  - 12.3.1IGES
  - 12.3.2STEP
  - 12.3.3PHIGS
  - 12.4Data Exchange to and from a NURBS System
- ***Chapter THIRTEEN:*** B-spline Programming Concepts ***B-样条 编程概念***
  - 13.1 Introduction
  - 13.2 Data Types and Portability
  - 13.3 Data Structures
  - 13.4 Memory Allocation
  - 13.5 Error Control
  - 13.6 Utility Routines
  - 13.7 Arithmetic Routines
  - 13.8 Example Programs
  - 13.9 Additional Structures
  - 13.10 System Structure
 

### Online C++ &coding resources
- [Beginner's Guide to C++](https://www.udemy.com/zh-cn/topic/c-plus-plus/#beginnersguide)
- [C++ language tutorial](https://cplusplus.com/doc/tutorial/)
- [C++ online tutorial](https://www.intap.net/~drw/cpp/index.htm)
- [Programming in C++](https://www.cprogramming.com/tutorial.html)
- [Learncpp](https://www.learncpp.com/)
- [Codeguru](https://www.codeguru.com/)
- [vckbase](http://www.vckbase.com/)
### OpenGL
- [LearnOpenGL](https://learnopengl-cn.readthedocs.io/zh/latest/)
- [LearnOpenGL 英文版](https://learnopengl-cn.github.io/)
- [OpenGL](http://www.opengl.org/)
