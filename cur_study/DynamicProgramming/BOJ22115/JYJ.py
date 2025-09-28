import sys
input = sys.stdin.readline

n, k = map(int, input().split())
caffein = list(map(int,input().split()))

dp = [100001] * (k+1)
dp[0] = 0

for i in caffein:
    for j in range(k, i-1, -1):
        if dp[j-i] != 100001:
            dp[j] = min(dp[j], dp[j-i]+1)

if dp[k] == 100001:
    print(-1)
else:
    print(dp[k])
