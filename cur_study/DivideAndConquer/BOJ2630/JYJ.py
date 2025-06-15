import sys
input = sys.stdin.readline

n = int(input())

paper = []
for i in range(n):
    paper.append(list(map(int,input().split())))
    
cnt_w = 0
cnt_b = 0
def divide(paper, n):
    temp = 0
    ttemp=0
    for i in paper:
        if 0 not in i:
            temp += 1
    for i in paper:
        if 1 not in i:
            ttemp += 1
    if temp == n:
        cnt_ww()
        return
    elif ttemp == n:
        cnt_bb()
        return

    else:
        n = n // 2
    
        q1 = [row[:n] for row in paper[:n]]
        q2 = [row[n:] for row in paper[:n]]
        q3 = [row[:n] for row in paper[n:]]
        q4 = [row[n:] for row in paper[n:]]
            
        divide(q1, n)
        divide(q2, n)
        divide(q3, n)
        divide(q4, n)
        
def cnt_ww():
    global cnt_w
    cnt_w += 1
    
def cnt_bb():
    global cnt_b
    cnt_b += 1
    
divide(paper, n)
print(cnt_b)
print(cnt_w)
