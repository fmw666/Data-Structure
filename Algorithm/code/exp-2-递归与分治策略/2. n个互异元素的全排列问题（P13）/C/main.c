#include <stdio.h>

void Swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/*
 *  产生 list[k:m] 的所有排列 
 */
void Perm(char list[], int k, int m)
{
    // 只剩下一个元素
    if(k == m)
    {       
        for(int i=0; i<=m; i++)
            printf("%c ", list[i]);
        printf("\n");
    }
    else
    {
        for(int i=k; i<=m; i++)
        {
            Swap(&list[k], &list[i]);
            Perm(list, k+1, m);
            Swap(&list[k], &list[i]);
        }
    }    
}

int main()
{
    char list[4] = {'a', 'b', 'e', 'f'};
    Perm(list, 0, 3);

    return 0;
}