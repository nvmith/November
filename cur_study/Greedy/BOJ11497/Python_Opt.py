import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    logs = sorted(list(map(int, input().split())))
    
    max_diff = 0
    for i in range(2, n):
        diff = logs[i] - logs[i-2]
        max_diff = max(max_diff, diff)
            
    print(max_diff)
