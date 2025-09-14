from sys import stdin, exit

n, m = map(int, stdin.readline().rstrip().split())
if m == 1:
    print("YES")
    exit()

listener = sorted([tuple(map(int, stdin.readline().rstrip().split())) for _ in range(n)])

for i in range(1, m):
    flag_1 = False  # 이전 것은 못듣고 다음 것은 들을때
    for people in listener:
        if people[i-1] == 0 and people[i] == 1:
            flag_1 = True
        elif flag_1 and people[i-1] == 1 and people[i] == 0:
            print("NO")
            exit()

print("YES")
