import sys

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

def solve(l, r):
    if l > r:
        return

    min_char = '~'
    idx = -1
    for i in range(l, r + 1):
        if not used[i] and s[i] < min_char:
            min_char = s[i]
            idx = i
    
    if idx == -1:
        return

    used[idx] = True

    result = "".join([s[i] for i in range(len(s)) if used[i]])
    print(result)

    solve(idx + 1, r)
    solve(l, idx - 1)

s = input().strip()
used = [False] * len(s)

solve(0, len(s) - 1)
