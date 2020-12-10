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

![scale]( https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/04_04.jpg)

#### 透视投影 Perspective projection

透视投影

- 在计算机图形中更为常用
- 近大远小

### 3D变换

缩放与位移变换:

![scale]( https://img-blog.csdnimg.cn/20200715152734485.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

旋转变换：

![scale]( https://img-blog.csdnimg.cn/20200715152748686.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

欧拉角：

![scale]( https://img-blog.csdnimg.cn/20200715152805402.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

![scale](https://img-blog.csdnimg.cn/20200715152816580.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

#### 视角变换（view tranformation）

想要知道眼睛与物体的相对位置，已知眼睛的位置与物体的位置，将眼睛移动到原坐标系的原点，那么此时物体的坐标自然便是相对坐标了！
我们先定义3个东西：**眼睛的位置e**，**观察方向g**，**视点正上方向t**

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715153443548.png)

其中u，v，w分别对应标准坐标系下的x，y，z，示意图如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715153515272.png)
(tips:这里为什么不直接拿 t 当做基底向量是因为摄像机的头可能是歪着看的，就像图中一样 )
接下来将其移动到原世界坐标系

1. 将相机移动到原点
2. 通过旋转矩阵将二者坐标系重合
   ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715153634108.png)
   （本文中所有矩阵都是左乘），最右边的矩阵代表第一步操作移至原点，旁边那个矩阵则代表第二步操作将坐标系重合。

#### 投影变换（projection tranformation)

##### 正交投影变换(Orthographic Projection Transformation)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715160403513.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)
M正交投影是相对简单的一种，坐标的相对位置不变，相当于平行映射，我们只需要物体（可视部分，即上图的那个长方体）全部转换到一个[−1,1] ^3的空间之中即可（其中x，y坐标便是投影结果，保留z是为了之后的遮挡检测）
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715160720240.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715161141806.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

##### 透视投影变换(Perspective Projection Transformation)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715153932576.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)
透视投影就是好比人眼看东西，遵循近大远小的规则。如下图，左图为透视，右图为正交。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715154124378.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)
投影过程如下：(x,y,z)->(x’,y’,z’)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715154255363.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715155530110.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)
设投影矩阵为M，即：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715155644882.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)
（如果形象化的描述一下的话，就是利用这个变换矩阵将整个空间压缩了一下，使其对应了真正透视投影的坐标，最后不要忘了要利用正交转换到[−1,1]3[-1,1]^3[−1,1]3的空间之内）

首先，这个矩阵的前两行和最后一行是能很快确定出来的，根据最后的齐次坐标，如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715155737444.png)

对于矩阵的第三行，这里就要运用透视投影的一个性质：投影前后z坐标不变

1. Any point on the near plane will not change
2. Any point’s z on the far plane will not change

将n，f带入式中
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020071516001642.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715160105930.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020071516012287.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)
最后矩阵为：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715160228866.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

最后将将这个被压缩过的空间，重新正交投影成标准小立方体，故定义透视投影变换如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715161408513.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715161426752.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3doeTE4NzY3MTgzMDg2,size_16,color_FFFFFF,t_70)

#### 视口变换(viewport transformation)

这一步就很简单了，一开始也介绍过就是两个范围空间的转换[−1,1] ^2→[0,width]∗[0,height],在正交变换一节已详细解释清楚，这里直接套公式即可
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020071516160955.png)