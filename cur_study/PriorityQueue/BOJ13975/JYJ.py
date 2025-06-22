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
        ans += x + y
        heapq.heappush(heap, x + y)
    print(ans)
