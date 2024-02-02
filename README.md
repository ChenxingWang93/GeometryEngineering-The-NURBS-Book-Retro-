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
  - 1.1[Implicit & Parametric Forms](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.1/1.Implicit%20%26Parametric%20Form.md) _隐式 &参数形式_
  - 1.2[Power Basis Form of a Curve](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.2/1.2Power%20Basis%20Form%20of%20a%20Curve.md) _一 曲线 幂基 形式_
  - 1.3[Bezier Curves](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.3/1.3Bezier%20Curves.md) _贝塞尔 曲线_
  - 1.4[Rational Bezier Curves](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.4/1.4Rational%20Bezier%20Curves.md) _有理 贝塞尔 曲线_
  - 1.5[Tensor Product Surfaces](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A1.5/1.5Tensor%20Product%20Surfaces.md) _张量 积 曲面_
    - Exercises
- ***Chapter TWO:*** B-Spline Basis Functions ***B-样条 基础函数***
  - 2.1[Introduction](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A2.1/2.1Introduction.md) _简介_
  - 2.2[Definition and Properties of B-spline Basis Functions](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A2.2/2.2Definition%20and%20Properties%20of%20B-spline%20Basis%20Functions.md) _B-Spline 基础函数的 定义与 属性_
  - 2.3[Derivatives of B-spline Basis Functions](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A2.3/2.3Derivatives%20of%20B-spline%20Basis%20Functions.md) _B-Spline 基础函数的 Derivatives_
  - 2.4[Further Properties of the Basis Functions](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A2.4/2.4Further%20Properties%20of%20the%20Basis%20Functions.md) _基础函数的 近一属性_
  - 2.5[Computational Algorithms](https://github.com/ChenxingWang93/ComputationalGeometry/blob/main/A2.5/2.5Computational%20Algorithms.md) _计算🧮 算法_
- ***Chapter THREE:*** B-Spline Curves and Surfaces ***B-样条 曲线与曲面***
  - 3.1[Introduction]()
  - 3.2[The Definition and Properties of B-spline Curves]() _B-Spline 曲线的 定义与 属性_
  - 3.3[The Derivatives of a B-spline Curve]() _B-Spline 曲线的 衍生物_
  - 3.4[Definition and Properties of B-spline Surfaces]() _B-Spline 曲面的 定义与 属性_
  - 3.5[Derivatives of a B-spline Surface]() _B-Spline 曲面的 衍生物_
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

### 《SISL The SINTEF Spline Library Reference Manual》
### TOC
- ***1 Preface*** 
  -  1.1 The structure of this document _该文档📄 结构_
  -  1.2 The structure of the software package _软件包 结构_
  -  1.3 Licensing information _许可 信息_
- ***2 General Introduction*** 
  - 2.1 C Syntax Used in Manual _手册中的 C 句法_
  - 2.2 Dynamic Allocation in SISL _动态 分配_
  - 2.3 Creating the library _创建 库_
  - 2.4 An Example Program _样例 程序_
  - 2.5 B-spline Curves _B-样条 曲线_
    - 2.5.1 ~~B-spline~~
    - 2.5.2 ~~The Control Polygon~~
    - 2.5.3 ~~The Knot Vector~~
    - 2.5.4 ~~NURBS Surfaces~~
  - 2.6 B-spline Surfaces _B-样条 曲面_
    - 2.6.1 ~~The Basis Functions~~
    - 2.6.2 ~~NURBS Surfaces~~
- ***3 Curve Definition***
  - 3.1 Interpolation ***插入***
    - 3.1.1 Compute a curve interpolating a straight line between two points
    - 3.1.2 Compute a curve interpolating a set of points, automatic parameterization
    - 3.1.3 Compute a curve interpolating a set of points, parameterization as input
    - 3.1.4 Compute a curve by Hermite interpolation, automatic parameterization
    - 3.1.5 Compute a curve by Hermite interpolation, parameterization as input
    - 3.1.6 Compute a fillet curve based on parameter value
    - 3.1.7 Compute a fillet curve based on points
    - 3.1.8 Compute a fillet curve based on radius
    - 3.1.9 Compute a circular fillet between a 2D curve and a circle
    - 3.1.10 Compute a circular fillet between two 2D curves
    - 3.1.11 Compute a circular fillet between a 2D curve and a 2D line
    - 3.1.12 Compute a blending curve between two curves
  - 3.2 Approximation ***近似***
    - 3.2.1 Approximate a circular arc with a curve 
    - 3.2.2 Approximate a conic arc with a curve
    - 3.2.3 Compute a curve using the input points as controlling vertices, automatic parameterization
    - 3.2.4 Approximate the offset of a curve with a curve
    - 3.2.5 Approximate a curve with a sequence of straight lines
  - 3.3 Mirror a Curve ***镜像 一条 曲线***
  - 3.4 Conversion ***转化***
    - 3.4.1 Convert a curve of order up to four, to a sequence of cubic polynomials
    - 3.4.2 Convert a curve to a sequence of Bezier curves
    - 3.4.3 Pick out the next Bezier curve from a curve
    - 3.4.4 Express a curve using a higher-order basis
    - 3.4.5 Express the "i" -th derivative of an open curve as a curve
    - 3.4.6 Express a 2D or 3D ellipse as a curve
    - 3.4.7 Express a conic arc as a curve
    - 3.4.8 Express a truncated helix as a curve
- ***4 Curve Interrogation***
  - 4.1 Intersections
    - 4.1.1 
    - 4.1.2
    - 4.1.3
    - 4.1.4
    - 4.1.5
    - 4.1.6
  - 4.2 Compute the Length of a Curve
  - 4.3 Check if a Curve Closed
  - 4.4 Check if a Curve is Degenerated
  - 4.5 Pick the Parameter Range of a Curve
  - 4.6 Closest Points
    - 4.6.1
    - 4.6.2
    - 4.6.3
    - 4.6.4
    - 4.6.5
  - 4.7 Find the Absolute Extremals of a Curve
  - 4.8 Area between Curve and Point
    - 4.8.1
    - 4.8.2
  - 4.9 Bounding Box
    - 4.9.1
    - 4.9.2
    - 4.9.3 
  - 4.10 Normal Cone
    - 4.10.1 ~~Normal Cone~~
    - 4.10.2 ~~Create &initialize a curve/surface direction instance~~
    - 4.10.3 ~~Find the direction cone of a curve~~
- ***5 Curve Analysis*** 
  - 5.1 Curvature Evaluation
    - 5.1.1 Evaluate the curvature of a curve at given parameter values
    - 5.1.2 Evaluate the torsion of a curve at given parameter values
    - 5.1.3 Evaluate the Variation of Curvature (VoC) of a curve at given parameter values
    - 5.1.4 Evaluate the Frenet Frame (t,n,b) of a curve at given parameter values
    - 5.1.5 Evaluate geometric properties at given parameter values
- ***6 Curve Utilities***
  - 6.1 Curve Object _曲面 对象_
    - 6.1.1
    - 6.1.2
    - 6.1.3 
  - 6.2 Evaluation _评估_
    - 6.2.1
    - 6.2.2
    - 6.2.3
    - 6.2.4
    - 6.2.5
  - 6.3 Subdivision _细分_
    - 6.3.1
    - 6.3.2
    - 6.3.3
    - 6.3.4
    - 6.3.5
    - 6.3.6
  - 6.4 Joining _连接_
    - 6.4.1
    - 6.4.2
  - 6.5 Reverse the Orientation of a Curve
  - 6.6 Extend a B-spline Curve
- ***7 Surface Definition***
  - 7.1 Interpolation _插入_
    - 7.1.1
    - 7.1.2
    - 7.1.3
    - 7.1.4
    - 7.1.5
    - 7.1.6
    - 
  - 7.2 Approximation _近似_
  - 7.3 Mirror a Surface _镜像_
  - 7.4 Conversion _转换_
- ***8 Surface Interrogation***
  - 8.1 Intersection Curves _曲线交点_
  - 8.2 Find the Intersections _找 相交_
- ***9 Surface Analysis***
  - 9.1 Curvature Evaluation _曲率评估_
- ***10 Surface Utilities***
  - 10.1 Surface Object _曲面对象_
  - 10.2 Evaluation _评估_
  - 10.3 Subdivision _细分_
  - 10.4 Picking Curves from a Surface _从曲面 拾取 曲线_
  - 10.5 Pick a Part of a Surface _从曲面上 拾取一个部件_
  - 10.6 Turn the Direction of the Surface Normal Vector __
- ***11 Data Reduction***
  - 11.1 Curves
  - 11.2 Surfaces
- ***12 Tutorial programs***
  - 12.1 Compelling the programs
  - 12.2 Description & commentaries on the sample programs
- ***13 The object viewer program***
  - 13.1 General
  - 13.2 Compiling the viewer
  - 13.3 Command line arguments
  - 13.4 User controls
    - Mouse commands
    - Keyboard commands

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
