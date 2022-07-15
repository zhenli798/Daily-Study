# -*- coding = utf-8 -*-
# @Time: 2022/7/15 11:11
# @Author: 陌言
# @File: 03-Matplotlib显示三维图形实例.py
# @SoftWare: PyCharm
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
fig = plt.figure()
ax = Axes3D(fig)
x = np.linspace(-1, 1, 50)
y = np.linspace(-1, 1, 50)
xs, ys = np.meshgrid(x, y)
zs = xs**2 - ys**2
ax.plot_surface(xs, ys, zs)
plt.show()
