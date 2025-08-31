from sys import stdin

def func(num):
    if num < 3:
        return 0

    if num % 2 != 0:
        num += 1
    return num // 2 - 1


ans = 0
l, u = map(int, stdin.readline().rstrip().split())

for i in range(l, u + 1):
    ans += 26 ** func(i)


print("H") if ans % 2 != 0 else print("A")

ans %= ((10 ** 9) + 7)
print(ans)
