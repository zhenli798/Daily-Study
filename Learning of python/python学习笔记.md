# Python学习笔记

## 1. Python 基础语法

### 1.1 基本数据类型

1. 整数(int)：8
2. 浮点数(float)：8.8
3. 字符串(str)："8" "Python"
4. 布尔值(bool)：True False

```python
print(type(int('8'))) # 将字符串8转化为整型
print(type(str(123))) # 将整型123转为字符串类型
print(type(bool(123))) # 将整型123转为布尔类型
print(bool(0)) # 将整型0转为布尔类型 非0为True，0为False
```

### 1.2 变量的定义和常用操作

* a = 123 `a为变量名称，=为变量赋值，123为变量得到的值`

```python
# 网络带宽计算
print(100/8)

bandwidth = 100
ratio = 8
print(bandwidth/ratio)
```

<a href="https://python.freelycode.com/contribution/detail/47"> Python编码风格指南</a>

## 2. 序列

### 2.1 序列的概念

* 特点：成员都是有序排列，并且可以通过下标偏移量访问到它的一个或几个成员

* 字符串、列表、元组三种类型都属于序列

* 字符串："abcd"

* 列表：[0, "abcd"]

* 元组：("abc", "def")

* 思考：元组和列表的区别？

  答：相同点：都是序列，可以通过索引访问，可以存储任何数据类型

  不同点：写法不同，列表是可变的，元组是不可变的

* 无关知识点 ：在Python单引号跟双引号字符串没有区别，只是当你的字符串内容中有单引号出现时可以用双引号将整个字符串圈起来

```python
chinese_zodiac = '鼠牛虎兔龙蛇马羊猴鸡狗猪'

print(chinese_zodiac[0:4]) # 下标从0开始
print(chinese_zodiac[-1]) # 取最后一个元素
```

### 2.2 字符串的定义和使用

```python
# 记录生肖，根据年份来判断生肖
chinese_zodiac = '猴鸡狗猪鼠牛虎兔龙蛇马羊'

year = 2022
print(year%12)
print(chinese_zodiac[year%12])
```

### 2.3 序列的基本操作

1. 对象[not] in 序列
2. 序列+序列
3. 序列*整数
4. 序列[0:整数]

```python
chinese_zodiac = '猴鸡狗猪鼠牛虎兔龙蛇马羊'

print('狗' in chinese_zodiac)
print('狗' not in chinese_zodiac)
print(chinese_zodiac + 'abcd')
print(chinese_zodiac * 3)
```

### 2.4 元组的定义和常用操作

* 比较操作

```python
a = (4)
b = (5)
print(a > b) # 元组当中只有一个数时是按这一个元素的大小去比较
print(a < b)
c = (1,50)
d = (1,200)
print(c > d) # 当元组中有两个元素的时候是将这两个元素结合之后进行比较，此处是150 > 1200
print(c < d)
```

* 案例演示

```python
# 输入一个日期判断其是哪个星座
zodiac_name = (u'魔羯座', u'水瓶座', u'双鱼座', u'白羊座', u'金牛座', u'双子座', u'巨蟹座',
           u'狮子座', u'处女座', u'天秤座', u'天蝎座', u'射手座') # 在这u是指unicode编码，防止乱码
zodiac_days = ((1, 20), (2, 19), (3, 21), (4, 21), (5, 21), (6, 22), (7, 23),
               (8, 23), (9, 23), (10, 23), (11, 23), (12, 23))
(month, day) = (2, 15)

zodiac_day = filter(lambda x: x <= (month, day), zodiac_days)
# print(zodiac_day)
zodiac_len = len(list(zodiac_day))
print(zodiac_name[zodiac_len])
```

### 2.5 列表的定义和常用操作

**常用操作**：

* append(x)：向列表中插入一个元素x
* remove(x)：从列表中删除元素x

```python
a_list = ['abc', 'xyz']
a_list.append('X')
print(a_list)
a_list.remove('xyz')
print(a_list)
```

 ## 3. 条件与循环

### 3.1 条件语句

* **if语句**：

  * 关键字
  * 判断条件表达式
  * 判断为真时的代码块

  ```python
  格式：
  if 表达式:
  	代码块
  ```

  * 可以和else、elif(else-if)语句组合成更复杂的判断

  ```python
  if 表达式:
  	代码块
  elif 表达式:
  	代码块
  else:
  	代码块
  ```

### 3.2 循环

* **for语句**：

  ```python
  for 迭代变量 in 可迭代对象:
  	代码块
      
  # 例子    
  chinese_zodiac = '猴鸡狗猪鼠牛虎兔龙蛇马羊'
  
  for cz in chinese_zodiac:
      print(cz)
  
  for i in range(3): # 输出0-2
      print(i)
  
  for i in range(1, 3): # 输出1-2
      print(i)
  
  for year in range(2000, 2023):
      print('%s 年的生肖是 %s' %(year, chinese_zodiac[year % 12]))
  ```

* **while语句**：

  ```python
  while 条件表达式:
      代码块
  ```

* **for循环+if判断**:

  ```python
  # 输入一个日期判断其是哪个星座
  zodiac_name = (u'魔羯座', u'水瓶座', u'双鱼座', u'白羊座', u'金牛座', u'双子座', u'巨蟹座',
             u'狮子座', u'处女座', u'天秤座', u'天蝎座', u'射手座') # 在这u是指unicode编码，防止乱码
  zodiac_days = ((1, 20), (2, 19), (3, 21), (4, 21), (5, 21), (6, 22), (7, 23),
                 (8, 23), (9, 23), (10, 23), (11, 23), (12, 23))
  
  # 用户输入月份和日期
  int_month = int(input('请输入月份：'))
  int_day = int(input('请输入日期：'))
  
  for zd_num in range(len(zodiac_days)):
      if zodiac_days[zd_num] >= (int_month, int_day):
          print(zodiac_name[zd_num])
          break
      elif int_month == 12 and int_day > 23:
          print(zodiac_name[0])
          break
  ```

* **while循环+if判断**：

  ```python
  # 输入一个日期判断其是哪个星座
  zodiac_name = (u'魔羯座', u'水瓶座', u'双鱼座', u'白羊座', u'金牛座', u'双子座', u'巨蟹座',
             u'狮子座', u'处女座', u'天秤座', u'天蝎座', u'射手座') # 在这u是指unicode编码，防止乱码
  zodiac_days = ((1, 20), (2, 19), (3, 21), (4, 21), (5, 21), (6, 22), (7, 23),
                 (8, 23), (9, 23), (10, 23), (11, 23), (12, 23))
  
  # 用户输入月份和日期
  int_month = int(input('请输入月份：'))
  int_day = int(input('请输入日期：'))
  n = 0
  while zodiac_days[n] < (int_month, int_day):
      if int_month == 12 and int_day > 23:
          break
      n += 1
  print(zodiac_name[n])
  ```

## 4. 映射与字典

* **字典**：

  * 特性：包含哈希值和指向的对象

  * 格式：`{"哈希值":"对象"}`

  * 简单使用：

    ```python
    dict1 = {}
    print(type(dict1))
    dict2 = {'x':1, 'y':2}
    dict2['z'] = 3
    
    print(dict2)
    ```

* **列表推导式与字典推导式**：

  ```python
  # 1. 列表一般写法
  even_list = []
  for i in range(1, 11):  # 记录1-10中所有偶数的平方
      if (i % 2) == 0:
          even_list.append(i * i)
  print(even_list)
  # 1. 列表的列表推导式写法
  even_list2 = [i * i for i in range(1, 11) if (i % 2) == 0]
  print(even_list2)
  
  zodiac_name = (u'魔羯座', u'水瓶座', u'双鱼座', u'白羊座', u'金牛座', u'双子座', u'巨蟹座',
                 u'狮子座', u'处女座', u'天秤座', u'天蝎座', u'射手座')
  # 2. 字典的一般写法
  z_dict = {}
  for i in zodiac_name:
      z_dict[i] = 0
  print(z_dict)
  
  # 2. 字典的字典推导式写法
  z_dict2 = {k: 0 for k in zodiac_name}
  print(z_dict2)
  ```

## 5. 文件和输入输出

### 5.1 文件的内建函数

* **定义**：python自带的函数，不需要额外去安装
* **基本的函数**：
  1. open()：打开文件
  2. read()：输入
  3. readline()：输入一行
  4. seek()：文件内移动
  5. write()：输出
  6. close()：关闭文件
* **注意**：
  * 在打开文件之后一定要对文件进行关闭，否则电脑突然关机的话你写入的信息就会丢失。

### 5.2 文件的常用操作

* 读取一行：`readline()`

* 读取多行：`readlines()`得到一个列表，列表中每一个元素都是一行的内容

* 读取整个内容：`read()`直接得到整个文章的内容，用字符串的形式去存储

* 读取固定数字符：`read(x)`x代表读取的字符数量

* 移动文件读取指针：

  * 单个参数时：`seek(x)`代表移动到文章第几个字符处，从0开始
  * 两个参数时：`seek(a, b)` 第一个参数代表偏移位置   第二个参数0表示从文件开头偏移1表示从当前位置偏移2表示从文件结尾

* 例子：

  ```python
  # # 将小说的主要人物记录在文件中
  # # file1 = open('name.txt') # 默认以只读的方式打开文件
  # file1 = open('name.txt', 'w')  # 以写入的方式打开文件
  # file1.write('诸葛亮')
  # file1.close()
  #
  # file2 = open('name.txt')
  # print(file2.read())
  # file2.close()
  #
  # file3 = open('name.txt', 'a')  # 如果是以写入的方式打开文件在新写内容时会覆盖，这里用增加的方式进行写入
  # file3.write('刘备')
  
  # file4 = open('name.txt')
  # print(file4.readline()) # 读一行
  #
  # file5 = open('name.txt')
  # # print(file5.readlines()) # 读取多行
  # for line in file5.readlines():
  #     print(line)
  file6 = open('name.txt')
  print('当前文件指针的位置 %s' % (file6.tell()))  # 文件指针在哪个位置
  # print(file6.read())  # 读取所有文件
  print('当前读取到了一个字符，字符的内容是 %s' % file6.read(1))  # 默认是读取所有文件，此处表读取一个字符
  print('当前文件指针的位置 %s' % (file6.tell()))
  file6.seek(2, 0)  # 第一个参数代表偏移位置   第二个参数 0表示从文件开头偏移 1表示从当前位置偏移 2从文件结尾
  print('我们进行了seek操作')
  print('文件指针回到了位置 %s' % (file6.tell()))
  print('当前读取到了一个字符,字符的内容是 %s' % file6.read(1))  # 默认是读取所有文件，此处表读取一个字符
  print('当前文件指针的位置 %s' % (file6.tell()))
  file6.close()
  ```

## 6. 错误和异常

* **异常**：

  * 产生：出现错误时采用正常控制流以外的动作

  * 异常处理的一般流程：

    1. 检测到错误，引发异常
    2. 对异常进行捕获操作

  * 异常处理代码格式：

    ```python
    try:
        <监控异常>
    except Exception[,reason]:
        <异常处理代码>
    finally:
        <无论异常是否发生都执行>  # 常用于文件关闭
    ```

  * 简单试验：

    ```python
    # try:
    #     year = int(input('input year：'))
    # except ValueError:
    #     print('年份要输入数字!')
    
    # except (ValueError, AttributeError, KeyError) 捕获多个异常时使用元组将其整合成一个对象
    
    # try:
    #     print(1 / 0)
    # except Exception as e:  # Exception代表所有错误信息
    #     print('0不能做除数 %s' % e)
    
    # 自己定义错误信息
    try:
        raise NameError('helloError')
    except NameError:
        print('my Custom error')
    ```



## 7. 函数

* 定义：对程序逻辑进行结构化的一种编程方法

* 定义格式：

  ```python
  def 函数名称():
  	代码
  	return 需要返回的内容
  ```

* 函数的调用：`函数名称()`

### 7.3 函数的迭代器与生成器

* iter()：用来生成迭代器
* next()：返回迭代器的下一个项目

```python
list1 = [1, 2, 3]
it = iter(list1)
print(next(it))
print(next(it))
print(next(it))
print(next(it))

list2 = ['a', 'b', 'c']
for i in iter(list2):
    print(i)
```

* 生成器：使用了yield的函数称为生成器，生成器是迭代器的一种。调用一个生成器函数，返回一个迭代器对象。

```python
# 自己手写一个浮点数range
def frange(start, stop, step): # 使用了yield的函数我们称为生成器，也是迭代器的一种
    x = start
    while x < stop:
        yield x
        x += step
for i in frange(10, 20, 0.5):
    print(i)
```

### 7.4 Lambda表达式

* **使用**：在我们仅仅使用函数进行简单计算的时候使用。省去了写return和定义函数名称的过程。

```python
def add(x, y):
    return x + y
lambda x,y: x + y
```

### 7.5 Python内建函数

* filter(func, iterable)：将符合指定函数的项给选出来

  ```python
  a = [1, 2, 3, 4, 5, 6, 7]
  list(filter(lambda x:x>2, a)) # 将符合指定函数的项给取出来
  ```

* map()：对每个元素依次进行操作变变换

  ```python
  a = [1, 2, 3]
  b = [4, 5, 6]
  list(map(lambda x:x+1, a)) # 对a列表中的每一项进行加一
  list(map(lambda x,y:x+y, a, b))# a列表中的每一项加上b列表中的每一项
  ```

* reduce()：序列的所有项和初始值依次按照函数做运算<font color=red>注意：reduce虽然是内建函数，但是得用`from functools import reduce`导入</font>

  ```python
  reduce(lambda x,y: x+y, [2,3,4], 1) # (( 1 + 2 ) + 3 ) + 4
  # 初始值可以省略，当省略时，默认为0
  ```

* zip()：可以使两个元组纵向合并。可以实现字典的key、value对调

  ```python
  a = (1, 2, 3)
  b = (4, 5, 6)
  tuple(zip(a, b))
  for i in zip(a, b): # zip是一个可迭代的函数,其有一个iter方法
      print(i)
  dicta = {'a':'aaa', 'b':'bbb'}
  dictb = dict(zip(dicta.values(), dicta.keys()))
  dictb
  ```

* 补充：
  
  * 可迭代的函数都会有一个iter的方法

### 7.6 闭包

* **定义**：嵌套的函数，且当外部函数的参数被内部函数给引用的情况下我们称其为闭包。

* **小示例**：

  ```python
  # 使用闭包实现计数器
  def counter(FIRST=0):
      cnt = [FIRST]
      def add_one():
          cnt[0] += 1
          return cnt[0]
      return add_one
  num1 = counter(5)
  num2 = counter(10)
  print(num1())
  print(num1())
  print(num2())
  print(num2())
  ```

  运行结果：

  >6
  >
  >7
  >
  >11
  >
  >12

  发现：

  互不影响，这也是闭包的好处。

  ```python
  # 使用闭包实现线段
  def a_line(a, b):
      def arg_y(x):
          return a * x + b
      return arg_y
  line1 = a_line(3, 5)
  line2 = a_line(10, 5)
  print(line1(5))
  print(line2(5))
  '''
  闭包优雅写法
  def a_line(a, b):
      return lambda x:a*x+b
  '''
  ```

  * 好处：比传统的实现方式传参少，定义函数时只需要传a、b两个参数，使用线段求y时只用传x一个参数。

### 7.7 装饰器

* 定义与闭包类似，只不过它传递的参数是一个函数，使用方法经过不断演化后得到了简化。

* 示例：

  * 粗略计算一下程序的运行时间

  ```python
  import time
  # 未用装饰器前
  def I_sleep():
      time.sleep(3)
  start_time = time.time()
  I_sleep()
  stop_time = time.time()
  print("程序运行了%s" %(stop_time-start_time))
  
  # 用装饰器后
  def timer(func):
      def wrapper():
          start_time = time.time()
          func()
          stop_time = time.time()
          print("程序运行了%s" %(stop_time-start_time))
      return wrapper
  @timer # 语法糖，修饰I_sleep2
  def I_sleep2():
      time.sleep(3)
  I_sleep2() # 实际上是(timer(I_sleep2))()这么运行的
  ```

* 带参数的装饰器：

  ```python
  # 带参数的装饰器
  def out(func):
      def inner(a,b):
          print('start')
          func(a,b)
          print('stop')
      return inner
  @out
  def add(a,b):
      print(a + b)  
  add(7,3) # 实际上可以理解为运行的时候是这样的(out(add))(7,3),所以实际上是inner(7,3)
  ```

* 针对不同函数装饰器做适应：

  ```python
  # 带参数的装饰器
  def new(argv):
      def out(func):
          def inner(a,b):
              print('start %s %s' %(argv, func.__name__)) # __name__取传入函数的名字
              func(a,b)
              print('stop')
          return inner
      return out
  @new('add_module')
  def add(a,b):
      print(a + b) 
  @new('sub_module')
  def sub(a,b):
      print(a - b)
  add(3, 5)
  sub(5, 3)
  ```

* 好处：

  1. 调用函数时不用在上面下面去编写重复的代码，可以将这些代码放在装饰器里面。
  2. 装饰器更易于复用

### 7.8 自定义上下文管理器

先来看看一般打开文件的方法

```python
fd = open('name.txt')
try:
    for line in fd:
        print(line)
finally:
    fd.close()
```

上面这种方法是不优雅的

下面我们使用`with`上下文管理器的方法去精简

```python
with open('name.txt') as f:
    for line in f:
        print(line)
```

通过这种方法省去了我们写finally，因为在出现异常的时候，它会自动帮我们做关闭的操作。

## 8. 模块

在代码量变得相当大之后，将需要重复使用的有组织的代码段放在一起组成一个文件，这个文件就是模块。可以附加到现有的程序中。

* 导入：附加的过程

* 导入的一般写法：

  ```python
  import 模块名称 as 别名
  from 模块名称 import 方法名
  ```


## 9. 面向对象编程

### 9.1 类与实例

```python
# 传统表示玩家信息的方法
user1 = {'name':'tom','hp':100}
user2 = {'name':'jerry','hp':80}

def print_role(rolename):
    print('name is %s,hp is %s' %(rolename['name'], rolename['hp']))
print_role(user1)
print_role(user2)
# 使用类的方法
class Player():
    def __init__(self, name, hp):
        self.name = name
        self.hp = hp
    def print_role(self): # 定义了一个方法
        print('name is %s,hp is %s' %(self.name, self.hp))
user1 = Player('Tom', 100) # 类的实例化
user2 = Player('Jerry', 80)
user1.print_role()
user2.print_role()
```

### 9.2 增加类的属性和方法

```python
# 使用类的方法
class Player():
    def __init__(self, name, hp, occu):
        self.__name = name # 变量被称作属性
        self.hp = hp
        self.occu = occu
    def print_role(self): # 定义了一个方法(函数被称作方法)
        print('name is %s,hp is %s,occupation is %s' %(self.__name, self.hp, self.occu))
    def updateName(self, newname):
        self.__name = newname
user1 = Player('Tom', 100, 'war') # 类的实例化
user2 = Player('Jerry', 80, 'master')
user1.print_role()
user2.print_role()

user1.updateName('wilson')
user1.print_role()
```

其中name默认是公有成员，也可以通过实例.name的方式去访问和更改。

如果想使得name不能使用.name 的方式去访问和更改，可以在其类中使用`__name`。

### 9.3 类的继承

```python
class Monster():
    # 定义怪物类
    pass # 告知系统我们定义了一个Monster，但是现在我们还不想去实现它
class Animals(Monster): # 继承自Monster类
    # 普通怪物
    pass
class Boss(Monster):
    # Boss类怪物
    pass
```

### 9.4 自定义with语句

```python
class Testwith():
    def __enter__(self):
        print('run')
    def __exit__(self, exc_type, exc_val, exc_tb):
        print('exit')
with Testwith():
    print('test is running')
```

运行结果：

run

test is running 

exit

```python
class Testwith():
    def __enter__(self):
        print('run')
    def __exit__(self, exc_type, exc_val, exc_tb):
        if exc_tb is None: # 没有异常它的值就是None
            print('正常结束')
        else:
            print('has error %s' %exc_tb)
with Testwith():
    print('test is running')
    raise NameError('testNameError') # 手动抛出异常
```

## 10. 多线程编程

* 定义：同时处理多个请求的方法

* 线程的简单使用：

  ```python
  import threading
  import time
  from threading import current_thread
  def myThread(arg1, arg2):
      # print(current_thread().getName(),'start')
      time.sleep(1)
      print('%s %s' %(arg1, arg2))
      # print(current_thread().getName(),'stop')
  for i in range(1, 6, 1):
      t1 = threading.Thread(target=myThread,args=(i, i + 1))
      t1.start()
  ```

* 让主线程等待其他线程结束之后再结束

  ```python
  import threading
  from threading import current_thread
  class Mythread(threading.Thread):
      def run(self):
          print(current_thread().getName(), 'start')
          print('run')
          print(current_thread().getName(), 'stop')
  t1 = Mythread()
  t1.start() # 线程使用start启动的时候实际上是调用了run方法
  t1.join() # 等待t1线程结束才会向下执行
  
  print(current_thread().getName(), 'end')
  
  ```


* 生产者和消费者：

  ```python
  from threading import Thread,current_thread
  import time
  import random
  from queue import Queue
  
  queue = Queue(5) # 定义队列的长度
  class ProducerThread(Thread):
      def run(self):
          name = current_thread().getName() # 获取线程的名字
          nums = range(100)
          global queue
          while True:
              num = random.choice(nums)
              queue.put(num)
              print('生产者 %s 生产了数据 %s' %(name, num))
              t = random.randint(1, 3)
              time.sleep(t)
              print('生产者 %s 睡眠了 %s 秒' %(name, t))
  class ConsumerThread(Thread):
      def run(self):
          name = current_thread().getName()
          global queue
          while True:
              num = queue.get()
              queue.task_done() # 封装好了关于线程等待和线程同步的代码
              print('消费者 %s 消耗了数据 %s' %(name, num))
              t = random.randint(1, 5)
              time.sleep(t)
              print('消费者 %s 睡眠了 %s 秒' %(name, t))
  p1 = ProducerThread(name = 'p1')
  p1.start()
  p2 = ProducerThread(name = 'p2')
  p2.start()
  p3 = ProducerThread(name = 'p3')
  p3.start()
  c1 = ConsumerThread(name = 'c1')
  c1.start()
  c2 = ConsumerThread(name = 'c2')
  c2.start()          
  ```

## 11. 标准库

* **定义**：安装python后自带的库
* **目前比较广泛的模块**：
  1. 文字处理的re
  2. 日期类型的time、datetime
  3. 数字和数学类型的math、random
  4. 文件和目录访问的pathlib、os.path
  5. 数据压缩和归档的tarfile
  6. 通用操作系统的os、logging、argparse
  7. 多线程的threading、queue
  8. Internet数据处理的base64、json、urllib
  9. 结构化标记处理工具的html、xml
  10. 开发工具的unitest
  11. 调试工具的timeit
  12. 软件包发布的venv
  13. 运行服务的\_\_main\_\_

### 11.1 正则表达式库re的使用

* 导入`import re`

* 单个字符的匹配：

  ```python
  import re
  p = re.compile('a')
  print(p.match('a'))
  print(p.match('b'))
  ```

  运行结果：

  ```python
  <re.Match object; span=(0, 1), match='a'> # 匹配到的位置
  None # 匹配失败
  ```

* 正则表达式元字符：

  * `.`匹配任意一个字符除换行符
  * `\d`匹配任意一个数字
  * <a href="[(32条消息) 正则表达式_小陌白的博客-CSDN博客](https://xiaomobai.blog.csdn.net/article/details/119743379)">更多</a>

* 匹配日期：

  ```python
  p = re.compile(r'(\d+)-(\d+)-(\d+)') # r是告知python字符串中的特殊符号不要进行转义
  print(p.match('2022-05-05').group()) # 获取匹配到的内容
  print(p.match('2022-05-07').group(1)) # 获取年
  print(p.match('2022-05-07').groups()) # 获取年月日，用元组去存
  year,month,day = ('2022', '05', '07')
  ```

* 正则表达式match与search的区别

  * match要求原字符和输入字符完全匹配。即当第一个字符与原字符不匹配时便返回匹配失败。
  * search不会，它会沿输入字符继续向后进行匹配。
  * match经常是用于完全匹配之后进行分组。

* 正则表达式库替换函数sub

  * sub(str1, str2, str3)：

    * str1：匹配的规则
    * str2：匹配到的字符串要替换成的内容
    * str3：将要替换的字符串

  * 使用：

    ```python
    # 删去电话号码结尾不合法部分
    phone = '123-456-789 # 这是一个电话号码'
    p = re.sub(r'#.*$', '', phone)
    print(p)
    # 删去-
    p2 = re.sub(r'\D','',p)
    print(p2)
    ```

    运行结果：

    > 123-456-789
    >
    > 123456789

* 补充：

  * search只能匹配一次，想要匹配多次要用findall

### 11.2 日期与时间函数库

* 时间库：

  * 引入`import time`

  * 函数：

    * time()：从1970年1月1日到现在经历了多少秒
    * localtime([sec])：格式化时间戳为本地的时间
    * strftime(str)：返回str格式的当前时间

  * 使用：

    ```python
    import time
    print(time.time()) # 查19700101到现在过了多少秒
    print(time.localtime())
    print(time.strftime('%Y%m%d'))
    ```

* 以当前时间为准，计算指定偏移后的时间

  ```python
  import datetime
  print(datetime.datetime.now())
  newtime = datetime.timedelta(minutes = 10) # 计算十分钟偏移量
  print(datetime.datetime.now() + newtime) # 显示十分钟后的时间
  
  one_day = datetime.datetime(2008,5,27)
  new_date = datetime.timedelta(days = 10)
  print(one_day + new_date)
  ```

### 11.2 数学相关库

* math

* random

  * randint()：返回指定区间的随机数
  * choice(obj)：从对象中任选一值

  ```python
  import random
  print(random.randint(1, 5))
  print(random.choice([1, 2, 'a', 'b']))
  ```

### 11.3 文件与目录操作库

* os.path

  * 引入：`import os`或者`from os import path`

  * 使用：

    ```python
    from os import path
    print(path.abspath('..')) # 根据相对路径.获得绝对路径v
    print(path.exists('./01 hello_world.py')) # 判断文件是否存在
    print(path.isfile('./01 hello_world.py')) # 判断是否是文件
    print(path.isdir('./01 hello_world.py')) # 判断是否是目录
    print(path.isdir('.'))
    print(path.join('/tmp/','01 hello_world.py')) # 路径拼接
    ```

* pathlib

  * 引入：`from pathlib import Path`

  * 使用：

    ```python
    from pathlib import Path
    p = Path('.')
    print(p.resolve()) # 根据相对路径获得绝对路径，跟我们的path.abspath()一样
    print(p.is_dir()) # 判断当前位置是否是目录
    q = Path('./a/b/c')
    Path.mkdir(q, parents=True) # parents=True是当父级目录不存在时会创建父级目录
    ```

* 特点：两者大多数功能类似，但pathlib好的是可以创建目录。

## 12. 机器学习库

### 12.1 Numpy库

* **用途**：主要用于高性能科学计算和数据分析，是常用的高级数据分析库的基础包。

* **简单使用**：

  ```python
  import numpy as np
  arr1 = np.array([2, 3, 4])
  print(arr1)
  print(arr1.dtype)
  
  arr2 = np.array([2.1, 3.1, 4.1])
  print(arr2)
  print(arr2.dtype)
  print(arr1 + arr2)
  
  # Numpy数组和标量的计算
  print(arr2 * 10)
  data = [[1,2,3], [4,5,6]]
  arr3 = np.array(data) # 将列表转为二维矩阵
  print(arr3)
  print(arr3.dtype)
  print(type(arr3))
  
  print(np.zeros(10)) # 定义了一个一维的长度为10的数组，这个数组的所有值都是0
  print(np.zeros((3, 5))) # 定义一个3x5的矩阵，这个矩阵的所有值为0
  print(np.ones((4, 6))) # 定义一个4x6的矩阵，初始值都为1
  print(np.empty((2,3,2))) # 定义了一个三维矩阵，初始值为随机值
  
  # Numpy数组的索引和切片
  arr4 = np.arange(10)
  print(arr4[5])
  print(arr4[5:8])
  arr4[5:8] = 0
  print(arr4)
  arr_slice = arr4[5:8]
  arr_slice[:] = 1 # 由于python这里是引用，故而这么做会影响到arr4的内容
  print(arr4)
  arr_slice = arr4[5:8].copy()
  arr_slice[:] = 0 # 这样子做操作不会影响arr4，因为它是arr4的一个副本
  print(arr4)
  print(arr_slice)
  arr5 = np.array(['a', 'b', 'c', 'd'])
  print(arr5[1]) # 下标从0开始计算
  ```

### 12.2 Pandas库

* **好处**(相比于Numpy)：

  * 自动帮你将数据对齐显示
  * 可以灵活的处理缺失的数据、
  * 还可以实现像类似sql语句一样的连接操作

* **特点**：

  * 会帮我们自动添加索引
  * 键值可以不唯一

* **简单使用**：

  ```python
  import pandas as pd
  obj = pd.Series([4, 5, 6, -7])
  print(obj)
  
  print(obj.index) # 打印索引
  print(obj.values) # 打印值
  
  obj2 = pd.Series([4, 5, 6, 3], index = {'a', 'b', 'd', 'c'})
  print(obj2)
  obj2['c'] = 6
  print(obj2)
  print('c' in obj2) # 判断是否存在键'c'
  print('f' in obj2)
  
  # 将字典转化到我们的series中
  sdata = {'beijing' : 35000, 'shanghai' : 70000, 'guangzhou' : 16000, 'shenzhen' : 5000}
  obj3 = pd.Series(sdata)
  print(obj3)
  obj3.index = ['bj', 'sh', 'gz', 'sz'] # 修改索引为它们的缩写
  print(obj3)
  
data = {'city' : ['shanghai', 'guangzhou', 'beijing', 'shenzhen'],
          'year' : [2016, 2017, 2018, 2019],
          'pop' : [1.5, 1.8, 1.3, 2.0]}
  frame = pd.DataFrame(data)
  print(frame)
  
  frame2 = pd.DataFrame(data, columns = ['year', 'city', 'pop'])
  print(frame2)
  
  # 将二维表格转换为一维的数据
  print(frame2['city'])
  print(frame2.year)
  
  # 为pandas增加一个新的列
  frame2['cap'] = frame2.city == 'beijing'
  print(frame2)
  
  pop = { 'beijing' : {2008:1.5, 2009:2.0},
          'shanghai' : {2008:2.0, 2009:3.6}
         }
  frame3 = pd.DataFrame(pop)
  print(frame3)
  # 行和列的转换
  print(frame3.T)
  
  obj4 = pd.Series([4.5, 7.2, -5.3, 3.6], index = ['b', 'd', 'c', 'a'])
  obj5 = obj4.reindex(['a', 'b', 'c', 'd', 'e']) # 按索引顺序排序，不存在的索引将出现空值
  print(obj5)
  
  obj6 = obj4.reindex(['a', 'b', 'c', 'd', 'e'], fill_value = 0) # 给空值填充0
  print(obj6)
  
  obj7 = pd.Series(['blue', 'yellow', 'pink'], index = [0, 2, 4])
  print(obj7.reindex(range(6)))
  print(obj7.reindex(range(6), method = 'ffill')) # 空值填充为其前一个数值
  
  from numpy import nan as NA
  # 删除缺失值的一行数据
  data = pd.Series([1, NA, 2])
  print(data.dropna())
  
  # 在DataFrame删除缺失值的情况
  # 1. 某一列的某一行有缺失
  data = pd.DataFrame([[1.,  6.5, 3], [1., NA, NA], [NA, NA, NA]])
  data[4] = NA
  print(data)
  print(data.dropna()) # 发现只要出现了na的一行就会被全部删掉
  print(data.dropna(how = 'all')) # 只删掉全部出现na的一行
  print(data.dropna(axis = 1, how = 'all')) # 删掉全部出现na的一列
  data.fillna(0) # 这种方法是对data副本进行填充0，并返回，并不会直接修改data
  data.fillna(0, inplace = True) # 使用了inplace参数则代表是对data进行填充修改
  print(data)
  
  import numpy as np
  data3 = pd.Series(np.random.randn(10),
                 index = [['a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'd', 'd'],
                          [1, 2, 3, 1, 2, 3, 1, 2, 2, 3]])
  # 层次化索引的用途
  print(data3)
  print(data3.unstack()) # 将一维数据转化为二维数据
  print(data3.unstack().stack()) # 再转换回来
  ```
  

### 12.3 Matplotlib库

* **用途**：绘图

* **简单使用**：

  ```python
  import matplotlib.pyplot as plt
  
  # 绘制简单的曲线
  plt.plot([1, 3, 5], [4, 8, 10])
  plt.show()
  
  import numpy as np
  x =  np.linspace(-np.pi, np.pi, 100) # x轴的定义域为-3.14·3.14，中间间隔100个元素
  print(x)
  plt.plot(x, np.sin(x))
  # 显示所画的图
  plt.show()
  
  x = np.linspace(-np.pi * 2, np.pi * 2, 100)
  plt.figure(1, dpi = 50) # 创建图表，dpi代表精度，精度越高，画的图就越大就越清晰
  for i in range(1, 5): # 画四条线
      plt.plot(x, np.sin(x / i))
  plt.show()
  
  plt.figure(1, dpi = 50) # 创建图表1，dpi代表图片精细度，dpi越大文件越大，杂志要300以上
  data = [1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 5, 6, 4]
  plt.hist(data) # 只要传入数据，直方图就会统计数据出现的次数
  plt.show()
  
  x = np.arange(1, 10)
  y = x
  fig = plt.figure()
  plt.scatter(x, y, c = 'r', marker = 'o') # c = 'r' 表示散点的颜色为红色，marker表示指定三点多边形为圆形
  plt.show()
  
  import pandas as pd
  iris = pd.read_csv('./iris_training.csv')
  print(iris.head())
  # 绘制散点图
  iris.plot(kind = 'scatter', x = '120', y = '4')
  
  # 没啥用，只是让pandas的plot方法显示
  plt.show()
  
  # 使用seaborn来绘制图
  import seaborn as sns
  import warnings 
  warnings.filterwarnings('ignore')
  iris = pd.read_csv('./iris_training.csv')
  # 设置样式
  sns.set(style = 'white', color_codes = True)
  # 设置绘制格式为散点图
  # sns.jointplot(x = '120', y = '4', data = iris, size = 5)
  # distplot绘制曲线
  # sns.distplot(iris['120'])
  sns.FacetGrid(iris, hue = 'virginica', size = 5).map(plt.scatter, '120', '4').add_legend() # 按virginica属性分类，给点分配不同颜色
  sns.FacetGrid(iris, hue = 'virginica', size = 5).map(plt.scatter, 'setosa', 'versicolor').add_legend()
  ```

## 13. 爬虫

### 13.1 网页数据采集与urllib库

* **网络库**：

  * urllib库：http协议常用库
  * requests库：http协议常用库
  * BeautifulSoup库：xml格式处理库

  urlib跟requests库都是用于收集数据的库，BeautifulSoup是用于数据处理的库

* **urlib库**：

  * 使用：`from urllib import request`

  * 例子：

    ```python
    from urllib import request
    
    url = 'http://www.baidu.com'
    response = request.urlopen(url, timeout = 1)
    print(response.read().decode('utf-8')) # read直接读是按照单个字节解释出来的，而中文往往要占多个字节，所以要用decode做编码解析
    ```

  * 专门用于测试get和post请求的网页：http://www.httpbin.org/

  * 发送get请求：

    * 注意：使用urlopen的时候一般都要指定timeout，不然一旦请求超时程序会卡死

    ```python
    from urllib import request
    response = request.urlopen('http://httpbin.org/get', timeout=1) 
    print(response.read())
    
    # 超时异常捕获处理
    import urllib
    import socket
    try:
        response3 = request.urlopen('http://httpbin.org/get', timeout=0.1)
    except urllib.error.URLError as e:
        if isinstance(e.reason, socket.timeout):
            print('TIME OUT')
    ```

  * 发送post请求：

    ```python
    from urllib import parse # 处理post数据
    from urllib import request
    data = bytes(parse.urlencode({'word':'hello'}), encoding='utf8')
    # print(data)
    response2 = request.urlopen('http://httpbin.org/post', data=data)
    print(response2.read().decode('utf-8'))
    ```

    