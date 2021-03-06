# 计算机图形学

## Lecture 05  光栅化	Rasterization

### 1. 屏幕上的立方体  Canonical cube to screen

 屏幕(**Screen**)的定义：

- 一个二维的数组
- 数组的大小：屏幕的分辨率
- 一个典型的光栅成像设备

------

光栅 (**Raster**)，在德语中意为屏幕

- 光栅化(**Rasterize**) ，把物体画屏幕上。

------

像素(**Pixel**)

- 对于现在，像素代表了屏幕上的一个小方块，只带有一种颜色
- 像素颜色的构成由红绿蓝构成，表示为(red, green, blue)

------

屏幕空间(**Screen space**)，就是在屏幕上定义一个坐标系，会将屏幕上某个点定义为原点$(0, 0)$，那么像素的坐标就为$(x ,y)$，像素坐标的方位范围则是$(0,0)-(width-1,height-1)$; 而像素实际的中心是$(x+0.5,y+0.5)$,屏幕空间的整个占比为$(0,0)-(width,height)$。   

###  2. 在成像设备上进行光栅化

对于是否在区内部，在就进行光栅化，不在就不需要，可以用双重循环判断点是否在三角形内部。

![scale]( https://github.com/LXYYYYY/notes/raw/master/%E8%AE%A1%E7%AE%97%E6%9C%BA%E5%9B%BE%E5%BD%A2%E5%AD%A6/img/05_01.jpg)