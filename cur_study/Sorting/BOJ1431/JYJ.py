n  = int(input())
serial = list()
for _ in range(n):
    serial.append(input())

def ssum(x):
    x = list(x)
    result = 0
    for i in x:
        if i.isnumeric():
            result += int(i)
    return result


serial.sort(key = lambda x : (len(x), ssum(x), x))

for i in serial:
    print(i)
