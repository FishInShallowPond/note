

# 头文件与类的声明

C与C++：C++将数据和对数据的操作（函数）**封装**在一起，形成class (避免了C中所有函数都能对数据进行操作)

E.G: 数据A表示职工的月薪，函数B用于修改月薪，如果未封装，可能在使用B时“动小手脚”，对不该涨薪的职工加薪（设计模式）

<img src="D:\My Files\笔记\C++\C++面向对象.assets\image-20231021092104484.png" alt="image-20231021092104484" style="zoom:80%;" align = "left"/>

<img src="D:\My Files\笔记\C++\C++面向对象.assets\image-20231021091911806.png" alt="image-20231021091911806" style="zoom:80%;" />

## **调用**

当**调用头文件**时，需要写
``#include "需要调用到的头文件名"``

当**调用标准库**中的文件时，需要写
``#include<需要用到的库文件名>``





## **头文件的防卫式声明格式**

防止调用相同的内容

```c++
//如果 没有定义这个名字，则定义，进入；后序再次调用时，已经定义了，不再进入
#ifndef 头文件名
#define 头文件名
...
...
...

#endif
```



## **头文件（HEADER）的布局**

<img src="D:\My Files\笔记\C++\C++面向对象.assets\image-20231021093215294.png" alt="image-20231021093215294" style="zoom:80%;" align = 'left' />



## class的声明

![image-20231021093412137](D:\My Files\笔记\C++\C++面向对象.assets\image-20231021093412137.png)





## **class template(模板)简介**

```c++
template<typenameT> 
class complex
{
public:
	complex (Tr = 0, Ti = 0): re(r), im(i){ }
	complex &operator + = (const complex&); 
	Treal( ) const {return re;} 
	Timag( ) const {return im; }

private:
	T re,im;
};

friend complex & __doapl ( complex* , const complex&);};
{ 
	complex <double> c1(2.5, 1.5); 
	complex<int> c2(2, 6); 
	. . . 
}
```

```
使用到的原因：有可能申请的是int/float/double的实部虚部，这时候要定义多个类（大部分内容是重复的，仅仅改变了类型）
使用模板——》由用户来决定使用时的类型
<typename T>表示T是一个数据类型
```

## inline(内联)函数

在class内定义的函数称为内联函数（内联函数很好，记住这一点）
但是如何写是一回事，程序运行时是否将其视为incline函数是另一回事
<在class内定义>只是“**推荐”**成为`inline函数`

- 在class内定义函数体
- 在class外定义，但是在函数返回类型前加上` inline `

![image-20231021094308288](D:\My Files\笔记\C++\C++面向对象.assets\image-20231021094308288.png)



## 访问级别

==三种级别：public, private, protect==

数据一般处于private级别（类外部无法访问）——访问数据时只能通过 调用`public`中对应的函数，**不能**直接将 `private` 中的数据拿出来直接用

![image-20231021094734098](D:\My Files\笔记\C++\C++面向对象.assets\image-20231021094734098.png)
