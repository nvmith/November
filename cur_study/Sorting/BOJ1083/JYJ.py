n = int(input())
num = list(map(int, input().split()))
s = int(input())

for i in range(n):
    max_pos = i
    for j in range(i + 1, min(n, i + s + 1)):
        if num[j] > num[max_pos]:
            max_pos = j

    if max_pos == i or max_pos - i > s:
        continue    
    s -= (max_pos - i)

    for j in range(max_pos, i, -1):
        num[j], num[j - 1] = num[j - 1], num[j]

    if s == 0:
        break

for i in num:
    print(i, end = ' ')
