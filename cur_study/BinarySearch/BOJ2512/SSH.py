import sys
import math

n = int(sys.stdin.readline().rstrip())

hope_budget = list(map(int, sys.stdin.readline().split()))
budget = int(sys.stdin.readline().rstrip())

if sum(hope_budget) <= budget:
    print(max(hope_budget))
    sys.exit()

elif min(hope_budget) >= budget//len(hope_budget):
    print(math.ceil(budget // len(hope_budget)))
    sys.exit()

hope_budget = sorted(hope_budget)

start = 1
end = budget
result_mid = None
while start <= end:
    mid = (start + end) // 2
    result = 0

    for i in hope_budget:
        if i > mid:
            result += mid
        else:
            result += i

    if result > budget:
        end = mid - 1

    elif result < budget:
        start = mid + 1
        result_mid = mid

    else:
        result_mid = mid
        break

print(result_mid)
