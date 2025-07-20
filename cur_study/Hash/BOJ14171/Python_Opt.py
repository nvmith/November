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
    if k1 < k2:
        pair_key = (k2, k1)
        if cs.get(pair_key):
            cnt += val * cs[pair_key]

print(cnt)
