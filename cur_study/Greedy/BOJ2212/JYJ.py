import sys
input = sys.stdin.readline

n = int(input())
k = int(input())
censor = list(map(int, input().split()))

if k >= n:
    print(0)
    exit()

censor.sort()

big = censor[-1]
small = censor[0]

term = []
for i in range(len(censor)-1):
    term.append((censor[i+1] - censor[i]))

term.sort(reverse=True)

term = term[:k-1]

result = big - small
for i in term:
    result = result - i

print(result)
