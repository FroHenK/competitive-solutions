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


def solve(st):
    if [st[0], st[4], st[8]].count('x') == 2 and [st[0], st[4], st[8]].count('.') == 1:
        st[0] = 'x'
        st[4] = 'x'
        st[8] = 'x'
        return st
    if [st[2], st[4], st[6]].count('x') == 2 and [st[2], st[4], st[6]].count('.') == 1:
        st[2] = 'x'
        st[4] = 'x'
        st[6] = 'x'
        return st

    for i in range(3):

        if [st[i], st[i + 3], st[i + 6]].count('x') == 2 and [st[i], st[i + 3], st[i + 6]].count('.') == 1:
            st[i] = 'x'
            st[i + 3] = 'x'
            st[i + 6] = 'x'
            return st
        if [st[i * 3], st[i * 3 + 1], st[i * 3 + 2]].count('x') == 2 and [st[i * 3], st[i * 3 + 1],
                                                                          st[i * 3 + 2]].count('.') == 1:
            st[i * 3] = 'x'
            st[i * 3 + 1] = 'x'
            st[i * 3 + 2] = 'x'
            return st

    if st.count('x') == 0:
        st[4] = 'x'
        return st
    if st.count('x') == 1:
        if st[1] == '.' and st[7] == '.' and st[0] == '.' and st[2] == '.':
            st[1] = 'x'
            return st
        if st[1] == '.' and st[7] == '.' and st[6] == '.' and st[8] == '.':
            st[7] = 'x'
            return st

        if st[3] == '.' and st[5] == '.' and st[0] == '.' and st[6] == '.':
            st[3] = 'x'
            return st

        if st[3] == '.' and st[5] == '.' and st[2] == '.' and st[8] == '.':
            st[5] = 'x'
            return st

        exit(1)

    if st.count('x') == 2:
        if st[1] == 'x':
            if st[0] == '.' and st[8] == '.':
                st[0] = 'x'
                return st
            if st[2] == '.' and st[6] == '.':
                st[2] = 'x'
                return st
            exit(1)

        if st[3] == 'x':
            if st[0] == '.' and st[8] == '.':
                st[0] = 'x'
                return st
            if st[6] == '.' and st[2] == '.':
                st[6] = 'x'
                return st
            exit(1)

        if st[5] == 'x':
            if st[8] == '.' and st[0] == '.':
                st[8] = 'x'
                return st
            if st[2] == '.' and st[6] == '.':
                st[2] = 'x'
                return st
            exit(1)

        if st[7] == 'x':
            if st[6] == '.' and st[2] == '.':
                st[6] = 'x'
                return st
            if st[8] == '.' and st[0] == '.':
                st[8] = 'x'
                return st
            exit(1)
    #
    # i1 = 8
    # if st[i1] == '.':
    #     exit(1)
    # if st[i1] == 'x':
    #     time.sleep(45)
    # if st[i1] == 'o':
    #     print('DSAPDSAIFNAOIDNF')

    return st


while True:
    st = input()
    st += input()
    st += input()
    if st == 'x' * 9:
        exit(0)
    _ = solve(list(st))
    _.insert(6, '\n')
    _.insert(3, '\n')
    print(''.join(_))
