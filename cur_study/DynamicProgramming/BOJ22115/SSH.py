n, k = map(int, input().split())
coffee = sorted(list(map(int, input().split())), reverse=True)
MAX = k+1
if k in coffee:
    print(1)
    exit()
if sum(coffee) < k:
    print(-1)
    exit()

dp = [MAX for _ in range(k+1)]
dp[0] = 0

for i in coffee:
    for j in range(k, i-1, -1):
        if i == j:
            dp[j] = 1
        else:
            dp[j] = min(dp[j], dp[j - i] + 1)

print(dp[k] if dp[k] != MAX else -1)
