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
 
 
def kekas(st, s, t):
    ar = []
    for i in st:
        if i == '0':
            ar.append(s)
        else:
            ar.append(t)
    return ''.join(ar)
 
 
print('echo kek')
sys.stdout.flush()
input()
print('echo kek')
sys.stdout.flush()
input()
print('echo kek')
sys.stdout.flush()
input()
print('echo kek')
sys.stdout.flush()
input()
print('echo kek')
sys.stdout.flush()
input()
print('echo kek')
sys.stdout.flush()
input()
print('echo kek')
sys.stdout.flush()
input()
print('echo kek')
sys.stdout.flush()
input()
print('echo kek')
sys.stdout.flush()
input()
print('echo win')
