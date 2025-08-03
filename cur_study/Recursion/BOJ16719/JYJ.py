import sys
input = sys.stdin.readline

word = input().strip()

def solution(visited):
    
    if all(visited):
        return

    cur_string = "a"
    cur_index = -1
    
    for i in range(len(word)):
        if not visited[i]:
            temp = ""
            for j in range(len(word)):
                if visited[j] or i == j:
                    temp += word[j]
            
            if temp < cur_string:
                cur_string = temp
                cur_index = i

    print(cur_string)

    visited[cur_index] = True
    solution(visited)

visited = [False] * len(word)
solution(visited)
