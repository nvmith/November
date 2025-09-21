from math import comb
import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

print(comb(m-1,m-n))
