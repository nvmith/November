from collections import deque
import sys
input = sys.stdin.readline
def bfs(i, j, color):
    q = deque()
    q.append((i,j))
    
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    while q:
        x, y  = q.popleft()
        for _ in range(4):
            nx = x + dx[_]
            ny = y + dy[_]
            if 0 <= nx < n and 0 <= ny < n and (nx, ny) not in visited and graph[nx][ny] == color:
                visited.add((nx, ny))
                q.append((nx, ny))
                
answer = []                
visited = set()
n = int(input())
graph = []
for i in range(n):
    graph.append(list(map(str,input())))
    
cnt = 0
for i in range(n):
    for j in range(n):
        if (i,j) not in visited:
            visited.add((i,j))
            bfs(i,j,graph[i][j])
            cnt += 1
answer.append(cnt)

for i in range(n):
    for j in range(n):
        if graph[i][j] == 'G':
            graph[i][j] = 'R'

cnt = 0
visited = set()
for i in range(n):
    for j in range(n):
        if (i,j) not in visited:
            visited.add((i,j))
            bfs(i,j,graph[i][j])
            cnt += 1
answer.append(cnt)

for i in answer:
    print(i, end = ' ')
    
