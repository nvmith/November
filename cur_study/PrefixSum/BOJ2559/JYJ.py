import sys
input = sys.stdin.readline

n, k = map(int, input().split())
nums = list(map(int,input().split()))

result = -100 * k

prefix_sum = [0] * (n+1)

for i in range(n):
    prefix_sum[i+1] = prefix_sum[i] + nums[i]
    
for i in range(k, n+1):
    cur_sum = prefix_sum[i] - prefix_sum[i-k]
    result = max(cur_sum, result)
    
print(result)
