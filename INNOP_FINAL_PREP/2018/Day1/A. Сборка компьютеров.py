import getpass
import sys
import math
import random
import itertools
import bisect

files = True
debug = False

if getpass.getuser() == 'frohenk' and files:
    debug = True
    sys.stdin = open("test.in")
    # sys.stdout = open('test.out', 'w')
elif files:
    fname = "computers"
    sys.stdin = open("%s.in" % fname)
    sys.stdout = open('%s.out' % fname, 'w')


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


a1, a2, a3 = ria()
b1, b2, b3 = ria()

n1 = min(a1, b1)
a1 -= n1
b1 -= n1

n2 = min(a2, b2)
a2 -= n2
b2 -= n2


n3 = min(a1, b3)
b3 -= n3
a1 -= n3

n4 = min(a2, b3)
b3 -= n4
a2 -= n4

n5 = min(b1, a3)
a3 -= n5
b1 -= n5

n6 = min(b2, a3)
a3 -= n6
b2 -= n6

n7 = min(b3, a3)
a3 -= n7
b3 -= n7

print(n1 + n2 + n3 + n4 + n5 + n6 + n7)
