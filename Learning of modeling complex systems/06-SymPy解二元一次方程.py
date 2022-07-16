# -*- coding = utf-8 -*-
# @Time: 2022/7/15 11:49
# @Author: 陌言
# @File: 06-SymPy解二元一次方程.py
# @SoftWare: PyCharm

# x - y = 10, x + y = 16
from sympy import *
x = Symbol('x')
y = Symbol('y')
f1 = x - y - 10
f2 = x + y - 16
print(solve([f1, f2]))