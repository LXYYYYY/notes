# MY 1st STL

## Allocate

#### **typename**:

将allocator_type中的value_type嵌套类型定义一个叫做value_type的别名,告诉编译器其是类型而不是变量

```c++
typedef typename allocator_type::value_type      value_type;
```

#### **noexcpet**:

```c++
vector() noexcept { //noexcept表示不会抛出异常，利于编译器对程序做更多的优化
			try_init();
		}
```

#### **explicit**：

使用了explicit关键字，则该构造函数无法进行隐式转换。

```c++
explicit vector(size_type n) {
			fill_init(n, size_type());
		}
```

#### C++11新特性--std::enable_if和SFINAE

 SFINAE是英文Substitution failure is not an error的缩写，意思是匹配失败不是错误。当调用模板函数时编译器会根据传入参数推导最合适的模板函数，在这个推导过程中如果某一个或者某几个模板函数推导出来是编译无法通过的，只要有一个可以正确推导出来，那么那几个推导得到的可能产生编译错误的模板函数并不会引发编译错误。

#### delete 和 deallocate 的区别

delete是释放动态内存，即成员函数中 new的动态内存。

deallocate是释放对象内存，即成员所占的内存。

#### 右值引用&&

右值引用就是对右值进行引用操作。例子如下：

```c++

int a = 1;
//int& b = a + 2; //error
int&& b = a + 2;

```

我们使用两个与符号表示右值引用，从上面的例子中可以看出，普通的引用的等号右侧不可以是一个右值，而右值引用的左侧必须是一个右值。那么中间道理发生了什么呢？其实右值引用指向的是将要销毁的对象，也就是前面提到的a+2产出的临时对象，在对象销毁之前该引用可以接管其资源。

**而对于move：**

我们可以显式的使用move将一个左值转换为对用的右值引用类型。如下：

```c++
int a = 1;
int&& b = std::move(a);
```

总结出来move的概念其实很简单，就一句话：将一个左值转换为对用的右值引用类型。

这里需要注意一点的就是，右值引用的是将要销毁的对象，使用move调用意味着告诉编译器我们有一个左值，但想像右值一样使用，所以调用move后原来的对象除了赋值和销毁它外不能有其他的操作（书上是这么说的，但是测试的时候未发现问题）。

### 强制类型转换运算符

c++除了能使用c语言的强制类型转换外，还新增了四种强制类型转换：static_cast、dynamic_cast、const_cast、reinterpret_cast，主要运用于继承关系类间的强制转化，语法为：

```c++
static_cast<new_type>      (expression)
dynamic_cast<new_type>     (expression) 
const_cast<new_type>       (expression) 
reinterpret_cast<new_type> (expression)
```

#### static_cast

static_cast相当于传统的C语言里的强制转换，该运算符把expression转换为new_type类型，用来强迫隐式转换，例如non-const对象转为const对象，编译时检查，用于非多态的转换，可以转换指针及其他，但*没有运行时类型检查来保证转换的安全性*。它主要有如下几种用法：

①用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。

*进行上行转换（把派生类的指针或引用转换成基类表示）是**安全**的；*

*进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是**不安全**的。*

②用于基本数据类型之间的转换，如把int转换成char，把int转换成enum。这种转换的安全性也要开发人员来保证。

③把空指针转换成目标类型的空指针。

④把任何类型的表达式转换成void类型。

**注意：static_cast不能转换掉expression的const、volatile、或者__unaligned属性。**

例如： 

```c++
char a = 'a';
int b = static_cast<char>(a);//正确，将char型数据转换成int型数据

double *c = new double;
void *d = static_cast<void*>(c);//正确，将double指针转换成void指针

int e = 10;
const int f = static_cast<const int>(e);//正确，将int型数据转换成const int型数据

const int g = 20;
int *h = static_cast<int*>(&g);//编译错误，static_cast不能转换掉g的const属性
```

类上行和下行转换：

```c++
if(Derived *dp = static_cast<Derived *>(bp)){//下行转换是不安全的
  //使用dp指向的Derived对象  
}
else{
  //使用bp指向的Base对象  
}

if(Base*bp = static_cast<Derived *>(dp)){//上行转换是安全的
  //使用bp指向的Derived对象  
}
else{
  //使用dp指向的Base对象  
}
```

#### forward关键字

保持住参数的右值属性。实现了参数在传递过程中保持其值属性的功能，即若是左值，则传递之后仍然是左值，若是右值，则传递之后仍然是右值。

#### ptrdiff_t类型

ptrdiff_t是C/C++标准库中定义的一个与机器相关的数据类型。ptrdiff_t类型变量通常用来保存两个指针减法操作的结果。

```c++
int *a=new int(1);
    int *b=new int(2);
    ptrdiff_t result=a-b;

    cout<<a<<ends<<b<<ends<<result<<endl;
000F8F08
000F8F38
-12
```

可以看出，**2个指针相减等于（地址相减的值)/指针所指向的数据类型**。