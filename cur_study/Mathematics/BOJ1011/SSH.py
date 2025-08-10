from sys import stdin
from math import sqrt


def sol(x, y):
    length = y - x
    n = int(sqrt(length))
    if n**2 == length:
        return 2*n - 1
    elif n**2 + n >= length:
        return 2 * n
    else:
        return 2*n + 1


for _ in range(int(stdin.readline().rstrip())):
    print(sol(*map(int, stdin.readline().split())))
