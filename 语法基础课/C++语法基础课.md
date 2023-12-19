# 函数
使用“引用”作为函数形参时，可以在函数体内（赋值...）对传入的实参做变换
```c++
int zero(int &a,int &b)
{
	a = 0;
	b = 0;
}

int main()
{
	int a = 1;
	int b = 4;
	zero(a, b);
	cout << a << b
}

>>0 0
```
数组其实就是一种指针,数组的传递属于引用的传递
一维数组作形参时，函数声明可不写明数组的大小，如==int max(int a[]);==但是二维数组做形参时，只能去掉第一个（如==int max(int a\[]\[3])==）
函数可以“初始化”某个形参，当调用函数时没有对应的实参传入时，该值不变；如果有，赋值为传入参数的值，默认值一般放在后面
```c++
void foo(int a, int b = 10)
{
	printf("%d %d \n",a,b);
}

int main()
{
	int a = 3# 	int b = 3;
	foo(a);
	foo(a,b);
}

>>3 10 
>>3 3 
```




static修饰局部变量，相当于一个函数体内的全局变量，**该变量只在第一次进入函数时被初始化**（==可用于计数）==
```c++
int output()
{
	//定义静态变量cnt，只在第一次进入函数时被初始化，其他情况下保留“最新值”
	//该变量作用范围只在output()函数中
	static int cnt = 0;
	cnt++;
	printf("%d ",cnt);
}
int main()
{
	output();
	output();
	output();
	output();
	output();
}

>>1 2 3 4 5
```