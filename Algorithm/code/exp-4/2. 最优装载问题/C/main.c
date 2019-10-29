#include <stdio.h>

void bubble_sort(int weight[], int n)
{
    for(int i=0; i<n-1; i++)
	{
		for(int j=n-1; j>i; j--)
        {
			if(weight[j] < weight[j-1])
            {
				int temp = weight[j];
                weight[j] = weight[j-1];
                weight[j-1] = temp;
            }
        }
	}
}

int main()
{
    int C;
    printf("请输入轮船最大承载重量：");
    scanf("%d", &C);
    int n;
    printf("请输入集装箱总数：");
    scanf("%d", &n);

    // 每个的集装箱重量所构成的列表
    int weight[n];

    // 用户依次输入每个集装箱的重量
    for(int i=0; i<n; i++)
    {
        printf("第%d个集装箱重量：", (i+1));
        scanf("%d", &weight[i]);
    }

    // 重量排序
    bubble_sort(weight, n);

    // 能装载的集装箱总量
    int amount = 0;
    // 当前装载的总重量
    int total_weight = 0;

    while(1)
    {
        // 能装载集装箱个数最多为之前设定的n值
        if(amount < n)
        {
            total_weight += weight[amount];
            if(total_weight <= C)
                amount++;
            else
                break;
        }
        // 所有集装箱即为所求解结果
        else
            break;
    }

    printf("%d\n", amount);

    return 0;
}