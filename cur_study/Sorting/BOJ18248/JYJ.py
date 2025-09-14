n, m = map(int, input().split())

jong = list()
for _ in range(n):
    jong.append(list(map(int, input().split())))

if n == 1 or m == 1:
    print('YES')
    exit()

for i in range(m-1,-1,-1):
    jong.sort(key = lambda x : -x[i])

for i in range(m):
    temp = []
    for j in jong:
        temp.append(j[i])
    ttemp = sorted(temp, reverse = True)
    if temp != ttemp:
        print('NO')
        exit()

print('YES')
