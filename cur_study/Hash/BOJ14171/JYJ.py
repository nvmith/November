import sys
input = sys.stdin.readline
n = int(input())

cs = {}

for _ in range(n):
    c, s = input().split()
    c = c[:2]
    
    if c != s:
        key = (c, s)
        cs[key] = cs.get(key, 0) + 1

cnt = 0
for (k1, k2), val in cs.items():
    pair_key = (k2, k1)
    if pair_key in cs:
        cnt += val * cs[pair_key]

print(cnt // 2)
