# 计算机图形学

## Lecture 03  变换	Transformation

### 1. 2D变换

**缩放：**

![scale]( https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/03_01.jpg)



**翻转：**

![roll](https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/03_02.jpg)

**斜着翻转：**

![scale](https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/03_03.jpg)

**旋转：**

![scale](https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/03_04.jpg)

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

   