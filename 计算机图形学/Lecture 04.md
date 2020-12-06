# 计算机图形学

## Lecture 04  变换	Transformation

### 1. 观测变换	View/Camera Transformation 

**MVP变换：Model，View，Projection变换**

**View**即相机位，也就是定义**观测位置**，**观测方向**和**向上方向**。 

而相机的**标准位置**，则处在坐标轴系统中的 $(0,0,0)$ 位置，视角方向沿着 $-z$ 方向看，向上方向为 $y$ 

当相机移动时，所有的物体也会随着相机一起移动，使得永远将相机位作为世界的原点。

​																		**插入图1**

 总结为两点

- 物体会随着相机的变换而变换。即**物体会和相机应用同样的变换**。
- 相机永远是上方向为 $y$ ,看向 $-z$ 的方向。

### 2. 投影变换 Projection transformation

在计算机图形学中，投影分为

- 3D到2D
- 正交投影  **Orthographic projection**
- 透视投影 **Perspective projection**

​                                                                            **插入图2 3**

#### 正交投影  **Orthographic projection**

正交投影的变换

​									插入图4

#### 透视投影 Perspective projection

透视投影

- 在计算机图形中更为常用
- 近大远小



#### 平移

​	对于前面的变换都可以用一个矩阵来做到，但是对于平移却需要新引入一个矩阵相加来做到，那么能否把所有的变换都用同一个系统来表示？

​	即**引入齐次坐标**

#### 齐次坐标  Homogenous Coordinates

对于2D空间上的点和向量，在这里多添加一个维度。

- 2D的点  = $(x,y,1)^T$
- 2D的向量 = $(x,y,0)^T$

那么对于变换形式就可以写成

$\bigg(\begin{matrix}   x' \\  y' \\ w'  \end{matrix}\bigg) = \bigg(\begin{matrix}   1 &0 &t_x \\  0 &1 &t_y \\ 0 &0 &1  \end{matrix}\bigg) \bigg(\begin{matrix}   x \\  y \\ 1  \end{matrix}\bigg) = \bigg(\begin{matrix}   x+t_x \\  y+t_y \\ 1  \end{matrix}\bigg)$

在**齐次坐标**中

$\bigg(\begin{matrix}   x\\  y \\ w  \end{matrix}\bigg)$对应的2D平面中的点就是$\bigg(\begin{matrix}   x/w \\  y/w \\ 1  \end{matrix}\bigg), w ≠ 0$

   