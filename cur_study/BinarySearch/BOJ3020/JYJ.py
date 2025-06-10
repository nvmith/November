import sys
input = sys.stdin.readline

n, h = map(int, input().split())
lines = [0] * h

for i in range(n):
    size = int(input())
    if i % 2 == 0:
        lines[h-size] += 1
    else:
        lines[0] += 1
        lines[size] -= 1

for i in range(1, h):
    lines[i] += lines[i-1]

result = 0
low = min(lines)
for l in lines:
    if l == low:
        result += 1

print(low, result)
