def solution(numbers, target):
    cnt = 0
    
    def dfs(idx, amount):
        nonlocal cnt
        if idx == len(numbers):
            if amount == target:
                cnt += 1
            return
        dfs(idx+1, amount + numbers[idx])
        dfs(idx+1, amount - numbers[idx])
        
    dfs(0, 0)
    return cnt
