import sys

d, k = map(int, sys.stdin.readline().split())

co_a, co_b = 1, 0
for _ in range(d - 1):
    co_a, co_b = co_b, co_a + co_b

for a in range(1, k // (co_a + co_b) + 2):
    remainder = k - (co_a * a)
    
    if remainder > 0 and remainder % co_b == 0:
        b = remainder // co_b
        
        if a <= b:
            print(a)
            print(b)
            break
