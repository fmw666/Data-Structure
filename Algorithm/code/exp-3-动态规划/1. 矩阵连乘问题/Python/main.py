def matrix_chain(p, n, m, s):
    for i in range(n):
        m[i][i] = 0
    for r in range(2, n+1):
        for i in range(1, n-r+2):
            j = i + r -1
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]
            s[i][j] = i
            for k in range(i+1, j):
                t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                if t < m[i][j]:
                    m[i][j] = t
                    s[i][j] = k

def print_result(s, i, j):
    if i == j:
        print('A{}'.format(i), end="")
    else:
        print('(', end="")
        print_result(s, i, s[i][j])
        print_result(s, s[i][j]+1, j)
        print(')', end="")


n = 6
p = [30, 35, 15, 5, 10, 20, 25]
m = [[0 for i in range(n+1)] for i in range(n+1)]
s = [[0 for i in range(n+1)] for i in range(n+1)]

matrix_chain(p, n, m, s)
print_result(s, 1, n-1)
print()