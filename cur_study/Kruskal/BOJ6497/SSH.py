import sys


def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]


def union(x, y):
    find_a = find(x)
    find_b = find(y)

    if find_a < find_b:
        parent[find_b] = find_a
    else:
        parent[find_a] = find_b


while True:
    m, n = map(int, sys.stdin.readline().split())

    if m == 0 and n == 0:
        break

    city = []
    parent = [i for i in range(m + 1)]

    for _ in range(n):
        tmp = list(map(int, sys.stdin.readline().split()))
        city.append((tmp[0], tmp[1], tmp[2]))

    city = sorted(city, key=lambda x: x[2])

    total_weight = 0
    weight = 0

    for a, b, c in city:
        total_weight += c
        if find(a) != find(b):
            union(a, b)
            weight += c

    print(total_weight - weight)
