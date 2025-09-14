from sys import stdin
from re import findall

n = int(stdin.readline().rstrip())

serial = []

for i in range(n):
    serial.append(stdin.readline().rstrip())


def is_2(x):
    tmp = (findall(r'\d', x))
    temp = 0
    if tmp:
        for i in tmp:
            temp += int(i)
        return temp
    else:
        return 0


for i in sorted(serial, key=lambda x: (len(x), is_2(x), x)):
    print(i)
