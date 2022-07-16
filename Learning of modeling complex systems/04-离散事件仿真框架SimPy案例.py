# -*- coding = utf-8 -*-
# @Time: 2022/7/15 11:19
# @Author: 陌言
# @File: 04-离散事件仿真框架SimPy案例.py
# @SoftWare: PyCharm
# 模拟两个周期事件，fast事件周期是0.5秒，slow事件周期是1秒，模拟过程从0秒时刻开始到2秒时刻结束
import simpy
def clock(env, name, tick):
    while True:
        print(name, env.now)
        yield env.timeout(tick)
env = simpy.Environment()
env.process(clock(env, 'fast', 0.5))
env.process(clock(env, 'slow', 1))
env.run(until=2)
