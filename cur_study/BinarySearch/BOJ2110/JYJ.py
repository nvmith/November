import sys
input = sys.stdin.readline

n, c = map(int,input().split())

home = []
for i in range(n):
    home.append(int(input()))
    
home.sort()

start = 1   
end = home[-1] - home[0]
result = 0
while True:
    if start > end:
        break
    mid = (start + end) // 2
    cur = home[0]
    cnt = 1
    for i in range(1,n):
        if home[i] >= cur + mid:
            cur = home[i]
            cnt += 1
    if cnt >= c:
        result = mid
        start = mid + 1
    elif cnt < c:
        end = mid - 1
        
print(result)
