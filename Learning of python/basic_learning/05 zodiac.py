# -*- coding = utf-8 -*-
# @Time: 2022/4/13 13:15
# @Author: 陌言
# @File: 05 zodiac.py
# @SoftWare: PyCharm

# # 输入一个日期判断其是哪个星座
# zodiac_name = (u'魔羯座', u'水瓶座', u'双鱼座', u'白羊座', u'金牛座', u'双子座', u'巨蟹座',
#            u'狮子座', u'处女座', u'天秤座', u'天蝎座', u'射手座') # 在这u是指unicode编码，防止乱码
# zodiac_days = ((1, 20), (2, 19), (3, 21), (4, 21), (5, 21), (6, 22), (7, 23),
#                (8, 23), (9, 23), (10, 23), (11, 23), (12, 23))
# (month, day) = (2, 15)
#
# zodiac_day = filter(lambda x: x <= (month, day), zodiac_days)
# # print(zodiac_day)
# zodiac_len = len(list(zodiac_day))
# print(zodiac_name[zodiac_len])
a_list = ['abc', 'xyz']
a_list.append('X')
print(a_list)
a_list.remove('xyz')
print(a_list)