import math
import sys

input = sys.stdin.readline

t = int(input())
for i in range(t):
    x, y = map(int, input().split())
    distance = y - x
    
    if distance == 1:
        print(1)
        continue
    
    n = int(math.sqrt(distance))
    
    if n*n == distance:
        print(2*n - 1)
    
    elif distance <= n*n + n:
        print(2*n)
        
    else:
        print(2*n + 1)
