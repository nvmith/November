def solution(numbers, target):
    answer = 0

    def dfs(idx, target):
        if idx == len(numbers):
            if target == 0:
                nonlocal answer
                answer += 1
            return
        dfs(idx + 1, target - numbers[idx])
        dfs(idx + 1, target + numbers[idx])

    dfs(0, target)
    return answer
