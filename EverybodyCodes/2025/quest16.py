from functools import cache, cached_property
from collections import deque, Counter, OrderedDict
from itertools import *
from math import *
import sys
from dataclasses import dataclass
import re
from builtins import pow

GRID_MOVES = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def part1(a):
    a = a[0].split(",")

    cols = 91
    ans = [0] * cols

    for x in a:
        x = int(x)
        ind = x
        while ind < cols:
            ans[ind] += 1
            ind += int(x)

    print(sum(ans))


def part2(a):
    a = a[0].split(",")
    a = list(map(int, a))
    a.insert(0, 0)

    ans = 1
    cols = len(a)
    exp = [0] * cols

    for i, x in enumerate(a):
        y = exp[i]
        if x > y:
            ans *= i
            ind = i
            while ind < cols:
                exp[ind] += 1
                ind += i
    print(ans)


def part3(a):
    a = a[0].split(",")
    a = list(map(int, a))
    a.insert(0, 0)

    ans = 0
    cols = len(a)
    exp = [0] * cols
    seen = list()

    for i, x in enumerate(a):
        y = exp[i]
        if x > y:
            seen.append(i)
            ind = i
            while ind < cols:
                exp[ind] += 1
                ind += i

    def bins(ln, sn):
        return sum(ln // k for k in sn)

    blocks = 202520252025000
    low = 0
    high = blocks * 2
    ans = 0
    while low < high:
        mid = (low + high) // 2
        blks = bins(mid, seen)
        if blks < blocks:
            ans = mid
            low = mid + 1
        elif blks > blocks:
            high = mid

    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    # part1(G)
    part2(G)
    # part3(G)
    return 0


if __name__ == "__main__":
    main()
