### 标准库类型string

#### **使用string库前的声明：**

```c++
#include<string>
using std::string    //string定义在命名空间std中
```



#### **定义和初始化string对象：**

```c++
//定义string对象
string s1;             //默认初始化，s1是一个空字符串
string s2 = s1;	       //拷贝初始化，s2是s1的副本
string s3 = "value"    //拷贝初始化，s3是该字符串字面值的副本
string s4(n,'c')       //直接初始化，s4是由连续n个字符c组成的字符串
string s5("value")     //直接初始化，s5是该字符串字面值的副本

```

#### **string对象的操作**

```c++
s.empty();        //判空
s.size();		  //返回字符个数
s[n];			  //s中第n个字符的引用，n>=0
s1+s2;			  //s1和s2连接
<,<=,>,>=,		  //比较字符顺序
```



#### **读写string对象：**

- 使用标准I/O：cin,cout
- 使用getline（）读取一整行

```getline
getline():
1. <string>中的标准函数getline():
	getline(输入流，暂存字符串，截止标志)
2. 输入流中的getline():
	输入流.getline(字符数组，字符数，截止)  
```



```c++
// I/0操作符读取
//停止读取标志：空白
int main()
{
    string s1,s2;                              //初始化为空字符串
    cin >> s1 >> s2;                           //从命令行窗口读入s1,s2的值，遇到空白停止
    cout << s1 << s2 <<endl;
    return 0;
}

//输入
Hello World
//输出
HelloWorld
```

**读取未知数量的string对象**

​     ==while（cin >> n）==

```c++
//读取未知数量
// cin返回值可用作条件判断
int main()
{
    string word;
    while (cin >> word)			//反复读取直至文件末尾
        cout << word << endl;
    return 0;
}

```

**使用getline读取一整行（截止标志：enter）**

==注意==：getline()得到的string对象不包括最后的enter

```c++
int main()
{
    string line
    while(getline(cin,line))  //每次读入一整行（cin）,赋值给line
        cout << line << endl;
    return;
}
```



课后题：

![屏幕截图 2023-08-23 101257](D:\我的文档\笔记\笔记图片\屏幕截图 2023-08-23 101257.png)

```c++
///练习3.2
///编写一段程序从标准输入中一次读入一整行,然后修改该程序使其一次读入一个词.
#include<iostream>
#include<string>
using namespace std;

//从标准输出中一次读入一整行
int main()
{
	string s1;
	while (getline(cin, s1))
		cout << s1 << endl;
	return 0;
}

//从标准输出中一次读入一个词
int main()
{
    string word;
	while (cin, word)
		cout << s1 << endl;
	return 0;
}
```

```c++
//练习3.3
标准库输入运算符自动忽略字符串开头的空白(包括空格符,换行符,制表符等),从第一个真正的字符开始读起,直到遇见下一处空白为止
getline函数从给定的输入流中读取数据,直到遇到换行符为止,此时换行符也被读取进来,但是并不存储在最后的字符串中.
```

```c++
///练习3.4
///编写一段程序读入两个字符串,比较其是否相等并输出结果.
///如果不相等,输出比较大的那个字符串.改写上述程序,比较输入的两个字符串是否等长,如果不等长,输出长度较大的那个字符串
#include <iostream>
#include <string>
using namespace std;、
//比较大小
void compareString ()
{
    string s1, s2;

    cin >> s1 >> s2;

    if (s1 == s2) {
        cout << "equal" << endl;
    } else if (s1 > s2){
        cout << s1 << endl;
    } else {
        cout << s2 << endl;
    }

}


//比较长度
void compareSize ()
{
    string s1, s2;

    cin >> s1 >> s2;
    if (s1.size() == s2.size()) {
        cout << "equal" << endl;
    } 
    else if (s1.size() > s2.size()) {
        cout << s1 << endl;
    } 
    else {
        cout << s2 << endl;
    }
}


```

```c++
3.5 编写一段程序，从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。然后修改程序，用空格把输入的多个字符串分割开来。
void linkString ()
{
    string word;
    string sum;

    while (getline (cin, word)) {

        sum += word;
        cout << sum << endl;
    }   
}

void spliteString ()
{
    string word;
    string sum;

    while (getline(cin, word)) {
        sum += (word + " ");
        cout << sum << endl;
    }
}

```

