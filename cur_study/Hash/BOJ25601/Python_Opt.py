import sys
sys.setrecursionlimit(10**6) 
input = sys.stdin.readline

def find_ancestor(descendant, target, parent_map):
    if descendant not in parent_map:
        return False
    
    parent = parent_map[descendant]
    
    if parent == target:
        return True
    
    return find_ancestor(parent, target, parent_map)

n = int(input())
parents = {}
for _ in range(n - 1):
    child, parent = input().rstrip().split()
    parents[child] = parent

person1, person2 = input().rstrip().split()

if find_ancestor(person1, person2, parents) or find_ancestor(person2, person1, parents):
    print(1)
else:
    print(0)
