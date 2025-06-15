import sys

n = int(sys.stdin.readline())

paper = []

for _ in range(n):
    paper.append(list(map(int, sys.stdin.readline().split())))

color_list = [0, 0]


def recursive(left, right, top, bot):
    color = paper[top][left]

    if bot - top == 1 and right - left == 1:
        color_list[color] += 1
        return

    flag = True

    for i in range(top, bot):
        for j in range(left, right):
            if paper[i][j] != color:
                flag = False
                break
        if not flag:
            break

    if flag:
        color_list[color] += 1
    else:
        mid_x = (left + right) // 2
        mid_y = (top + bot) // 2
        recursive(left, mid_x, top, mid_y)  # 좌상단
        recursive(left, mid_x, mid_y, bot)  # 좌하단
        recursive(mid_x, right, top, mid_y)  # 우상단
        recursive(mid_x, right, mid_y, bot)  # 우하단
    return


recursive(0, len(paper), 0, len(paper[0]))
print(color_list[0])
print(color_list[1])
