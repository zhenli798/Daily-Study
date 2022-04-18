# -*- coding = utf-8 -*-
# @Time: 2022/4/18 11:25
# @Author: 陌言
# @File: 13 file_op.py
# @SoftWare: PyCharm


# # 将小说的主要人物记录在文件中
# # file1 = open('name.txt') # 默认以只读的方式打开文件
# file1 = open('name.txt', 'w')  # 以写入的方式打开文件
# file1.write('诸葛亮')
# file1.close()
#
# file2 = open('name.txt')
# print(file2.read())
# file2.close()
#
# file3 = open('name.txt', 'a')  # 如果是以写入的方式打开文件在新写内容时会覆盖，这里用增加的方式进行写入
# file3.write('刘备')

# file4 = open('name.txt')
# print(file4.readline()) # 读一行
#
# file5 = open('name.txt')
# # print(file5.readlines()) # 读取多行
# for line in file5.readlines():
#     print(line)
file6 = open('name.txt', 'r')
print('当前文件指针的位置 %s' % (file6.tell()))  # 文件指针在哪个位置
# print(file6.read())  # 读取所有文件
print('当前读取到了一个字符，字符的内容是 %s' % file6.read(1))  # 默认是读取所有文件，此处表读取一个字符
print('当前文件指针的位置 %s' % (file6.tell()))
file6.seek(2, 0)  # 第一个参数代表偏移位置   第二个参数 0表示从文件开头偏移 1表示从当前位置偏移 2从文件结尾
print('我们进行了seek操作')
print('文件指针回到了位置 %s' % (file6.tell()))
print('当前读取到了一个字符,字符的内容是 %s' % file6.read(1))  # 默认是读取所有文件，此处表读取一个字符
print('当前文件指针的位置 %s' % (file6.tell()))
file6.close()
