import sys
from collections import deque


visited = set()


def bfs(color, graph, start_node):
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    q = deque()
    q.append(start_node)
    visited.add(start_node)

    cnt = 1

    while q:
        x, y = q.popleft()

        if graph[x][y] == color:
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if 0 <= nx < m and 0 <= ny < n:
                    if (nx, ny) not in visited and graph[nx][ny] == color:
                        visited.add((nx, ny))
                        q.append((nx, ny))
                        cnt += 1

    return cnt*cnt


n, m = map(int, sys.stdin.readline().split())

area = []

for _ in range(m):
    area.append(list(map(str, sys.stdin.readline().rstrip())))

blue = 0
white = 0

for i in range(m):
    for ii in range(n):
        if (i, ii) not in visited:

            if area[i][ii] == "W":
                white += bfs("W", area, (i, ii))
            else:
                blue += bfs("B", area, (i, ii))

print(white, blue)
