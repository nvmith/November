import sys
input = sys.stdin.readline

n = int(input())
tri = []
for _ in range(n):
    tri.append(list(map(int, input().split())))

dp = []
for i in range(1, n+1):
    dp.append([0] * i)
    
if n == 1:    
    dp[0][0] = tri[0][0]
if n >= 2:
    dp[1][0] = tri[0][0] + tri[1][0]
    dp[1][1] = tri[0][0] + tri[1][1]

for i in range(2, n):
    for j in range(len(dp[i])):
        if j == 0:
            dp[i][j] = dp[i-1][j] + tri[i][j]
        elif j == len(dp[i]) - 1:
            dp[i][j] = dp[i-1][j-1] + tri[i][j]            
        else:
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j]

print(max(dp[n-1]))
