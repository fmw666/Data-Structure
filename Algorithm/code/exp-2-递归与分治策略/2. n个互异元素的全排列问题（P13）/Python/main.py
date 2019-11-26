def Perm(list, k, m):
    if k == m:
        for i in range(m+1):
            print(str(list[i]) + ' ', end="")
        print()

    else:
        for i in range(k, m+1):
            list[k], list[i] = list[i], list[k]
            Perm(list, k+1, m)
            list[k], list[i] = list[i], list[k]

list = ['a', 'b', 'e', 'f']
Perm(list, 0, 3)