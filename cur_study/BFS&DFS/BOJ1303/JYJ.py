from collections import deque
n, m = map(int, input().split())

area = []
visited = set()

for _ in range(m):
    area.append(list(map(str,input())))
    
def bfs(i, j, color):
    q = deque([(i,j)])
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    cnt = 1
    while q:
        x, y = q.popleft()
        for _ in range(4):
            nx = x + dx[_]
            ny = y + dy[_]
            if 0 <= nx < m and 0 <= ny < n and area[nx][ny] == color and (nx, ny) not in visited:
                q.append([nx,ny])
                visited.add((nx,ny))
                cnt += 1
    return cnt*cnt
                
w_cnt = 0
for i in range(m):
    for j in range(n):
        if area[i][j] == 'W' and (i,j) not in visited:
            visited.add((i,j))
            w_cnt += bfs(i, j, 'W')
            
b_cnt = 0
for i in range(m):
    for j in range(n):
        if area[i][j] == 'B' and (i,j) not in visited:
            visited.add((i,j))
            b_cnt += bfs(i, j, 'B')
            
print(w_cnt, b_cnt)
