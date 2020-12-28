# STL源码剖析

## 3	迭代器概念与traits编程技法

迭代器是一种抽象的设计概念，在《Design Patterns》书中对iterator模式定义为：

> 提供一种方法，使之能够已持续巡访某个聚合物（容器）所含的各个元素，而又无需暴露该聚合物的内部表述方式

### 3.1 迭代器思维

STL的中心思想在于：将数据容器（containers）和算法（algorithms）分开，彼此独立设计，最后再用迭代器iterator来将两者结合在一起。

例如对于算法find():

```c++
template <class InputIterator, class T>
InputIterator find(InputIterator first,
                   InputIterator last,
                   const T& value){
    while(first != last && 8first != value)
        ++first;
    return first;
}
```

只要赋予不同的迭代器，find()就可以对不同的容器进行查找操作。

### 3.2	迭代器是一种智能指针

迭代器是一种行为类似于指针的对象，所以类似于指针的内容提领（*操作）和成员访问（->）。

迭代器中最重要的就是对operator*和operator->进行重载。

### 3.3	迭代器相应类别

在C++中并不支持typeof操作，所以对于判断迭代器所指之物类别可以用别的方法：

**利用function template 的参数推导机制**。



