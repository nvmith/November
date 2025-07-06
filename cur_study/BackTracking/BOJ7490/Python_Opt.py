import sys
input = sys.stdin.readline

cal = ['+', '-', ' ']

def dfs(n, idx, expr, prev_num, total, last_op):
    if idx > n:
        if total == 0:
            ans.append(''.join(expr))
        return

    for op in cal:
        expr.append(op)
        expr.append(str(idx))

        if op == ' ':
            next_num = int(str(prev_num) + str(idx))
            dfs(n, idx + 1, expr, next_num, total - prev_num + next_num, last_op)
        elif op == '+':
            dfs(n, idx + 1, expr, idx, total + idx, '+')
        else:
            dfs(n, idx + 1, expr, -idx, total - idx, '-')

        expr.pop()
        expr.pop()

t = int(input())
for _ in range(t):
    n = int(input())
    ans = []

    dfs(n, 2, ['1'], 1, 1, '+')

    ans.sort()
    for a in ans:
        print(a)
    print()
