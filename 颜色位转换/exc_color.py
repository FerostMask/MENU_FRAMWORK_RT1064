# 程序执行
color = eval(input("请输入48位RGB值："))
R = (color & 0xF80000) >> 8
G = (color & 0x00FC00) >> 5
B = (color & 0x0000F8) >> 3
color = R | G | B
print("%x" % color)
