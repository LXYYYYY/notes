# 计算机图形学

## Lecture 02  线性代数	Linear Algebra

### 1. 点乘

-  在2D中： $ \vec a \cdot \vec b = \Big(\begin{matrix}   x_a \\  y_a  \end{matrix}\Big) \cdot \Big(\begin{matrix}   x_b \\  y_b  \end{matrix}\Big) = x_ax_b + y_ay_b$

- 在3D中： $ \vec a \cdot \vec b = \bigg(\begin{matrix}   x_a \\  y_a \\ z_a  \end{matrix}\bigg) \cdot \bigg(\begin{matrix}   x_b \\  y_b \\ z_b  \end{matrix}\bigg) = x_ax_b + y_ay_b + z_az_b$
#### 点乘的作用

  - 求两向量之间的夹角 

    $\vec a \cdot \vec b = ||\vec a || \, || \vec b || \cos\theta$

    $\cos\theta = \frac{\vec a \cdot \vec b}{||\vec a || \, || \vec b || }   $

    对于单位向量之间：$\cos\theta = \vec a \cdot \vec b  $

  - 求一个向量对另一个向量的投影,比如求 $b$ 向量对 $a$ 向量上的投影 $\vec b_\bot$ ,那么 $\vec b_\bot$ 一定和 $\vec a$ 在一个方向上，所以对于 $\vec b_\bot$ 来说一定存在 $\vec b_\bot = k\hat a$ ，那么 $\vec b_\bot$ 的长度 $ k = || \vec b_\bot || = || \vec b ||\cos \theta$

### 2. 叉乘

两个向量叉乘的结果，将会得到一个与此两个向量组成的平面**垂直**的向量。

$a×b = - b × a$

$||a×b|| = ||a|| \, ||b|| \sin\phi$

#### 叉乘的作用

- 可以得到一个三维空间中的直角坐标系。

- 判定左和右

  $a×b$ 为正，则 $a$ 就在 $b$ 的 右侧，为负，则 $a$ 就在 $b$ 的左侧。

- 判定内和外 对于点 $P$ ，和点 $A,B,C$ ,若向量 $\vec {AP}$ 和 $\vec {AB}$ ，$\vec {BP}$ 和 $\vec {BC}$，$\vec {CP}$ 和 $\vec {CA}$ 的结果均为正或者均为负，则 $P$ 点就处于点 $A,B,C$ 构成的三角形内，若结果为0，那内外均可。

### 3. 矩阵

课上说的都会~

