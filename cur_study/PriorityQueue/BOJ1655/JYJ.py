import sys, heapq
input = sys.stdin.readline

n = int(input())
low  = [] 
high = [] 

for _ in range(n):
    x = int(input())
    if not low or x <= -low[0]:
        heapq.heappush(low, -x)
    else:
        heapq.heappush(high, x)
        
    if len(low) > len(high) + 1:
        heapq.heappush(high, -heapq.heappop(low))
    elif len(high) > len(low):
        heapq.heappush(low, -heapq.heappop(high))
    print(-low[0])
