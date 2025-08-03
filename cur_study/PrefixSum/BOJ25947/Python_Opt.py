n, b, a = map(int, input().split())
gift = list(map(int, input().split()))

gift.sort()

prefix_sum = [0] * (n + 1)
for i in range(n):
    prefix_sum[i + 1] = prefix_sum[i] + gift[i]

max_gift = 0

for i in range(1, n + 1):
    num_discount = min(a, i)
        
    cost1 = prefix_sum[i - num_discount]
    cost2 = prefix_sum[i] - cost1
    discount_cost = cost2 // 2

    total_cost = cost1 + discount_cost

    if total_cost <= b:
        max_gift = i
    else:
        break
    
print(max_gift)
