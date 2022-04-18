# -*- coding = utf-8 -*-
# @Time: 2022/4/18 10:10
# @Author: 陌言
# @File: 12 列表推导式和字典推导式.py
# @SoftWare: PyCharm

# 1. 列表一般写法
even_list = []
for i in range(1, 11):  # 记录1-10中所有偶数的平方
    if (i % 2) == 0:
        even_list.append(i * i)
print(even_list)
# 1. 列表的列表推导式写法
even_list2 = [i * i for i in range(1, 11) if (i % 2) == 0]
print(even_list2)

zodiac_name = (u'魔羯座', u'水瓶座', u'双鱼座', u'白羊座', u'金牛座', u'双子座', u'巨蟹座',
               u'狮子座', u'处女座', u'天秤座', u'天蝎座', u'射手座')
# 2. 字典的一般写法
z_dict = {}
for i in zodiac_name:
    z_dict[i] = 0
print(z_dict)

# 2. 字典的字典推导式写法
z_dict2 = {k: 0 for k in zodiac_name}
print(z_dict2)
