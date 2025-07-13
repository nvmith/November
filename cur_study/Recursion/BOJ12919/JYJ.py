import sys
input = sys.stdin.readline

s = input().rstrip()
t = input().rstrip()

result = 0
def recursion(cur_t):
    global result
    if result == 1:
        return
    
    if cur_t == s:
        result = 1
        return
    
    if len(cur_t) < len(s):
        return
    
    if cur_t[-1] == 'A':
        recursion(cur_t[:-1])
        
    if cur_t[0] == 'B':
        recursion(cur_t[1:][::-1])
        
recursion(t)
print(result)
