s, k = map(int, input().split())
rest = s % k
nums = [s//k] * k
for i in range(rest):
    nums[i] += 1

result = 1
for i in nums:
    result *= i
    
print(result)
