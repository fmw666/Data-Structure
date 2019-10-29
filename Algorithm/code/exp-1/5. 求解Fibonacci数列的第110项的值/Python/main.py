# 1 1 2 3 5 8 13 21

'''
def fibonacci(n):
    if n == 1 or n == 2:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

print(fibonacci(110))
'''

times = 110

first_num, second_num = 1, 1
flag = times - 2
while flag:
    first_num, second_num = second_num, first_num + second_num
    flag -= 1

print(second_num)