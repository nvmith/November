import sys
import heapq
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    heap = list(map(int, input().split()))
    ans = 0
    heapq.heapify(heap)
    while len(heap) > 1:
        x = heapq.heappop(heap)
        y = heapq.heappop(heap)
        cost = x + y
        ans += cost
        heapq.heappush(heap, cost)
    print(ans)
