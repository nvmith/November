import sys
input = sys.stdin.readline

n, x = map(int, input().split())

layer = [1] * 51
cnt_p = [1] * 51

for i in range(1, 51):
    layer[i] = 2 * layer[i - 1] + 3
    cnt_p[i] = 2 * cnt_p[i - 1] + 1

def eat(n, x):
    if n == 0:
        return 1 if x >= 1 else 0
    
    total_layer = layer[n]
    mid = layer[n - 1] + 2
    
    if x == 1:
        return 0
    
    elif x <= 1 + layer[n-1]:
        return eat(n-1, x-1)
        
    elif x == mid:
        return cnt_p[n-1] + 1
    
    elif x < total_layer:
        return cnt_p[n-1] + 1 + eat(n-1, x - mid)
        
    else: 
        return cnt_p[n]

result = eat(n,x)
print(result)
