import getpass
import sys
import math
import functools
import decimal
import string
import itertools


def lcm(a, b):
    return a * b // math.gcd(a, b)


def ria():
    return [int(i) for i in input().split()]


def dr(v):
    sm = sum([int(i) for i in str(v)])
    return sm if sm < 10 else dr(sm)


files = True
debug = False

if getpass.getuser() == 'frohenk' and files:
    debug = True
    sys.stdin = open("test.in")
    # sys.stdout = open('test.out', 'w')
    pass

ar = []


def count_circles(x, y):
    suma = 0
    # for xc, yc, rc in ar:
    #     if math.hypot(x - xc, y - yc) <= rc:
    #         suma += 1
    print(x,y)
    sys.stdin.flush()

    return int(input())


for x in range(0, 21):
    for y in range(0, 21):
        for r in range(1, 21):
            if x - r >= 0 and x + r <= 20 and y - r >= 0 and y + r <= 20:
                ar.append((x, y, r))

ang = 1.1
eps = 0.001
suma = 0
for xc, yc, rc in ar:
    # print( math.cos(ang))
    x1 = xc + math.cos(ang) * (rc + eps)
    y1 = yc + math.sin(ang) * (rc + eps)
    # print(x1,y1,xc,yc,rc)
    x2 = xc + math.cos(ang) * (rc - eps)
    y2 = yc + math.sin(ang) * (rc - eps)
    suma += count_circles(x2, y2) - (count_circles(x1, y1))

print('Done',suma)