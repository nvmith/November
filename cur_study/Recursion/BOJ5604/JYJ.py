import sys
input = sys.stdin.readline

n = int(input())

def recursion(target, pivot, temp):
    if target == 0:
        for i in temp:
            print(i, end=' ')
        print()
        return
    
    for i in range(min(target, pivot), 0, -1):
        temp.append(i)
        recursion(target-i, i, temp)
        temp.pop()
    
recursion(n, n, [])
