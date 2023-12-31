# Visual Studio使用教程

## visual studio常用快捷命令

### **常用：**

>| 快捷键              | 备注                                                         |
>| ------------------- | ------------------------------------------------------------ |
>| ctrl + ,            | 搜索文件或函数或变量 或者 编辑->定位到 注意：, 对应 < 那个按键上的 c，c逗号，而不是"那个键的逗号 ctrl + g : 定位到行 或者 编辑->转到 |
>| ctrl + -            | 返回到上一次光标浏览 注意：- 号不是小键(数字)盘上的那个键    |
>| ctrl + +            | 返回到后一次光标浏览 注意：+ 号不是小键(数字)盘上的那个键    |
>| ctrl + c            | 复制光标所在行 注意：只需要光标在这一行，不需要选中整行      |
>| ctrl + x            | 剪切光标所在行 注意：只需将光标移至该行，不需要选中整行      |
>| ctrl + l(注意是L键) | 删除光标所在行 注意：只需将光标移至该行，不需要选中整行      |
>| **ctrl + k + c**    | **注释所选代码或光标所在行 注意：先按k,再按c 或者 ctrl+k,ctrl+c** |
>| **ctrl + k + u**    | **取消注释所选代码或光标所在行 注意：先按k,再按u 或者 ctrl+k,ctrl+u** |
>| **ctrl + f**        | **在本文件中查找**                                           |
>| ctrl + h            | 在本文件中替换                                               |
>| f12                 | 转到定义 , 如想查找Connect函数在哪里定义，可以双击选中，然后f12 |
>| shift + f12         | 查找所有引用 。如想查找Connect函数在哪些地方调用了，可以选中 Connect，然后shift+f12 |
>| **f5**              | **开始运行 或者 开始调试**                                   |
>


### **一、文件相关**
>
>| 快捷键                 | 备注              |
>| ---------------------- | ----------------- |
>| Alt + F                | 打开文件窗口      |
>| Ctrl + Shift + N       | 新建项目          |
>| Ctrl + N               | 新建文件          |
>| Ctrl + Shift + O       | 打开项目/解决方案 |
>| Ctrl + Shift + Alt + O | 打开文件夹        |
>| Shift + Alt + O        | 打开网站          |
>| Ctrl + O               | 打开文件          |
>| **Ctrl + S**           | **保存单个文件**  |
>| Ctrl + Shift + S       | 全部保存          |
>| Ctrl + P               | 打印              |
>| Alt + F4               | 退出              |
>
>


### **二、编辑搜索相关**
>Ctrl + Enter = 在当前行插入空行
>Ctrl + Shift + Enter = 在当前行下方插入空行
>Ctrl +空格键 = 使用IntelliSense（智能感知）自动完成
>Alt + Shift +箭头键(←,↑,↓,→) = 选择代码的自定义部分
>Ctrl + } = 匹配大括号、括号
>Ctrl + Shift +} = 在匹配的括号、括号内选择文本
>Ctrl + Shift + S = 保存所有文件和项目
>Ctrl + K，Ctrl + C = 注释选定行
>Ctrl + K，Ctrl + U = 取消选定行的注释
>Ctrl + K，Ctrl + D = 正确对齐所有代码
>Ctrl+D 下一个匹配的也被选中
>Ctrl+C 、 Ctrl+V 复制或剪切当前行/当前选中内容
>Shift+Alt+F，或 Ctrl+Shift+P 后输入 format code 代码格式化
>Shift + End = 从头到尾选择整行
>Shift + Home = 从尾到头选择整行
>Ctrl + Delete = 删除光标右侧的所有字
>打开编辑窗口：Alt + E
>转到行：Ctrl + G
>转到所有：Ctrl + T
>转到文件：Ctrl + Shift + T
>转到最近文件：Ctrl + 1，R
>转到类型：Ctrl + 1，Ctrl + T
>转至成员：Alt + \
>转到符号：Ctrl + 1，Ctrl + S
>转到文件中的下个问题：Alt + PgDn
>转到文件中的上个问题：Alt + PgUp
>转到上一个编辑位置：Ctrl + Shift + Backspace
>搜索框：Ctrl + Q
>快速查找：Ctrl + F
>快速替换Ctrl + H
>在文件中查找：Ctrl + Shift + F
>在文件中替换：Ctrl + Shift + H
>将当前行添加书签：Ctrl + K Ctrl + K
>导航至下一个书签：Ctrl + K Ctrl + N
>如果你键入一个类名如Collection，且命名空间导入不正确的话，那么这个快捷方式组合将自动插入导入：Ctrl + .
>在文件中查找：Ctrl + Shift + F
>查找所有引用：Shift + F12
>显示查找对话框：Ctrl + F
>显示替换对话框：Ctrl + H
>跳转到行号或行：Ctrl + G
>查找所选条目在整个解决方案中的引用：Ctrl + Shift + F
>撤销：Ctrl + Z
>重做：Ctrl + Y
>剪切：Ctrl + X
>复制：Ctrl + C
>粘贴：Ctrl + V
>显示剪贴板历史记录：Ctrl + Shift + V
>复制一行：Ctrl + D
>删除：Del
>全选：Ctrl + A
>设置文档的格式：Ctrl + K，Ctrl + D
>设置选定内容的格式：Ctrl + K，Ctrl + F
>转换为大写：Ctrl + Shift + U
>转换为小写：Ctrl + U
>将选定行上移：Alt + ↑
>将选定行下移：Alt + ↓
>删除水平空白：Ctrl + K，Ctrl + \
>将选定内容扩展到包含块：Shift + Alt + ]
>展开选定内容：Shift + Alt + =
>收缩选定内容：Shift + Alt + -
>查看空白：Ctrl + R，Ctrl + W
>自动换行：Ctrl + E，Ctrl + W
>渐进式搜索：Ctrl + I
>切换行注释：Ctrl + K，Ctrl + /
>切换块注释：Ctrl + Shift + /
>注释选定内容：Ctrl + K，Ctrl + C
>取消注释选定内容 Ctrl + K，Ctrl + U
>切换书签：Ctrl + K，Ctrl + K
>上一个书签：Ctrl + K，Ctrl + P
>下一个书签：Ctrl + K，Ctrl + N
>清除书签：Ctrl + K，Ctrl + L
>文件夹中的上一书签：Ctrl + Shift + K，Ctrl + Shift + P
>文件夹中的下一书签：Ctrl + Shift + K，Ctrl + Shift + N
>添加任务列表快捷方式：Ctrl + K，Ctrl + H
>切换大纲显示展开：Ctrl + M，Ctrl + M
>切换所有大纲显示：Ctrl + M，Ctrl + L
>停止大纲显示：Ctrl + M，Ctrl + P
>停止隐藏当前区域：Ctrl + M，Ctrl + U
>折叠到定义：Ctrl + M，Ctrl + O
>列出成员：Ctrl + J
>参数信息：Ctrl + Shift + 空格键
>快速信息：Ctrl + K，Ctrl + I
>完成单词：Ctrl + 空格键
>切换完成模式：Ctrl + Alt + 空格键
>外侧代码：Ctrl + K，Ctrl + S
>插入片段：Ctrl + K，Ctrl + X
>插入下一匹配的脱字号：Shift + Alt + .
>在所有匹配位置插入脱字号：Shift + Alt + ;
>滚动窗口但不移动光标：Ctrl + Up/Down（方向键↑、↓）
>转到定义：F12
>在当前行插入空行：Ctrl + Enter
>在当前行下方插入空行：Ctrl + Shift + Enter
>块选择：Alt + Shift + 方向键、Shift + 方向键
>选择矩形文本：Alt + 鼠标左键
>匹配括号：Ctrl + }
>选择括号、括号内的文本：Ctrl + Shift + }
>从头到尾选择整行：Shift + End
>从尾到头选择整行：Shift + Home


### **三、导航视图相关**
>
>打开视图窗口：Alt + V
>代码：F7
>解决方案资源管理器：Ctrl + Alt + L
>团队资源管理器：Ctrl + \，Ctrl + M
>服务器资源管理器：Ctrl + Alt + S
>测试资源管理器：Ctrl + E，T
>书签窗口：Ctrl + K，Ctrl + W
>调用层次结构：Ctrl + Alt + K
>类视图：Ctrl + Shift + C
>代码定义窗口：Ctrl + \，D
>对象浏览器：Ctrl + Alt + J
>错误列表：Ctrl + \，E
>输出：Ctrl + Alt + O
>任务列表：Ctrl + \，T
>工具箱：Ctrl + Alt + X
>通知：Ctrl + \，Ctrl + N
>查找符号接口：Ctrl + Alt + F12
>命令窗口：Ctrl + Alt + A
>Web浏览器：Ctrl + Alt + R
>任务运行程序资源管理器：Ctrl + Alt + Backspace
>文档大纲：Ctrl + Alt + T
>资源视图：Ctrl + Shift + E
>全屏膜：Shift + Alt + Enter
>所有窗口：Shift + Alt + M
>向后导航：Ctrl + -
>向前导航：Ctrl + Shift + -
>属性窗口：F4
>属性页：Shift + F4
>滚动窗口但不移动光标：Ctrl +Up/Down 　　
>让光标移动到它先前的位置：Ctrl + - 　
>让光标移动到下一个位置：Ctrl ++ 　
>转到定义：F12
>


### **四、项目相关**
>
>打开项目窗口：Alt + P
>类向导：Ctrl + Shift + X
>添加新项：Ctrl + Shift + A
>添加现有项：Shift + Alt + A
>


### **五、生成相关**
>
>生成解决方案：Ctrl + Shift + B
>对解决方案运行代码进行分析：Alt + F11
>生成项目：Ctrl + B
>编译：Ctrl + F7
>


### **六、调试相关**
>
>打开调试窗口：Alt + D
>断点窗口：Ctrl + Alt + B
>异常设置：Ctrl + Alt + E
>显示诊断工具：Ctrl + Alt + F12
>即时：Ctrl + Alt + I
>启动图形调试：Alt + F5
>开始调试：F5
>开始执行（不调试）：Ctrl + F5
>停止调试：Shift + F5
>重新启动调试：Ctrl + Shift + F5
>性能探查器：Alt + F2
>附加到进程：Ctrl + Alt + P
>逐语句：F11
>逐过程：F10
>切换断点：F9
>启动/停止断点：Ctrl + F9
>运行到光标处：Ctrl + F10
>函数断点：Ctrl + K，B
>停止调试：Shift + F5
>


### **七、调试相关**
>| 快捷键             | 备注           |
>| ------------------ | -------------- |
>| Alt + S            | 打开测试窗口   |
>| Ctrl + R，A        | 运行所有测试   |
>| Ctrl + R，L        | 重复上次运行   |
>| Ctrl + R，Ctrl + A | 调试所有测试   |
>| Ctrl + R，D        | 调试上次运行   |
>| Ctrl + E，T        | 测试资源管理器 |
>| Ctrl + Alt + P     | 附加到进程     |
>| F10                | 调试单步执行   |
>| F5                 | 开始调试       |
>| Shift + F5         | 停止调试       |
>| Ctrl + Alt + Q     | 添加快捷匹配   |
>| F9                 | 设置或删除断点 |
>
>


### **八、分析相关**
>| 快捷键                  | 备注               |
>| ----------------------- | ------------------ |
>| Alt + N                 | 打开分析窗口       |
>| Ctrl + Shift + Alt + F7 | 对文件运行代码分析 |


### **九、工具相关**
>| 快捷键             | 备注           |
>| ------------------ | -------------- |
>| Ctrl + K，Ctrl + B | 打开工具窗口   |
>| Alt + T            | 代码片段管理器 |


### **十、扩展相关**
>| 快捷键  | 备注         |
>| ------- | ------------ |
>| Alt + X | 打开扩展窗口 |

### **十一、窗口相关**

>| 快捷键      | 备注     |
>| ----------- | -------- |
>| Alt + W     | 打开窗口 |
>| Shift + Esc | 关闭     |


### **十二、帮助相关**
>| 快捷键    | 备注         |
>| --------- | ------------ |
>| Alt + H   | 打开帮助窗口 |
>| Ctrl + F1 | 查看帮助     |

## 自定义 VS 视图