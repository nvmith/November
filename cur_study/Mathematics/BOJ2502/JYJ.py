import sys
input = sys.stdin.readline

d, k = map(int, input().split())

a_temp = [0] * (d + 1)
b_temp = [0] * (d + 1)

a_temp[1] = 1
b_temp[2] = 1

for i in range(3, d + 1):
    a_temp[i] = a_temp[i-1] + a_temp[i-2]
    b_temp[i] = b_temp[i-1] + b_temp[i-2]


co_a = a_temp[d]
co_b = b_temp[d]

for a in range(1, 100001):

    re = k - (co_a * a)
   
    if re > 0 and re % co_b == 0:
        b = re // co_b

        if b >= a:
            print(a)
            print(b)
            sys.exit()
