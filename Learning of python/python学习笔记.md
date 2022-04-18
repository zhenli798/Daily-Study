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

