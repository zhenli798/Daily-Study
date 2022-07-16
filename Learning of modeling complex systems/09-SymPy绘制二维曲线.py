# -*- coding = utf-8 -*-
# @Time: 2022/7/15 12:06
# @Author: 陌言
# @File: 09-SymPy绘制二维曲线.py
# @SoftWare: PyCharm
from sympy.plotting import plot
from sympy import symbols
x = symbols('x')
p2 = plot(x* x, (x, -10, 10))