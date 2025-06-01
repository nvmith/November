n = int(input())
budget = list(map(int,input().split()))
m = int(input())

if sum(budget) <= m:
    print(max(budget))
    
else:
    start = 1
    end = m
    mid = 0
    result_mid = 0
    while start <= end:
        mid = (start + end) // 2
        target = 0
        for i in budget:
            if i > mid:
                target += mid
            elif i <= mid:
                target += i
        if target < m:
            start = mid + 1
            result_mid = mid
        elif m < target:
            end = mid - 1
        else:
            result_mid = mid
            break
        
    print(result_mid)
