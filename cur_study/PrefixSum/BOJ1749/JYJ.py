# python으로는 시간초과 나지만 pypy로는 정답 -> 최적화 필요
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

nums = []
for i in range(n):
    nums.append(list(map(int, input().split())))
    
result = -float('inf')
prefixSum = [[0]*(m+1) for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(1, m+1):
        prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + nums[i-1][j-1]

for y1 in range(1, n + 1):
    for x1 in range(1, m + 1):
        for y2 in range(y1, n + 1):
            for x2 in range(x1, m + 1):
                cur_sum = prefixSum[y2][x2] - prefixSum[y1-1][x2] - prefixSum[y2][x1-1] + prefixSum[y1-1][x1-1]
                result = max(result, cur_sum)
        
print(result)
