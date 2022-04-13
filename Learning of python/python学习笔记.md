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

* **for循环**：

