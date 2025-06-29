import sys
input = sys.stdin.readline
n = int(input())

dec_nums = []

def gen_number(num):
    dec_nums.append(num)
    before = num % 10
    for i in range(before):
        new_num = num * 10 + i
        gen_number(new_num)
        
for i in range(10):
    gen_number(i)
    
dec_nums.sort()

if n >= len(dec_nums):
    print(-1)
else:
    print(dec_nums[n])
