import sys
input = sys.stdin.readline

def make_zero(n, idx, exp):
    if idx == n:
        exp += str(idx)
        if eval(exp.replace(' ', '')) == 0:
            ans.append(exp)
        return
    for i in cal:
        make_zero(n, idx+1, exp+str(idx)+i)

t = int(input())
cal = ['+', '-', ' ']
for _ in range(t):
    n = int(input())
    ans = []
    make_zero(n, 1, '')
    ans.sort()
    for i in ans:
        print(i)
    print()
