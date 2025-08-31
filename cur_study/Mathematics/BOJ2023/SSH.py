from math import isqrt

n = int(input())

start_number = [2, 3, 5, 7]
last_number = [1, 3, 7, 9]

ans = set()


def is_prime(num):
    for i in range(2, isqrt(num)):
        if num % i == 0:
            return False
    return True


def recursive(num, limit):

    if len(str(num)) >= limit:
        ans.add(num)
        return

    num *= 10

    for i in last_number:
        if is_prime(num+i):
            recursive(num+i, limit)

    return


for a in start_number:
    recursive(a, n)

ans = sorted(list(ans))

for a in ans:
    print(a)
