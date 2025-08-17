from sys import stdin

m, n = map(int, stdin.readline().split())
pool = []

for ___ in range(m):
    pool.append(list(map(int, stdin.readline().split())))
pool = sorted(pool, key=lambda x: x[0])

cur_pos = 0

cnt = 0

for i in range(m):
    if pool[i][0] > cur_pos:
        cur_pos = pool[i][0]

    if (pool[i][1] - cur_pos) % n == 0:
        cnt += (pool[i][1] - cur_pos) // n
        cur_pos += (pool[i][1] - cur_pos) // n * n

    else:
        cnt += (pool[i][1] - cur_pos) // n + 1
        cur_pos += ((pool[i][1] - cur_pos) // n + 1) * n


print(cnt)
