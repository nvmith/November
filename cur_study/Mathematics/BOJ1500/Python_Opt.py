s, k = map(int, input().split())
print(pow(s//k + 1, s % k) * pow(s//k, k - s%k))
