# -*- coding = utf-8 -*-
# @Time: 2022/4/16 13:15
# @Author: 陌言
# @File: 05 zodiac.py
# @SoftWare: PyCharm

# 输入一个日期判断其是哪个星座
zodiac_name = (u'魔羯座', u'水瓶座', u'双鱼座', u'白羊座', u'金牛座', u'双子座', u'巨蟹座',
           u'狮子座', u'处女座', u'天秤座', u'天蝎座', u'射手座') # 在这u是指unicode编码，防止乱码
zodiac_days = ((1, 20), (2, 19), (3, 21), (4, 21), (5, 21), (6, 22), (7, 23),
               (8, 23), (9, 23), (10, 23), (11, 23), (12, 23))
# 记录生肖，根据年份来判断生肖
chinese_zodiac = '猴鸡狗猪鼠牛虎兔龙蛇马羊'

cz_num = {}
for i in chinese_zodiac:
    cz_num[i] = 0
z_num = {}
for i in zodiac_name:
    z_num[i] = 0


while True:
    # 用户输入月份和日期
    year = int(input('请输入年份：'))
    int_month = int(input('请输入月份：'))
    int_day = int(input('请输入日期：'))
    n = 0
    while zodiac_days[n] < (int_month, int_day):
        if int_month == 12 and int_day > 23:
            break
        n += 1
    print(zodiac_name[n])
    # 输入生肖
    print('%s 年的生肖是 %s' %(year, chinese_zodiac[year % 12]))

    cz_num[chinese_zodiac[year % 12]] += 1
    z_num[zodiac_name[n]] += 1

    # 输出生肖和字典的统计信息
    for each_key in cz_num.keys():
        print('生肖 %s 有 %d 个' %(each_key, cz_num[each_key]))
    for each_key in z_num.keys():
        print('星座 %s 有 %d 个' %(each_key, z_num[each_key]))