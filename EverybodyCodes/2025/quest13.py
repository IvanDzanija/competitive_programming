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
    ans = 0
    s1 = [1]
    s2 = list()
    f = False
    for x in a:
        f = not f
        if f:
            s1.append(x)
        else:
            s2.append(x)
    while s2:
        s1.append(s2.pop())
    ans = s1[2025 % len(s1)]

    print(ans)


# part3 is the same
def part2(a):
    ans = 0
    s1 = [(0, 1, 1)]
    s2 = list()
    f = False
    total = 1
    for x in a:
        low, high = x.split("-")
        low = int(low)
        high = int(high)
        f = not f
        curr = high - low + 1
        if f:
            s1.append((total, low, high))
            total += curr
        else:
            s2.append((low, high))
    while s2:
        low, high = s2.pop()
        curr = high - low + 1
        s1.append((total, high, low))
        total += curr

    TURNS = 202520252025
    pos = TURNS % total
    for start, low, high in s1:
        end = start + high - low
        if low > high:
            end = start + low - high
        if start <= pos <= end:
            pos -= start
            if low > high:
                ans = low - pos
            else:
                ans = low + pos

    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    # part1(G)
    # part2(G)
    return 0


if __name__ == "__main__":
    main()
