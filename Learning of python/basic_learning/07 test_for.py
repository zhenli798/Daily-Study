# -*- coding = utf-8 -*-
# @Time: 2022/4/16 16:46
# @Author: 陌言
# @File: 07 test_for.py
# @SoftWare: PyCharm

chinese_zodiac = '猴鸡狗猪鼠牛虎兔龙蛇马羊'

for cz in chinese_zodiac:
    print(cz)

for i in range(3): # 输出0-2
    print(i)

for i in range(1, 3): # 输出1-2
    print(i)

for year in range(2000, 2023):
    print('%s 年的生肖是 %s' %(year, chinese_zodiac[year % 12]))
