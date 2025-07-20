import sys
input = sys.stdin.readline

n, k = map(int, input().split())

nums = list(map(int, input().split()))

cnt = 0
cur_sum = 0
sum_cnt = {0: 1}

for i in nums:
    cur_sum += i
    target = cur_sum - k
    cnt += sum_cnt.get(target, 0)
    sum_cnt[cur_sum] = sum_cnt.get(cur_sum, 0) + 1

print(cnt)
