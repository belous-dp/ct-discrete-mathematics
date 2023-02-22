import math
from fractions import Fraction

n = int(input())
fq = [int(i) for i in input().split()]
sumfq = 0
for i in fq:
    sumfq += i

for i in range(n):
    fq[i] = Fraction(fq[i], sumfq)

s = input()
code = Fraction(int(s, base=2), 1 << len(s))

left, right = Fraction(0), Fraction(1)
for i in range(sumfq):
    start = left
    for id in range(n):
        if start <= code and code < start + fq[id] * (right - left):
            print(chr(id + ord('a')), end='')
            left, right = start, start + fq[id] * (right - left)
            break
        start += fq[id] * (right - left)
