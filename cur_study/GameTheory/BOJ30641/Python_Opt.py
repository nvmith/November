import sys


L, U = map(int, sys.stdin.readline().split())

sum_val = 0
multi = 1

if L == 1:
    sum_val += 1
    L += 1

if U != 1 and L == 2:
    sum_val += 1
    L += 1

if sum_val % 2 == 1:
    print("H")
else:
    print("A")

for i in range(3, U + 1):
    if i % 2 == 1:
        multi = (multi * 26) % 1000000007

    if i >= L:
        sum_val = (sum_val + multi) % 1000000007

print(sum_val)
