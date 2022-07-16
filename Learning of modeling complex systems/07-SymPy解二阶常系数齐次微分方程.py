# -*- coding = utf-8 -*-
# @Time: 2022/7/15 11:56
# @Author: 陌言
# @File: 07-SymPy解二阶常系数齐次微分方程.py
# @SoftWare: PyCharm
import sympy as sy
def differential_equation(x, f):
    return sy.diff(f(x), x, 2) + f(x) # f(x)'' + f(x) = 0 二阶常系数齐次微分方程
x = sy.symbols('x') # 约定变量
f = sy.Function('f') # 约定函数
print(sy.dsolve(differential_equation(x, f), f(x))) # 打印
sy.pprint(sy.dsolve(differential_equation(x, f), f(x))) # 漂亮的打印