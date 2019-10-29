C = int(input('请输入轮船最大承载重量：'))
n = int(input('请输入集装箱总数：'))

# 每个的集装箱重量所构成的列表
weight = [0]*n

# 用户依次输入每个集装箱的重量
for i in range(n):
    weight[i] = int(input('第' + str(i+1) + '个集装箱重量：'))

# 重量排序
weight.sort()

# 能装载的集装箱总量
amount = 0
# 当前装载的总重量
total_weight = 0

while True:
    # 能装载集装箱个数最多为之前设定的n值
    if amount < n:
        total_weight += weight[amount]
        if total_weight <= C:
            amount += 1
        else:
            break
    # 所有集装箱即为求解结果
    else:
        break

print(amount)
