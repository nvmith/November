from sys import stdin, exit

n = int(stdin.readline().rstrip())

cast = {}

for _ in range(n - 1):
    a, b = map(str, stdin.readline().rstrip().split())
    cast[a] = b

a, b = map(str, stdin.readline().rstrip().split())

tmp1 = a
tmp2 = b

while tmp1 != -1:
    f = cast.get(tmp1, -1)
    if f == b:
        print(1)
        exit()
    tmp1 = f

while tmp2 != -1:
    f = cast.get(tmp2, -1)
    if f == a:
        print(1)
        exit()
    tmp2 = f

print(0)
