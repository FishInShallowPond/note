<img src="D:\My Files\笔记\TCPIP网络编程.assets\image-20231104213524634.png" alt="image-20231104213524634" style="zoom:80%;" />



网络编程：编写程序使两台联网的计算机相互交换数据
前提：物理连接 + 软件设备（==套接字==）
**套接字含义：用来连接该网络的工具**

[Windows编程-6.网络编程-酷编程 (kucoding.com)](https://www.kucoding.com/article/90)

#### 接受连接请求的套接字的创建过程

**创建用于接听的电话套接字：**

1. 使用 ` socket `函数 安装 “电话机”（**创建套接字**）

```C++
// 调用socket函数（安装电话机）
#include<sys/socket.h>
int socket(int domain, int type, int protocol);

//成功时返回文件描述符，失败时返回-1
```

2.使用 `bind` 函数分配 ”电话号码“（**给创建好的套接字分配地址信息——IP地址和端口号**）

```c++
#include<sys/socket.h>
int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);

// 成功时返回0，失败时返回-1
```

3.使用 `listen` 函数连接“电话线”（**将套接字转化为可接受连接的状态**）

```c++
#include<sys/socket.h>
int listen(int sockfd, int backlog);

// 成功时返回0，失败时返回-1
```

4.使用 `accept` 函数“拿起话筒”（**接受连接请求**）

```c++
#include<sys/socket.h>
int accept(int sockfd, struct sockaddr * addr, socklen_t *addrlen);

// 成功时返回文件描述符，失败时返回-1
```



综上所述：网络中接受连接请求的套接字创建过程如下：

- 调用 `socket` 函数创建套接字

- 调用 `bind` 函数分配IP地址和端口号
- 调用 `listen` 函数转为可接受请求状态
- 调用 `accept` 函数受理连接请求

#### 编写“hello world”服务器端

==该服务器端收到连接请求后向请求者返回“hello world”答复==

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[]="Hello World!";
	
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	// socket
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(atoi(argv[1]));
	// bind
	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1 )
		error_handling("bind() error"); 
	//listen
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");
	//accept
	clnt_addr_size=sizeof(clnt_addr);  
	clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);
	if(clnt_sock==-1)
		error_handling("accept() error");  
	
	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);	
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);

```



#### 编写向服务器端发生连接请求的的客户端

客户端程序的步骤：

- 调用socket函数创建套接字
- 调用connect函数向服务器端发送连接请求

**主要任务**：调用socket函数和connect函数；与服务器端共同运行以收发字符串数据

**创建客户端套接字：**

```c++
#include<sys/socket.h>
int connect(int sockfd, struct sockaddr *asrv_addr, socklen_r addlen);

// 成功时返回0，失败时返回-1
```

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	char message[30];
	int str_len;
	
	if(argc!=3){
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	sock=socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));
		
	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1) 
		error_handling("connect() error!");
	
	str_len=read(sock, message, sizeof(message)-1);
	if(str_len==-1)
		error_handling("read() error!");
	
	printf("Message from server: %s \n", message);  
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);

```



#### 开发服务器

开发服务器主要的流程和其用到的函数如下：

1. 网络环境初始化：`WSAStartup`
2. 创建服务器套接字：`socket`
3. 绑定本机IP和端口：`bind`
4. 监听客户端：`listen`
5. 等待客户端连接：`accept`
6. 发送消息：`send`
7. 接收消息：`recv`
8. 关闭socket：`closesocket`
9. 清除网络环境：`WSACleanup`



##### **WSAStartup函数**

**函数功能**：==打开网络库/启动网络库==，启动了这个库，这个库里的函数/功能才能使用。

**解释：**

- W：windows
- S：socket
- A：Asynchronous 异步
  - 同步：阻塞、卡死状态
  - 异步：多个工作同时进行
- Startup：启动

**函数原型**

```c++
int WSAAPI WSAStartup(
  WORD      wVersionRequested,  //版本号，使用MAKEWORD宏生成
  LPWSADATA lpWSAData           //数据，指向WSADATA结构体的指针
);
//返回值：0代表成功，否则失败
```

**函数的使用实例**

```c++
#include<WinSock2.h>
#include<iostream>
#pragma comment(lib,"ws2_32")
using namespace std;
int main() {
	WSADATA data;
	int ret=WSAStartup(MAKEWORD(2,2),&data);
	if (ret) {
		cout << "初始化网络错误！" << endl;
		return -1;
	}
}
```



##### socket函数

**函数功能**：创建套接字

**函数原型：**

```c++
SOCKET socket(
int af,	//地址类型，常用IPv4地址：AF_INET，和IPv6地址：AF_INET6
int type, //套接字类型，常用TCP协议：SOCK_STREAM,UDP协议;SOCK_DGRAM
int protocol //协议类型，一般填0，自动选择即可
);
//返回值，INVALID_SOCKET失败，该宏实则定义为-1，否则成功
```

**函数使用**

```c++
SOCKET sock=socket(AF_INET,SOCK_STREAM,0);
if (sock == -1) {
	cout << "创建套接字失败";
	return -1;
}
```



##### bind函数

**函数功能**：为套接字分配 **IP** 和 **端口**

**函数原型：**

```c++
int bind( 
SOCKET s, //创建的socket
sockaddr * name, //包含地址和端口的结构体
int namelen //sockaddr 结构长度
);
//返回值：返回SOCKET_ERROR失败，该宏被定义为-1，否则成功，返回值为0

```

**函数使用：**

```c++
#define _WINSOCK_DEPRECATED_NO_WARNINGS //vs环境下必须定义，否则无法使用inet_addr函数
sockaddr_in addr;
addr.sin_family = AF_INET; //地址为IPv4协议
addr.sin_port = htons(9999); //端口为9999
addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //绑定到本机的ip地址
ret=bind(sock,(sockaddr*)&addr, sizeof(addr)); //绑定
if (ret == -1) {
	cout << "绑定地址端口失败";
	return -1;
}

```

##### listen函数

**函数功能**：监听客户端

**函数原型**

```c++
int listen(
SOCKET s, //要监听的socket
int backlog //等待连接的最大队列长度
);
//返回值：返回SOCKET_ERROR失败，该宏被定义为-1，否则成功，返回值为0
```

**函数使用**

```c++
ret=listen(sock,5);
if (ret == -1) {
	cout << "监听套接字失败";
	return -1;
}
```



##### accept函数

**函数功能**：等待客户端连接

**函数原型**

```c++
SOCKET accept(
SOCKET s, //接收的socket
sockaddr* addr, //接收到客户端的地址信息
int * addrlen //地址信息长度
);
//返回值：返回INVALID_SOCKET失败，该宏定义为-1，否则成功返回客户端的套接字，可进行发送和接收消息
```

**函数使用**

```c++
sockaddr addrCli;
int len = sizeof(addrCli);
SOCKET sockCli=accept(sock,&addrCli,&len);
if (sockCli == -1) {
	cout << "接收客户端连接失败";
	return -1;
}
```



##### send函数

**函数功能**：发送消息

**函数原型**

```c++
int send(
SOCKET s,
char * buf,//要发送的内容
int len, //内容长度
int flags //一般为0，拷贝到程序中就立即删除内核中的数据,或MSG_DONTROUTE:要求传输层不要将数据路由出去，MSG_OOB：标志数据应该被带外发送
);
//返回值：-1（或宏SOCKET_ERROR）表示发送失败，否则返回发送成功的字节数
```

**函数使用**

```c++
char buf[0xFF] = "我是服务器";
ret=send(sockCli, buf, strlen(buf),0);
if (ret == -1) {
	cout << "发送信息失败";
}
```



##### recv函数

**函数功能**：接受消息

**函数原型**

```c++
int recv(
SOCKET s, //套接字
 char * buf, //接受数据的缓存区
int len, //缓存区大小
int flags //标志，一般填0，将消息拷贝到应用程序中，将内核中的数据删除，还可以填MSG_PEEK,只取数据，不从内核中删除数据，MSG_OOB：处理带外数据
);
//返回值：小于等于0都表示出错，大于0则表示接收成功的数据大小
```

**函数使用**

```c++
ret=recv(sockCli,buf,0xFF,0);
if (ret <= 0) {
	cout << "接受客户端数据失败";
	return -1;
}
```



**closesocket函数**

**函数功能**：关闭不用的 `socket`，用来释放资源

**函数原型**

```c++
int closesocket(
SOCKET s //要关闭的socket
);
```



**WSACleanup函数**

**函数功能**：清理WSA，清除网络环境

**函数原型**

```c++
WSACleanup();
```



---



#### 开发客户端程序

客户端的流程比服务器要简单一些，且很多函数也都是通用的：

1. 初始化网络环境：`WSAStartup`
2. 创建套接字：`socket`
3. 连接服务器：`connect`
4. 发送数据：`send`
5. 接收数据：`recv`
6. 清理网络环境：`WSACleanup`

这里只是多出了个`connect`函数，但其使用方法其实与`bind`函数也是类似的。

##### connect函数

**函数功能**：连接到服务器

**函数原型：**

```c++
int connect(
SOCKET s, //与服务器连接的socket
sockaddr* name, //服务器的地址端口
int namelen //上个参数结构体的长度
);
//返回值：-1失败，否则成功

```

**函数使用：**

```c++
sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(9999);
addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
int ret = connect(sock, (sockaddr*)&addr, sizeof(addr));
if (ret == -1) {
	cout << "连接服务器失败" << endl;
	return -1;
}

```

