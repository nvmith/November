"""

    완성
    프로그래머스 타겟 넘버

"""

"""

    1번 풀이

"""

answer = 0


def recur(idx, numbers, target, stat):
    global answer
    if idx == len(numbers) - 1:
        if stat - numbers[idx] == target or stat + numbers[idx] == target:
            answer += 1
        return
    recur(idx + 1, numbers, target, stat - numbers[idx])
    recur(idx + 1, numbers, target, stat + numbers[idx])


def solution1(numbers, target):
    recur(0, numbers, target, 0)
    return answer


"""

    2번 풀이
    
"""

from collections import deque


def bfs(nums, target):
    will_do = deque()
    will_do.append(0)

    while nums:

        tmp = nums.pop()
        temp_list = deque()

        while will_do:
            num = will_do.pop()
            temp_list.append(num + tmp)
            temp_list.append(num - tmp)

        will_do = deque(temp_list)
        temp_list.clear()

    cnt = 0
    for i in will_do:
        if i == target:
            cnt += 1

    return cnt


def solution2(numbers, target):
    numbers = deque(numbers)
    ans = bfs(numbers, target)
    return ans


print(solution1([1, 1, 1, 1, 1], 3))
print(solution2([1, 1, 1, 1, 1], 3))
