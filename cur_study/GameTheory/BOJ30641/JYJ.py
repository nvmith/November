import sys 
input = sys.stdin.readline
l, u = map(int, sys.stdin.readline().split())
    
sum_val = 0
multi = 1

if l == 1:
    sum_val += 1
    l += 1
    
if u != 1 and l == 2:
    sum_val += 1
    l += 1

if sum_val % 2 == 1:
    print("H")
else:
    print("A")

for i in range(3, u + 1):
    if i % 2 == 1:
        multi = (multi * 26) % 1000000007
    
    if i >= l:
        sum_val = (sum_val + multi) % 1000000007

print(sum_val)
