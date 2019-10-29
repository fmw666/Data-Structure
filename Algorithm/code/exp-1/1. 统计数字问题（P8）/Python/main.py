# 文件读取
fp = open('input.txt', 'r')
page = int(fp.read())
fp.close()

# 结果存放数组
result = [0]*10

# 遍历每个页号
for i in range(1, page+1):
    stri = str(i)
    for char in stri:
        index = int(char)
        result[index] += 1

# 打印输出
fp = open('output.txt', 'w')
for num in result:
    fp.write(str(num)+'\n')
    print(num)
fp.close()