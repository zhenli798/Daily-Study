# -*- coding = utf-8 -*-
# @Time: 2022/7/16 9:16
# @Author: 陌言
# @File: 10-NetworkX生成星形网络.py
# @SoftWare: PyCharm

import matplotlib.pyplot as plt
import networkx as nx
G = nx.star_graph(20)
pos = nx.spring_layout(G)
colors = range(20)
nx.draw(G, pos, node_color='#A0CBE2', edge_color=colors,
        width=4, edge_cmap=plt.cm.Blues, with_labels=False)
plt.show()
