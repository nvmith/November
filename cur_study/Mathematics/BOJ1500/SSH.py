s, k = map(int, input().split())

ans = 1

a = [1] * k

num = s // k

for i in range(k):
    a[i] = num

for i in range(s % k):
    a[i] += 1

for i in range(k):
    ans *= a[i]

print(ans)
