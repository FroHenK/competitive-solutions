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
    fname = "next"
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


st = [int(i) for i in input().strip().replace('+', ' ').replace('=', ' ').split()]
if len(st) == 2:
    print('No solution')
    exit(0)
st = list(reversed(st))

keka = False
for i in range(st[1] + 1, st[1] + st[0]+1):
    if (st[1] + st[0]) % i == 0 or (st[1] + st[0]) % i > st[1] or (st[1] + st[0]) // i > 1:
        kd = (st[1] + st[0]) // i
        st_ = (st[1] + st[0])
        if (st_ // i > 1 and not st_ % i > st[1]) and not st_ % i == 0:
            kd-=1

        st = st[2:]
        for k in range(kd):
            st.insert(0, i)

        if st_ % i > st[1] != 0:
            st.insert(0, st_ % i)

        if (st_ // i > 1 and not st_ % i > st[1]) and not st_ % i == 0:
            st.insert(0,i+st_%i)

        keka = True
        break

st = list(reversed(st))
st = [str(i) for i in st]
print(st[0] + '=' + st[1], end='')
for i in range(2, len(st)):
    print('+' + st[i], end='')