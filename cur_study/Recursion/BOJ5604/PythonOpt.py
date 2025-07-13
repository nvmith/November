import sys
input = sys.stdin.readline

n = int(input())

def sol(target, pivot, temp):
    if target == 0:
        print(*temp)
        return
    
    for i in range(min(target, pivot), 0, -1):
        temp.append(i)
        sol(target-i, i, temp)
        temp.pop()
    
sol(n, n, [])
