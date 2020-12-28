# 计算机图形学

## Lecture 07-09  着色	Shading  和 局部光照模型(Blinn-Phong 反射模型)

### 光照模型

对于输入的的向量：

- 观测向量  $\vec v$
- 物体表面法向量  $\vec n$
- 光向量  $\vec I$
- 以及物体本身的属性参数

![img](https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/07_01.jpg)

#### 1. 漫反射模型

所谓Lambert漫反射模型其实就是在泛光模型的基础之上增加了漫反射项。漫反射便是光从一定角度入射之后从入射点向四面八方反射，且每个不同方向反射的光的强度相等，而产生漫反射的原因是物体表面的粗糙，导致了这种物理现象的发生。

![img](https://pic2.zhimg.com/80/v2-f9d6487d26325965ac807035cbe9eb9d_720w.jpg)

这种漫反射我们该去怎么模拟呢？首先应该考虑入射的角度所造成的接收到光强的损失，如下图所示：

![img](https://pic4.zhimg.com/80/v2-f9b56bf3a1820ef8a6b6297092a956cf_720w.jpg)

只有当入射光线与平面垂直的时候才能完整的接受所有光的能量，而入射角度越倾斜损失的能量越大，具体来说，我们应该将光强乘上一个![[公式]](https://www.zhihu.com/equation?tex=cos%5Ctheta+%3D+l+%5Ccdot+n)，其中![[公式]](https://www.zhihu.com/equation?tex=l)是入射光方向，![[公式]](https://www.zhihu.com/equation?tex=n)为平面法线方向。

好了！除了入射角度之外，光源与照射点的距离也应该考虑，直观来说，离得越远当然强度也就越弱！具体来说如图所示：

![img](https://pic2.zhimg.com/80/v2-e8049585b53b1b1ab71fe5a7067ffe09_720w.jpg)

图中中心为一个点光源，光线均匀的向周围发射，可以想象光源发射出来的能量其实是一定的，那么在任意两个圈上接受到的能量之和一定相等。而离圆心越远，圆的面积越大，单位面积所接受能量也就越弱，因此会将光强 ![[公式]](https://www.zhihu.com/equation?tex=I) 除上一个 ![[公式]](https://www.zhihu.com/equation?tex=r%5E2)。

**那么可以得到漫反射的表示方法：**

![img](https://pic3.zhimg.com/80/v2-679183b3783819c14b6916ce890f7d9e_720w.jpg)

其中![[公式]](https://www.zhihu.com/equation?tex=k_d)为漫反射系数，![[公式]](https://www.zhihu.com/equation?tex=I)入射光强，![[公式]](https://www.zhihu.com/equation?tex=n%2Cl)分别如图中所示为法线向量和入射方向，max是为了剔除夹角大于90°的光。 **注意漫反射光线强度是与出射方向无关的，因此无论人眼在哪观察接收到的强度都是一样的！** 将环境光与漫反射一起考虑之后：

![img](https://pic2.zhimg.com/80/v2-b2ba12e33e376a09957dda252992d989_720w.jpg)

因为漫反射的存在我们已经能够很明显的看出茶壶的体积感了，但依然感觉不是很真实，因为缺少了高光！即镜面反射，下一节将介绍在Lambert模型之内再加入镜面反射，从而得到Phong模型！

(tips：通过改变漫反射模型的3维反射系数![[公式]](https://www.zhihu.com/equation?tex=k_d)，我们就能够得到物体表面不同的颜色)

#### 2. Phong反射模型

如图所示![[公式]](https://www.zhihu.com/equation?tex=R)为镜面反射方向,![[公式]](https://www.zhihu.com/equation?tex=v)为人眼观察方向。

![img](https://pic1.zhimg.com/80/v2-15a8b2c0a6e065e190603fdf63602d70_720w.jpg)

除了考虑漫反射中提到的光源到反射点的距离![[公式]](https://www.zhihu.com/equation?tex=r)之外，需要注意的是，观察方向在镜面反射时是很重要的，具体来说，只有当观察方向集中在反射方向周围很近的时候才能看见反射光，因此在镜面反射中会考虑 ![[公式]](https://www.zhihu.com/equation?tex=R) 与 ![[公式]](https://www.zhihu.com/equation?tex=v) 的夹角 ![[公式]](https://www.zhihu.com/equation?tex=%5Calpha)。如下式：

![img](https://pic4.zhimg.com/80/v2-61b199802ffde5cd0603ac426c859387_720w.png)

其中![[公式]](https://www.zhihu.com/equation?tex=k_s)为镜面反射系数，![[公式]](https://www.zhihu.com/equation?tex=I)为入射光强，![[公式]](https://www.zhihu.com/equation?tex=r)为光源到入射点距离，注意这里在max剔除大于90°的光之后，我们还乘了一个指数p，添加该项的原因很直接，因为离反射光越远就越不应该看见反射光，需要一个指数p加速衰减

![img](https://pic4.zhimg.com/80/v2-23a1bcca580d90b36364a2c806a76447_720w.jpg)

最后我们把环境光，漫反射光，镜面反射光全部累加得到Phong模型效果：

![img](https://pic4.zhimg.com/80/v2-bf1c2fe5e71588567e00a38fd4d2ceeb_720w.jpg)

可以看出，此时模型其实已经非常接近真实效果了！那么Blinn-Phong反射模型是什么呢？它只是对phong模型计算反射方向与人眼观察方向角度的一个优化！