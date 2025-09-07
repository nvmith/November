from sys import stdin

triangle = []
n = int(stdin.readline().rstrip())
for _ in range(n):
    triangle.append(list(map(int, stdin.readline().rstrip().split())))

for i in range(n-2, -1, -1):
    for j in range(len(triangle[i])):
        tmp = -1
        for k in range(2):
            tmp = max(triangle[i+1][j+k] + triangle[i][j], tmp)

        triangle[i][j] = tmp

print(triangle[0][0])
