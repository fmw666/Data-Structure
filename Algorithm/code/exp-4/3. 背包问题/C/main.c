#include <stdio.h>

typedef struct Items
{
    int weight;
    int value;
}Item;

void print_item_info(Item items[], int N)
{
    for(int i=0; i<N; i++)
    {
        printf("【第%d个物品】 重量：%d  价值：%d\n", (i+1), items[i].weight, items[i].value);
    }
}

void sort(Item items[], int N)
{
    for(int i=0; i<N-1; i++)
	{
		for(int j=N-1; j>i; j--)
        {
			if(((float)items[j].value/items[j].weight) > ((float)items[j-1].value/items[j-1].weight))
            {
				Item temp = items[j];
                items[j] = items[j-1];
                items[j-1] = temp;
            }
        }
	}
}

int main()
{
    int V;
    printf("请输入背包的容量：");
    scanf("%d", &V);
    int N;
    printf("请输入物品的总数：");
    scanf("%d", &N);

    // 物品列表
    Item items[N];
    for(int i=0; i<N; i++)
    {
        printf("第%d个物品的信息\n", (i+1));
        int w;
        printf("重量：");
        scanf("%d", &w);
        int v;
        printf("价值：");
        scanf("%d", &v);

        Item item;
        item.weight = w;
        item.value = v;

        items[i] = item;
    }

    // 按照物品的权重（价值/重量）倒序排序
    sort(items, N);

    // 能装入的物品总量
    int amount = 0;
    // 当前装入的总重量
    int total_weight = 0;
    // 当前装入的总价值
    int total_value = 0;
    // 新的物品列表
    Item new_items[N];

    while(1)
    {
        // 能装入背包个数最多为之前设定的N值
        if(amount < N)
        {
            if(total_weight+items[amount].weight <= V)
            {
                new_items[amount] = items[amount];
                total_weight += items[amount].weight;
                total_value += items[amount].value;
                amount++;
            }
            else
                break;
        }
        // 所有物品个数即为求解结果
        else
            break;
    }

    // 输出结果信息
    printf("===\n");
    printf("书包总容量：%d\n", V);
    printf("装入物品总重量：%d\n", total_weight);
    printf("装入物品总价值：%d\n", total_value);
    printf("装入物品信息：\n");
    print_item_info(new_items, amount);
    printf("总共：%d个物品\n", amount);

    return 0;
}