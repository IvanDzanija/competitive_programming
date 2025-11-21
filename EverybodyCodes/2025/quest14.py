from functools import cache, cached_property
from collections import deque, Counter, OrderedDict
from itertools import *
from copy import deepcopy
from math import *
import sys
from dataclasses import dataclass
import re
from builtins import pow

GRID_MOVES = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def extract(a):
    i = 0
    ext = [[0] * 8 for _ in range(8)]
    for r in range(13, 21):
        j = 0
        for c in range(13, 21):
            ext[i][j] = a[r][c]
            j += 1
        i += 1
    return ext


def count(a):
    res = 0
    for r in range(len(a)):
        for c in range(len(a[0])):
            res += a[r][c]
    return res


def part1(a):
    ans = 0
    n = len(a)
    m = len(a[0])

    next = [[0] * m for _ in range(n)]
    prev = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if a[i][j] == "#":
                prev[i][j] = 1

    steps = 10
    for i in range(1, steps + 1):
        for r in range(n):
            for c in range(m):
                x = prev[r][c]
                neib = 0
                for dr, dc in [(1, 1), (-1, -1), (-1, 1), (1, -1)]:
                    rr = r + dr
                    cc = c + dc
                    if rr < 0 or rr >= n or cc < 0 or cc >= m:
                        continue
                    if prev[rr][cc] == 1:
                        neib += 1

                if x == 1:
                    if neib % 2 == 1:
                        next[r][c] = 1
                    else:
                        next[r][c] = 0
                else:
                    if neib % 2 == 0:
                        next[r][c] = 1
                    else:
                        next[r][c] = 0

        for r in range(n):
            for c in range(m):
                ans += next[r][c]
        prev = deepcopy(next)
    print(ans)


def part2(a):
    ans = 0
    n = len(a)
    m = len(a[0])

    next = [[0] * m for _ in range(n)]
    prev = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if a[i][j] == "#":
                prev[i][j] = 1

    steps = 2025
    for i in range(1, steps + 1):
        for r in range(n):
            for c in range(m):
                x = prev[r][c]
                neib = 0
                for dr, dc in [(1, 1), (-1, -1), (-1, 1), (1, -1)]:
                    rr = r + dr
                    cc = c + dc
                    if rr < 0 or rr >= n or cc < 0 or cc >= m:
                        continue
                    if prev[rr][cc] == 1:
                        neib += 1

                if x == 1:
                    if neib % 2 == 1:
                        next[r][c] = 1
                    else:
                        next[r][c] = 0
                else:
                    if neib % 2 == 0:
                        next[r][c] = 1
                    else:
                        next[r][c] = 0

        for r in range(n):
            for c in range(m):
                ans += next[r][c]
        prev = deepcopy(next)
    print(ans)


def part3(a):
    ans = 0
    n = len(a)
    m = len(a[0])
    h = 34

    b = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if a[i][j] == "#":
                b[i][j] = 1

    next = [[0] * h for _ in range(h)]
    prev = [[0] * h for _ in range(h)]

    seen = dict()
    rep = 0
    steps = 1000000000
    for i in range(1, steps + 1):
        for r in range(h):
            for c in range(h):
                x = prev[r][c]
                neib = 0
                for dr, dc in [(1, 1), (-1, -1), (-1, 1), (1, -1)]:
                    rr = r + dr
                    cc = c + dc
                    if rr < 0 or rr >= h or cc < 0 or cc >= h:
                        continue
                    if prev[rr][cc] == 1:
                        neib += 1

                if x == 1:
                    if neib % 2 == 1:
                        next[r][c] = 1
                    else:
                        next[r][c] = 0
                else:
                    if neib % 2 == 0:
                        next[r][c] = 1
                    else:
                        next[r][c] = 0

        prev = deepcopy(next)

        ext = extract(next)
        if ext == b:
            ans += count(next)

        hashed = tuple(map(tuple, next))
        if hashed in seen.keys():
            rep = i
            break

        seen[hashed] = i

    rem = (steps) // (rep - 1)
    ans *= rem
    steps = steps - (rep - 1) * rem

    for i in range(1, steps + 1):
        for r in range(h):
            for c in range(h):
                x = prev[r][c]
                neib = 0
                for dr, dc in [(1, 1), (-1, -1), (-1, 1), (1, -1)]:
                    rr = r + dr
                    cc = c + dc
                    if rr < 0 or rr >= h or cc < 0 or cc >= h:
                        continue
                    if prev[rr][cc] == 1:
                        neib += 1

                if x == 1:
                    if neib % 2 == 1:
                        next[r][c] = 1
                    else:
                        next[r][c] = 0
                else:
                    if neib % 2 == 0:
                        next[r][c] = 1
                    else:
                        next[r][c] = 0

        prev = deepcopy(next)
        ext = extract(next)
        if ext == b:
            ans += count(next)

    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    # part1(G)
    # part2(G)
    # part3(G)
    return 0


if __name__ == "__main__":
    main()
