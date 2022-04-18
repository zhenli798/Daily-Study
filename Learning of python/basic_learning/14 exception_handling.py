# -*- coding = utf-8 -*-
# @Time: 2022/4/18 13:25
# @Author: 陌言
# @File: 14 exception_handling.py
# @SoftWare: PyCharm

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
