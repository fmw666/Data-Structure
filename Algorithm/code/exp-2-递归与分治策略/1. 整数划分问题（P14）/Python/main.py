def q(n, m):
    if n<1 or m<1:
        return 0
    if n==1 or m==1:
        return 1
    if n < m:
        return q(n, n)
    if n == m:
        return q(n, m-1) + 1
    return q(n, m-1) + q(n-m, m)

print(q(6, 6))