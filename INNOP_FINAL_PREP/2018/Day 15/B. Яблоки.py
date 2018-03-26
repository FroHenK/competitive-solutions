import getpass
import sys
import math
import itertools
from decimal import Decimal
import decimal

files = True
debug = False

if getpass.getuser() == 'frohenk' and files:
    debug = True
    sys.stdin = open("test.in")
    # sys.stdout = open('test.out', 'w')
elif files:
    # fname = "gift"
    # sys.stdin = open("%s.in" % fname)
    # sys.stdout = open('%s.out' % fname, 'w')
    pass


def lcm(a, b):
    return a * b // math.gcd(a, b)


def ria():
    return [int(i) for i in input().split()]


def range_sum(a, b):
    ass = (((b - a + 1) // 2) * (a + b))
    if (a - b) % 2 == 0:
        ass += (b - a + 2) // 2
    return ass


def comba(n, x):
    return (math.factorial(n) // math.factorial(n - x)) // math.factorial(x)


arar = [[0], [1]]

for i in range(2, 51):
    cur = 1 + i
    ar = []
    for j in range(i):
        ar.insert(0, cur)
        cur += i * (2 ** j)

    arar.append(ar)
n = ria()[0]
for i in range(n):
    a, b = ria()
    ar = arar[a]
    if b % ar[0] != 0:
        print(-1)
        continue
    k=b//ar[0]
    for j in ar:
        print(k*j,end=' ')
    print()