import sys
import heapq
input = sys.stdin.readline

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.rank = [0] * (n + 1)

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        p = self.find(a)
        q = self.find(b)
        if p != q:
            if self.rank[p] < self.rank[q]:
                self.parent[p] = q
            elif self.rank[p] > self.rank[q]:
                self.parent[q] = p
            else:
                self.parent[q] = p
                self.rank[p] += 1

def kruskal(n, edges):
    heapq.heapify(edges)
    uf = UnionFind(n)

    min_cost = 0
    edges_used = 0
    max_edge_weight = 0

    while edges and edges_used < n - 1:
        w, u, v = heapq.heappop(edges)
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            min_cost += w
            max_edge_weight = max(max_edge_weight, w)
            edges_used += 1

    if edges_used != n - 1:
        return -1
    return min_cost - max_edge_weight

n, m = map(int, input().split())
edges = []
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append((w, u, v))

print(kruskal(n, edges))
