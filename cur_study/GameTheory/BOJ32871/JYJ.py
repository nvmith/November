import sys
input = sys.stdin.readline
t = int(input())
for testcase in range(t):
    n,m = map(int, input().split())
    pivot = abs(n-m)
    if n == 1 or m == 1:
        print('YES')
        continue
    if pivot % 2 == 0:
        print('NO')
    else:
        print('YES')
