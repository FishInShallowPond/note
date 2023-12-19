## 1.环境的配置

所需要的：
-  python（最好使用anaconda）
-  PyQt5 模块
-  pycharm
---

## 2.开发一个PyQt5的桌面应用：
**<font color = 'red'>注意大小写</font>**

使用的模块：
* PyQt5.QtWidgets
	-  PyQt5.QWidget
	-  PyQt5.QApplication

```python
import sys  
from PyQt5.QtWidgets import QApplication, QWidget  
  
if __name__ == '__main__':  
# 创建QApplication类的实例（固定写法）  
app = QApplication(sys.argv)  
# 创建一个窗口  
w = QWidget()  
# 设置窗口的尺寸  
w.resize(400, 200)
# 移动窗口
w.move(300,300z)
  
# 设置窗口的标题  
w.setWindowTitle('一个pyqt5的桌面应用')  
# 显示窗口  
w.show()  
  
# 进入程序的主循环（通用），并通过exit函数确保主循环安全结束  
# 循环扫描窗口上的所有事件，保持程序不退出  
sys.exit(app.exec_())

```


另一种创建窗口的方式：(主页面)
使用的模块：
* PyQt5.QtWidgets
	-  PyQt5.QMainWindow
	-  PyQt5.QApplication
```python
import sys  
from PyQt5.QtWidgets import QApplication, QMainWindow 
  
if __name__ == '__main__':  
# 创建QApplication类的实例（固定写法）  
app = QApplication(sys.argv)

# 初始化
myWin = MyMainForm()
#设置标题图标  
myWin.setWindowIcon(QIcon('./favicon.ico'))  
# 设置窗口的标题 
myWin.setWindowTitle('一个pyqt5的桌面应用')  
# 将窗口控件显示在屏幕上  
myWin.show() 

# 进入程序的主循环（通用），并通过exit函数确保主循环安全结束  
# 循环扫描窗口上的所有事件，保持程序不退出   
sys.exit(app.exec_())

```

---


## 3.QtDesigner的使用

### 3.1 QtDesigner的安装与配置

anancada下的目录：
Anaconda\\Library\\bin  :designer
![[Pasted image 20230919231044.png]]

==**在pycharm中直接启动QtDesigner: 添加外部工具==**![[Pasted image 20230919231331.png]]
![[Pasted image 20230919231803.png]]

==右键点击项目，即可看到外部工具（或者工具-外部工具）：点击即可启动==
**启动方法1：**====
![[Pasted image 20230919232620.png]]
<font color="#c0504d">**启动方法2**</font>
![[Pasted image 20230919232642.png]]

### 3.2 QtDesigner的简要介绍

启动-新建窗体（一般先创建主窗口）
![[Pasted image 20230920135917.png]]

创建完成后，进入页面，我们先看属性编辑器和窗口部件盒

**窗口部件盒**：
* **布局-间隔控件-按钮控件-视图-窗口-容器-采集输入-演示信息**
![[Pasted image 20230920140525.png]]

**属性编辑器**
从窗口部件盒中拖动一个“部件”到中间的窗口中，可以在属性编辑器中看到对应信息
![[Pasted image 20230920140923.png]]


从窗口部件盒中拖动部件到中间窗口，进行“**设计”**

### 3.3 窗体的切换
#### 3.3.1 由设计模式 转到 预览模式：
![[Pasted image 20230920141119.png]]


#### 3.3.2 查看对应的python代码（可直接运行）
![[Pasted image 20230920141343.png]]

![[Pasted image 20230920141425.png]]


### 3.4 将.ui文件转换为.py文件

什么是.ui文件？
QtDesigner 保存的文件，属于==用户与程序唯一交互的界面==，不能直接在pycharm中使用
每次查看代码-拷贝太麻烦了，如何将这一功能嵌入到Pycharm?
![[Pasted image 20230920142408.png]]
![[Pasted image 20230920142554.png]]

>-方法一：  直接使用python命令（命令行）
   python -m PyQt5.uic.pyuic ```ui文件名``` -o ```转换后的py文件名```   
   -方法二：   在anaconda中pyqt的一个文件（先转到对应路径，同样在命令行中输入）
  pyuic5 ```ui文件名``` -o ```转换后的py文件名```

不使用命令行：**加入到外部工具中**
- 实参：-m PyQt5.uic.pyuic \$FileName\$ -o \$FileNameWithoutExtension\$.py
- 工作目录：\$FileDir\$
- <font color = 'red'>PS：复制时别忘了删转义字符</font>
![[Pasted image 20230920144628.png]]

然后就可以在pycharm中：**右键.ui文件，选择外部工具**，便可以进行转换
<font color = 'red'>注意注意:</font> 不要直接在新生成的这个.py文件上做编辑，会被.ui文件覆盖掉，最好新建一个把代码复制过去


### 3.5 QtDesigner中 布局 的使用

位置：窗口部件图-布局
布局方式：(未按顺序翻译)
>1. 垂直布局、、、
>2. 水平布局
>3. 网格布局
>4. 表单布局


![[Pasted image 20230920145647.png]]


#### 3.5.1水平布局

简介：将所有的部件从左到右按一定的规则排列
使用布局的两种方法：
>1. 先放置部件，在进行布局
>2. 先设置布局，再将部件拖到布局中

``例子：放置五个button，使其等宽水平地排列

##### 方法一：

放置完成后，选中，右键点击
![[Pasted image 20230920150939.png]]

设置成功，保持等宽等距
![[Pasted image 20230920151051.png]]


**设置完成后如何进行整体选中？**

1.左键点击边缘红线拖动（可能不太方便）
2.在对象查看器中选中相应的布局（包含窗口中放置的所有部件对象以及组合）
![[Pasted image 20230920151441.png]]
**<font color = 'red'>注意：</font>整体选中后改变大小，不会改变内部单个部件的大小（不随布局的变化而变化）

##### 方法二

先将布局拖到窗口中
![[Pasted image 20230920152028.png]]

往布局中放部件，然后编辑部件的属性（如名字）
![[Pasted image 20230920152647.png]]
![[Pasted image 20230920152510.png]]

##### 补充[[#3.4 将.ui文件转换为.py文件]] ：如何在pycharm中通过转换得到的.py文件生成窗口

<font color = 'red'>注意注意:</font> 不要直接在新生成的这个.py文件上做编辑，会被.ui文件覆盖掉，最好新建一个把代码复制过去

.ui文件转换得到的.py文件：
![[Pasted image 20230920155145.png]]


新建的run程序：[[#2. 开发一个PyQt5的桌面应用：]]
- 导入相关的模块
- 创建应用和窗口
- 使用模块中的类，调用方法在**指定窗口**中创建部件
- 消除引用的警告：将.py文件设置为源代码根目录（高版本不用）
```python
# run_demo1.py  
  
import sys  
# 导入.py文件名  
import demo1  
  
from PyQt5.QtWidgets import QApplication,QMainWindow  
  
  
if __name__ == '__main__':  
	app = QApplication(sys.argv)  
	mainWindow = QMainWindow()  
  
	# 引用demo1.py中的MainWindow类，创建这个类的实例  
	ui = demo1.Ui_MainWindow()  
	# 调用方法，想主窗口中添加部件(手动输入 传入的窗口对象mainWindow) 
	ui.setupUi(mainWindow)  
  
	# 显示窗口  
	mainWindow.show()  
  
	# 循环扫描窗口上的所有事件，保持程序不退出  
	sys.exit(app.exec_())
```

**界面：**
![[Pasted image 20230920164418.png]]


#### 3.5.2 垂直布局

同样，两种方法：
>1. 先放置部件，在进行布局
>2. 先设置布局，再将部件拖到布局中

还可以和水平布局一起使用：
![[Pasted image 20230920163514.png]]

**代码部分**
![[Pasted image 20230920164204.png]]

```python
# run_vertical_layout  
  
import sys  
import vertical_layout  
from PyQt5.QtWidgets import QApplication,QMainWindow  
  
if __name__ == '__main__':  
	app = QApplication(sys.argv)  
	window = QMainWindow()  
  
	ui = vertical_layout.Ui_MainWindow()  
	ui.setupUi(window)  
  
	window.show()  
	sys.exit(app.exec_())
```

**界面：**
![[Pasted image 20230920164602.png]]


#### 3.5.3 网格布局（grid layout）
同样，两种方法：
>1. 先放置部件，在进行布局
>2. 先设置布局，再将部件拖到布局中

**移动部件到布局中时：**
* 移到布局内的部件的边缘处——出现蓝线
* 移到布局的空白处——出现红框
* **拖动布局内的部件大小即可更改格式（改变行列数）**
![[Pasted image 20230920170101.png]]![[Pasted image 20230920170119.png]]![[Pasted image 20230920170339.png]]


**代码：**
![[Pasted image 20230920170707.png]]

```python
# run_grid_layout  
import sys  
import grid_layout  
from PyQt5.QtWidgets import QApplication,QMainWindow  
  
if __name__ == '__main__':  
	app = QApplication(sys.argv)  
	window = QMainWindow()  
	ui = grid_layout.Ui_MainWindow()  
  
	ui.setupUi(window)  
  
	window.show()  
	sys.exit(app.exec_())
```

生成窗口展示
![[Pasted image 20230920172328.png]]

我们发现窗口部件显示不全，变形
解决方案：**拖动，重新保存，重新.py**