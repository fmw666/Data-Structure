#include <stdio.h>

// 1 1 2 3 5 8 13 21
/*
int Fibonacci(int n)
{
    if(n==1||n==2)
        return 1;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}
*/

int main()
{
//     printf("%d\n", Fibonacci(6));
    
    int times = 110;

    int first_num = 1;
    int second_num = 1;
    int flag = times-2;    
    while(flag)
    {
        int temp = second_num;
        second_num += first_num;
        first_num = temp;
        flag--;
    }
    printf("%d\n", second_num);

    return 0;
}