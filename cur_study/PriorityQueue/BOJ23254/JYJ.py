import heapq
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
n *= 24
base_score = list(map(int, input().split()))
increase_score = list(map(int, input().split()))

heap = []
for i in range(m):
    heap.append([-increase_score[i], i])
heapq.heapify(heap)

while heap:
    increase, idx = heapq.heappop(heap)
    increase *= -1
    
    x = (100 - base_score[idx]) // increase
    
    if (100 - base_score[idx]) % increase:
        heapq.heappush(heap, [-(100 - base_score[idx] - x * increase), idx])
        
    if x > n:
        x = n
    
    base_score[idx] += increase*x
    n -= x
    
    if n == 0:
        break
    
print(sum(base_score))
