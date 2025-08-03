import sys
input = sys.stdin.readline

n = int(input())

cast = {}

for _ in range(n-1):
    a, b = map(str, input().rstrip().split())
    cast[a] = b
    

c, p = map(str, input().rstrip().split())
    
tmp1 = c
tmp2 = p
flag = [False, False]
    
while True:
    f = cast.get(tmp1, -1)
    if f != -1 and f == p:
        print(1)
        exit()
    if f == -1:
        break
    
    tmp1 = f
    
while True:    
    f = cast.get(tmp2, -1)
    if f != -1 and f == c:
        print(1)
        exit()
                
    if f == -1:
        break
    
    tmp2 = f
    
        
print(0)
