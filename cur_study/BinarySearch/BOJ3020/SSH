import sys
import bisect


def lower_bound(target, area):
    start = 0
    end = len(area)

    while start < end:
        mid = (start + end) // 2

        if area[mid] <= target:
            start = mid + 1
        else:
            end = mid

    return len(area) - end


n, h = map(int, sys.stdin.readline().split())

bot = []    # 석순
top = []    # 종유석

obstacle = [0] * h

for i in range(1, n+1):
    if i % 2 == 1:
        bot.append(int(sys.stdin.readline().rstrip()))
    else:
        top.append(int(sys.stdin.readline().rstrip()))

bot.sort()
top.sort()

ans = sys.maxsize
interval = 0

for i in range(1, h+1):
    bot_cnt = lower_bound(i-1, bot)
    top_cnt = lower_bound(h-i, top)
    cnt = bot_cnt + top_cnt

    if cnt < ans:
        ans = cnt
        interval = 1
    elif cnt == ans:
        interval += 1

print(ans, interval)
