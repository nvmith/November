import sys, heapq
input = sys.stdin.readline

n = int(input())
low  = [] 
high = [] 

for _ in range(n):
    x = int(input())
    heapq.heappush(low,-x)
    heapq.heappush(high, -heapq.heappop(low))
    
    if len(low) < len(high):
        heapq.heappush(low, -heapq.heappop(high))
    
    print(-low[0])
