import sys
input = sys.stdin.readline

n = int(input())
k = int(input())
nums = [input().strip() for _ in range(n)]

res = set()
result = []
def backtracking(nums):
    if len(result) == k:
        res.add(''.join(result))
        return
        
    for i in range(len(nums)):
        result.append(nums[i])
        temp = nums[:i] + nums[i+1:]
        backtracking(temp)
        result.pop()
backtracking(nums)
print(len(res))
