V = int(input('请输入背包的容量：'))
N = int(input('请输入物品的总数：'))

class Item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value
    def get_value_div_weight(self):
        return self.value / self.weight

def print_item_info(items):
    for index, item in enumerate(items):
        print('【第' + str(index+1) + '个物品】 重量：' + str(item.weight) + '  价值：' + str(item.value))
    
if __name__ == "__main__":
    # 物品列表
    items = []
    # 用户输入每样物品信息--重量、价值
    for i in range(N):
        print('第' + str(i+1) + '个物品的信息')
        w = int(input('重量：'))
        v = int(input('价值：'))
        items.append(Item(w, v))
    # 按照物品的权重（价值/重量）倒序排序
    items.sort(key=lambda item:item.get_value_div_weight(), reverse=True)
    
    # 能装入的物品总量
    amount = 0
    # 当前装入的总重量
    total_weight = 0
    # 当前装入的总价值
    total_value = 0
    # 新的物品列表
    new_items = []

    while True:
        # 能装入背包个数最多为之前设定的N值
        if amount < N:
            if (total_weight + items[amount].weight) <= V:
                new_items.append(items[amount])
                total_weight += items[amount].weight
                total_value += items[amount].value
                amount += 1
            else:
                break
        # 所有物品个数即为求解结果
        else:
            break
        
    # 输出结果信息
    print('===')
    print('书包总容量：' + str(V))
    print('装入物品总重量：' + str(total_weight))
    print('装入物品总价值：' + str(total_value))
    print('装入物品信息：')
    print_item_info(new_items)
    print('总共：' + str(amount) + '个物品')
