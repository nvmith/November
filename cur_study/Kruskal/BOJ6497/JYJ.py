import sys

input = sys.stdin.readline
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

result = []
while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break
    parent = [i for i in range(m + 1)]
    edges = []

    for _ in range(n):
        j, k, l = map(int, input().split())
        edges.append((j, k, l))

    edges = sorted(edges, key=lambda x: x[2])

    max_weight = 0
    total_weight = 0

    for a, b, c in edges:
        max_weight += c
        if find(a) != find(b):
            union(a, b)
            total_weight += c
            max_weight = max(max_weight, c)
    
    result.append(max_weight - total_weight)

for i in result:
    print(i)
