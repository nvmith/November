from math import comb
n, k = map(int, input().split())
result = comb(n, k) * (2 ** (k-1))
print(result % (10**9+7))
