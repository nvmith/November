from sys import stdin


def recursive(left, right, top, bot, length):
    sum_cookies = []

    for i in range(top, bot):
        for ii in range(left, right):
            sum_cookies.append(cookie[i][ii])

    c = sum(sum_cookies)
    if length == 1:
        answer.append(c)
        return

    mid_x = (left + right) // 2
    mid_y = (top + bot) // 2

    if c % 4 == 0:
        recursive(mid_x, right, top, mid_y, length // 2)  # 우상단
        recursive(left, mid_x, mid_y, bot, length // 2)  # 좌하단
        recursive(mid_x, right, mid_y, bot, length // 2)  # 우하단

    elif c % 4 == 1:
        recursive(left, mid_x, top, mid_y, length // 2)  # 좌상단
        recursive(left, mid_x, mid_y, bot, length // 2)  # 좌하단
        recursive(mid_x, right, mid_y, bot, length // 2)  # 우하단

    elif c % 4 == 2:
        recursive(left, mid_x, top, mid_y, length // 2)  # 좌상단
        recursive(mid_x, right, top, mid_y, length // 2)  # 우상단
        recursive(mid_x, right, mid_y, bot, length // 2)  # 우하단
    else:
        recursive(left, mid_x, top, mid_y, length // 2)  # 좌상단
        recursive(mid_x, right, top, mid_y, length // 2)  # 우상단
        recursive(left, mid_x, mid_y, bot, length // 2)  # 좌하단


T = int(stdin.readline())
for _ in range(T):
    n = int(stdin.readline())
    cookie = []

    answer = []

    for u in range(n):
        cookie.append(list(map(int, stdin.readline().rstrip())))

    recursive(0, n, 0, n, n)
    print(sum(answer))
