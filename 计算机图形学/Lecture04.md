# 计算机图形学

## Lecture 04  变换	Transformation

### 1. 观测变换	View/Camera Transformation 

**MVP变换：Model，View，Projection变换**

**View**即相机位，也就是定义**观测位置**，**观测方向**和**向上方向**。 

而相机的**标准位置**，则处在坐标轴系统中的 $(0,0,0)$ 位置，视角方向沿着 $-z$ 方向看，向上方向为 $y$ 

当相机移动时，所有的物体也会随着相机一起移动，使得永远将相机位作为世界的原点。

![scale]( https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/04_01.jpg)

 总结为两点

- 物体会随着相机的变换而变换。即**物体会和相机应用同样的变换**。
- 相机永远是上方向为 $y$ ,看向 $-z$ 的方向。

### 2. 投影变换 Projection transformation

在计算机图形学中，投影分为

- 3D到2D
- 正交投影  **Orthographic projection**
- 透视投影 **Perspective projection**

​                                                                      ![scale]( https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/04_02.jpg)

![scale]( https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/04_03.jpg)

#### 正交投影  **Orthographic projection**

正交投影的变换

​									![scale]( https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/04_04.jpg)

#### 透视投影 Perspective projection

透视投影

- 在计算机图形中更为常用
- 近大远小

   