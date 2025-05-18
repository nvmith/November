def solution(numbers, target):
    answer = 0

    def dfs(idx, stat):
        if idx == len(numbers) - 1:
            if target == 0:
                nonlocal answer
                answer += 1
            return
        dfs(idx + 1, stat - numbers[idx])
        dfs(idx + 1, stat + numbers[idx])

    dfs(0, target)
    return answer
