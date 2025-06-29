import sys
from collections import deque

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

nums = [str(sys.stdin.readline().rstrip()) for _ in range(n)]

ans = set()


def recursive(pos, q, string):
    pos += 1
    q = deque(q)

    if pos == k:
        while q:
            ans.add(string + q.pop())
    else:
        for ii in q:
            new_string = string + ii
            tmp2 = deque(q)
            tmp2.remove(ii)
            recursive(pos, tmp2, new_string)

    return


for i in nums:
    tmp = deque(nums)
    tmp.remove(i)
    string_first = i
    recursive(1, tmp, string_first)

print(len(ans))

