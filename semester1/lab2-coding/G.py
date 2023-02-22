import math
from fractions import Fraction

n = int(input())
print(n)
s = input()
fq = [0 for i in range(n)]
sumfq = 0
for c in s:
    fq[ord(c) - ord('a')] += 1
    sumfq += 1
for i in range(n):
    print(fq[i], end=' ')
    fq[i] = Fraction(fq[i], sumfq)
print()

left, right = Fraction(0), Fraction(1)
for c in s:
    id = ord(c) - ord('a')
    start = left
    for i in range(id):
        start += fq[i] * (right - left)
    left, right = start, start + fq[id] * (right - left)

q = 1
while True:
    t = math.ceil(left * (1 << q))
    if t <= right * (1 << q):
        p = int(t)
        break
    q += 1

res = bin(p)
# print(res)
# print(bin(int(res, base=2) // 2))
res = res[2:]
while len(res) < q:
    res = '0' + res
print(res)
