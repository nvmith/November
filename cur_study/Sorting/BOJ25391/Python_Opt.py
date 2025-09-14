import sys
input = sys.stdin.readline
n, m, k = map(int, input().split())

score = []
for _ in range(n):
    score.append(tuple(map(int, input().split())))
score.sort(key=lambda x: -x[1])

result = 0
for i in range(k):
    result += score[i][0]

scores = [s[0] for s in score[k:]]
scores.sort(reverse=True)
result += sum(scores[:m])
print(result)
