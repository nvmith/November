
from sys import stdin

n, m = map(int, stdin.readline().split())
nums = [list(map(int, stdin.readline().split())) for _ in range(n)]

result = -float('inf')

prefixSum = [[0] * (m + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + nums[i - 1][j - 1]

for y1 in range(1, n + 1):
    for y2 in range(y1, n + 1):
        current_sum = 0

        for x in range(1, m + 1):
            col_sum = prefixSum[y2][x] - prefixSum[y1 - 1][x] - prefixSum[y2][x - 1] + prefixSum[y1 - 1][x - 1]
            current_sum += col_sum

            if current_sum > result:
                result = current_sum

            if current_sum < 0:
                current_sum = 0

print(result)
