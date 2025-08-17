import sys
import math
input = sys.stdin.readline

n, l = map(int, input().split())
water = []
for _ in range(n):
    water.append(list(map(int, input().split())))

water.sort(key = lambda x : x[0])

cnt = 0
cur_pos = 0

for start, end in water:
    if cur_pos > start:
        start = cur_pos

    cover = end - start
    if cover <= 0:
        continue
    
    need = math.ceil(cover / l)
    cnt += need
    
    cur_pos = start + need * l

print(cnt)
