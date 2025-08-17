import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    tree = list(map(int,input().split()))
    tree.sort()
    left = []
    right = []
    for i in range(len(tree)):
        if len(tree) == 0:
            break
        if i % 2 == 0:
            left.append(tree[i])
        elif i % 2 != 0:
            right.append(tree[i])
    left.sort(reverse=True)
    right.sort(reverse=True)
    
    q = deque()
    for i in left:
        q.appendleft(i)
    for i in right:
        q.append(i)
    result = list(q)
    res = 0
    result.append(result[0])
    for i in range(len(q)-1):
        res = max(abs(q[i] - q[i+1]), res)
    print(res)
