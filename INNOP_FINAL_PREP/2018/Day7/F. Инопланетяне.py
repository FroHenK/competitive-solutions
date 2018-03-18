import getpass
import sys
import math
import random
import itertools
import bisect
import time

files = True
debug = False

if getpass.getuser() == 'frohenk' and files:
    debug = True
    # sys.stdin = open("test.in")
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


koka = 0


def try_tile(x, y):
    global n
    if x > n or x < 1 or y > n or y < 1:
        return False
    global koka
    koka += 1
    if koka >= 299:
        exit(1)
    print('examine %s %s' % (x, y))
    sys.stdout.flush()
    return input() == 'true'


n, x, y = ria()
kd = 1
while try_tile(x, y + kd):
    kd *= 2
l = y
r = y + kd

while l < r:
    m = (l + r + 1) // 2
    if try_tile(x, m):
        l = m
    else:
        r = m - 1

up = l

kd = 1
while try_tile(x, y - kd):
    kd *= 2
l = y - kd
r = y

while l < r:
    m = (l + r) // 2
    if try_tile(x, m):
        r = m
    else:
        l = m + 1
dn = l
# print(up, dn)
ma = up - dn + 1

kd = 1
while try_tile(x - kd, y):
    kd *= 2
l = x - kd
r = x

while l < r:
    m = (l + r) // 2
    if try_tile(m, y):
        r = m
    else:
        l = m + 1
kak = l
x, y = kak, dn

while try_tile(x - ma * 2, y):
    x -= ma * 2
while try_tile(x, y - ma * 2):
    y -= ma * 2

if try_tile(x - 1, y - 1):
    x -= ma
    y -= ma

# print('solution', x, y)
# print(ma // 2, ma, ma * 2)
cx = x + ma * 2 + ma // 2
cy = y + ma * 2 + ma // 2

if (not try_tile(cx - ma // 2, cy)) or try_tile(cx - ma // 2 - 1, cy):
    exit(1)
if (not try_tile(cx + ma // 2, cy)) or try_tile(cx + ma // 2 + 1, cy):
    exit(1)

if (not try_tile(cx, cy - ma // 2)) or try_tile(cx, cy - ma // 2 - 1):
    exit(1)
if (not try_tile(cx, cy + ma // 2)) or try_tile(cx, cy + ma // 2 + 1):
    exit(1)

print('solution', cx, cy)
sys.stdout.flush()
