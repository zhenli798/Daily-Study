# -*- coding = utf-8 -*-
# @Time: 2022/4/13 9:12
# @Author: 陌言
# @File: 02 type cast.py
# @SoftWare: PyCharm

print(type(int('8'))) # 将字符串8转化为整型
print(type(str(123))) # 将整型123转为字符串类型
print(type(bool(123))) # 将整型123转为布尔类型
print(bool(0)) # 将整型0转为布尔类型 非0为True，0为False