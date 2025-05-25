import sys


def find(p, x):
    if p[x] != x:
        p[x] = find(p, p[x])
    return p[x]


def union(p, x, y):
    find_a = find(p, x)
    find_b = find(p, y)

    if find_a < find_b:
        parent[find_b] = find_a
    else:
        parent[find_a] = find_b


N, M = map(int, sys.stdin.readline().rstrip().split())

parent = [i for i in range(N + 1)]
edges = []

for _ in range(M):
    a, b, c = map(int, sys.stdin.readline().rstrip().split())
    edges.append((a, b, c))

edges = sorted(edges, key=lambda x: x[2])

max_weight = -1
total_weight = 0

for x, y, c in edges:
    if find(parent, x) != find(parent, y):
        union(parent, x, y)
        total_weight += c
        max_weight = max(max_weight, c)

print(total_weight - max_weight)
