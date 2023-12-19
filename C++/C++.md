# **关键字\__attribute__:**

[__attribute__((constructor))用法解析 - 简书 (jianshu.com)](https://www.jianshu.com/p/dd425b9dc9db)

![image-20231020223859292](D:\My Files\笔记\C++\C++.assets\image-20231020223859292.png)

![image-20231020224020415](D:\My Files\笔记\C++\C++.assets\image-20231020224020415.png)

**DEMO:**

```c++
int main(int argc, char * argv[]) {
    @autoreleasepool {
        printf("main function");
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate 				class]));
    }
}
__attribute__((constructor)) static void beforeFunction()
{
    printf("beforeFunction\n");
}
```

**——运行结果：**

```c++
beforeFunction
main function
```



**声明和实现分离的写法如下(同时指明了先后执行顺序):**

```c++
#include <stdio.h>
#include <stdlib.h>
 
static void before(void) __attribute__((constructor));
 
static void before3(void) __attribute__((constructor(103)));
static void before2(void) __attribute__((constructor(102)));
static void before1(void) __attribute__((constructor(101)));
 
static void before2()
{
	printf("before  102\n");
}
 
static void before1()
{
	printf("before  101\n");
}
 
static void before3()
{
	printf("before  103\n");
}
 
static void before()
{
	printf("before main\n");
}
 
 
int main()
{	
	printf("main\n");
	return 0;
}

```

# C++友元函数和友元类（C++ friend）详解

[C++友元函数和友元类（C++ friend）详解 (biancheng.net)](https://c.biancheng.net/view/169.html)

目的：在类的成员函数外部直接访问对象的私有成员
打个比方，这相当于是说：朋友是值得信任的，所以可以对他们公开一些自己的隐私。使用友元的同时也破坏了类的封装特性，这即是友元最大的缺点。

eg:在类里声明一个普通函数，在 前面加上 friend 修饰，那么这个函数就成了该类的友元。这时这个普通函数可以访问该类的一切成员。

利用 C++ 的 friend 修饰符，可以让一些你设定的函数能够对这些私有或保护数据进行操作。

[详解C++ friend关键字-CSDN博客](https://blog.csdn.net/lwbeyond/article/details/7591415)

友元分为两种：友元函数和友元类。

![image-20231024100206853](D:\My Files\笔记\C++\C++.assets\image-20231024100206853.png)

![image-20231024100257024](D:\My Files\笔记\C++\C++.assets\image-20231024100257024.png)



# STL-优先队列

[【进阶】C++STL之优先队列 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/346966234)

[C++ STL优先队列常用用法_c++ stl 优先队列-CSDN博客](https://blog.csdn.net/cerberux/article/details/51762357)

在优先队列中，元素被赋予优先级。当访问元素时，具有最高优先级的元素最先删除。
可以使用具有默认优先级的已有数据结构；也可以再定义优先队列的时候传入自定义的优先级比较对象；或者使用自定义对象(数据结构)，但是必须重载好< 操作符。

## 头文件

```c++
#include <queue> /* 优先队列需要的头文件 */
```

## 定义方式

```c++
priority_queue <type> name; /* 定义一个最大优先队列 */
priority_queue <type, vector<type>, greater<type> > name; 
/* 定义一个最小优先队列 */

/* 例子 */
priority_queue <int> q;
priority_queue <string, vector<string>, greater<string> > qs;
```

最小优先队列，指保证队首永远是优先级最小的元素的优先队列。

最大优先队列，指保证队首永远是优先级最高的元素的优先队列。

需要注意的是，在定义小根优先队列的时候，greater的“>”和优先队列的“>”中间要有一个空格，否则部分编译器会将其识别为右移符号导致编译错误。

### 优先队列常用定义和重载运算符方法

priority_queue模板原型

```c++
template< class T ,class Sequence=vector<T> ,classCompare=less<typenameSequence::value_type> >class priority_queue;

```



==①默认优先级：==

```c++
#include <queue>
using namespace std;

priority_queue<int> q; 
```

**通过<操作符可知在整数中元素大的优先级高。**



==②传入一个比较函数==，使用functional.h函数对象作为比较函数。

```c++
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;  
```

**此时整数中元素小的优先级高。**



==③传入比较结构体==，自定义优先级。

```c++
#include <queue>
using namespace std;

struct cmp{
    bool operator ()(int a,int b){    //通过传入不同类型来定义不同类型优先级
        return a>b;    //最小值优先
    }
};
/**
struct cmp{
    bool operator ()(int a,int b){
        return a<b;    //最大值优先
    }
};
**/


priority_queue<int, vector<int>, cmp > q;

```



==④自定义数据结构==，自定义优先级。

```c++
#include <queue>
using namespace std;

struct node {
    int priority;
    int value;
    friend bool operator < (const node &a, const node &b) {  
        return a.priority < b.priority;
    }
    /* 这样写也可以
    bool operator < (const node &a) const {
        return priority < a.priority;
    }
    */

};
/**
因为标准库默认使用元素类型的<操作符来确定它们之间的优先级关系。而且自定义类型的<操作符与>操作符并无直接联系，故会编译不过。
struct node {
    int priority;
    int value;
    friend bool operator > (const node &a, const node &b) {   //错误示范
        return a.priority > b.priority;  
    }
};
**/

priority_queue<node> q;

```



## 函数

```text
q.push(x); /* 向优先队列q中插入一个元素x */
q.pop(); /* 删除优先队列队首元素 */
q.top(); /* 访问优先队列的队首元素 */
q.empty(); /* 查询优先队列是否为空 */
q.size()           返回队列中元素的个数
```
