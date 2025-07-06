import sys
input = sys.stdin.readline

t = int(input())

def split_cookie(cookie):
    global cnt
    p = len(cookie)
    if p == 1:
        cnt += cookie[0][0]
        return

    total = sum(sum(row) for row in cookie)
    check = total % 4
    x = p // 2

    piece = [
        [row[:x] for row in cookie[:x]],  
        [row[x:] for row in cookie[:x]],  
        [row[:x] for row in cookie[x:]],  
        [row[x:] for row in cookie[x:]]   
    ]

    for i in range(4):
        if i == check:
            continue 
        split_cookie(piece[i])
     
   
for _ in range(t):
    cnt = 0
    n = int(input())
    cookie = []
    for i in range(n):
        cookie.append(list(map(int, input().rstrip())))
    split_cookie(cookie)
    print(cnt)
    
