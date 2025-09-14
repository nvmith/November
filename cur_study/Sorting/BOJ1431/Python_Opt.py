import sys
n = int(sys.stdin.readline())
serial = [sys.stdin.readline().strip() for _ in range(n)]

def ssum(x):
    result = 0
    for i in x:
        if i.isnumeric():
            result += int(i)
    return result

serial.sort(key = lambda x : (len(x), ssum(x), x))
print('\n'.join(serial))
