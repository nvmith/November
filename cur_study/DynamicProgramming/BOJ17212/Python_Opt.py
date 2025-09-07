n = int(input())
dp = [0 for _ in range(n+1)]

for i in range(1, n+1):
    temp = []
    if i >= 7:
        temp.append(dp[i-7])
    if i >= 5:
        temp.append(dp[i-5])
    if i >= 2:
        temp.append(dp[i-2])
    if i >= 1:
        temp.append(dp[i-1])
    dp[i] = min(temp) + 1
print(dp[n])
