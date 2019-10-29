from scipy.special import comb, perm

# 文件读取
fp = open('input.txt', 'r')
lines = fp.readlines()
data = [line.strip() for line in lines]
fp.close()

# 数据处理
num = data[0]
chars = data[1:]

alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m',\
            'n','o','p','q','r','s','t','u','v','w','x','y','z']

results = []

for char in chars:
    if len(char) == 1:
        results.append(str(alphabet.index(char) + 1))
    elif len(char) == 2:
        a1:index = alphabet.index(c)
        index * 26
        a2:index = 
        # results.append(comb(26,1)+)
    elif len(char) == 3:
        pass
    elif len(char) == 4:
        pass
    elif len(char) == 5:
        pass
    elif len(char) == 6:
        pass

# 结果保存进文件
fp = open('output.txt', 'w')
for result in results:
    fp.write(result+'\n')
fp.close()
