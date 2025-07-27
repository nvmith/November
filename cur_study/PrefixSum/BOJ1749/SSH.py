from sys import stdin

n, m = map(int, stdin.readline().split())
nums = [list(map(int, stdin.readline().split())) for _ in range(n)]

ans = -10001

for i in range(n):
    for ii in range(m):
        ans = max(ans, nums[i][ii])
        if i > 0 and ii > 0:
            nums[i][ii] += (nums[i-1][ii] + nums[i][ii-1] - nums[i-1][ii-1])
        elif i > 0 and ii == 0:
            nums[i][ii] += nums[i-1][ii]
        elif i == 0 and ii > 0:
            nums[i][ii] += nums[i][ii - 1]

for i in range(n-1, 0, -1):
    for ii in range(m-1, 0, -1):
        for j in range(i-1, 0, -1):
            for jj in range(ii-1, 0, -1):
                ans = max(ans, nums[i][ii] - nums[j][ii] - nums[i][jj] + nums[j][jj])
print(ans)
