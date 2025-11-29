from functools import cache, cached_property
from collections import deque, Counter, OrderedDict
from itertools import *
from math import *
import sys
import heapq
from copy import deepcopy
from dataclasses import dataclass
import re
from builtins import pow

GRID_MOVES = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def part1(a):
    ans = 0
    skip = 0
    for i, x in enumerate(a):
        skip = 1 - skip
        for j, y in enumerate(x):
            if y != "T":
                continue
            if j < len(x) - 1:
                if x[j + 1] == "T":
                    ans += 1

            if i == 0 or j % 2 == skip:
                continue
            prev = a[i - 1]

            if prev[j] == "T":
                ans += 1
    print(ans)


def part2(a):
    ans = 0
    skip = 0
    jumps = dict()
    for i, x in enumerate(a):
        skip = 1 - skip
        for j, y in enumerate(x):
            if y not in "SET":
                continue
            if (i, j) not in jumps:
                jumps[(i, j)] = list()
            if j < len(x) - 1:
                if x[j + 1] in "SET":
                    if (i, j + 1) not in jumps:
                        jumps[(i, j + 1)] = list()
                    jumps[(i, j)].append((i, j + 1))
                    jumps[(i, j + 1)].append((i, j))
                    ans += 1

            if i == 0 or j % 2 == skip:
                continue
            prev = a[i - 1]

            if prev[j] in "SET":
                if (i - 1, j) not in jumps:
                    jumps[(i - 1, j)] = list()

                jumps[(i, j)].append((i - 1, j))
                jumps[(i - 1, j)].append((i, j))
                ans += 1

    R = len(a)
    C = len(a[0])
    sr, sc = -1, -1
    er, ec = -1, -1
    for r in range(R):
        for c in range(C):
            if a[r][c] == "S":
                sr, sc = r, c
            elif a[r][c] == "E":
                er, ec = r, c

    q = deque()
    q.append((sr, sc, 0))
    seen = set()
    while q:
        r, c, j = q.popleft()
        if (r, c) == (er, ec):
            print(j)
            return
        if (r, c) in seen:
            continue
        seen.add((r, c))
        for nr, nc in jumps[(r, c)]:
            q.append((nr, nc, j + 1))

    print(ans)


def rotate(a):
    pr = list()
    C = len(a[0])
    sr = len(a) - 1
    sc = C // 2
    for i in range(len(a)):
        tr, tc = sr, sc
        prc = list()
        for j in range(i):
            prc += "."
        f = True
        while len(prc) + i < C:
            prc += a[sr][sc]
            if f:
                sr -= 1
            else:
                sc -= 1
            f = not f

        for j in range(i):
            prc += "."
        pr.append(prc)
        sr, sc = tr - 1, tc + 1
    return pr


def part3(a):
    R = len(a)
    C = len(a[0])
    ans = 0
    r1 = a
    r2 = rotate(a)
    r3 = rotate(r2)
    r4 = rotate(r3)
    for i in range(R):
        for j in range(C):
            assert r1[i][j] == r4[i][j]

    def find_jumps(a, b):
        skip = 0
        jumps = dict()
        for i in range(len(a)):
            skip = 1 - skip
            for j, y in enumerate(a[i]):
                if y not in "SET":
                    continue

                if (i, j) not in jumps:
                    jumps[(i, j)] = list()
                jumps[(i, j)].append((i, j))

                x = b[i]

                left, right = None, None
                if j > 1:
                    left = x[j - 1]
                if j < len(x) - 1:
                    right = x[j + 1]

                if left and left in "SET":
                    jumps[(i, j)].append((i, j - 1))
                if right and right in "SET":
                    jumps[(i, j)].append((i, j + 1))

                if i > 0 and j % 2 != skip:
                    prev = b[i - 1]
                    if prev[j] in "SET":
                        jumps[(i, j)].append((i - 1, j))

                if i < len(a) - 1 and j % 2 == skip:
                    next = b[i + 1]
                    if next[j] in "SET":
                        jumps[(i, j)].append((i + 1, j))

        return jumps

    jumps1 = find_jumps(r1, r2)
    jumps2 = find_jumps(r2, r3)
    jumps3 = find_jumps(r3, r1)

    sr, sc = -1, -1
    er1, ec1 = -1, -1
    er2, ec3 = -1, -1
    er2, ec3 = -1, -1
    for r in range(R):
        for c in range(C):
            if a[r][c] == "S":
                sr, sc = r, c
            elif a[r][c] == "E":
                er1, ec1 = r, c

    for r in range(R):
        for c in range(C):
            if r2[r][c] == "E":
                er2, ec2 = r, c

    for r in range(R):
        for c in range(C):
            if r3[r][c] == "E":
                er3, ec3 = r, c

    q = deque()
    q.append((sr, sc, 0, 1))
    seen1 = set()
    seen2 = set()
    seen3 = set()

    while q:
        r, c, j, m = q.popleft()
        # print(r, c, j, m)
        if m == 1:
            if (r, c) == (er1, ec1):
                print(j)
                return
            if (r, c) in seen1:
                continue
            seen1.add((r, c))

            if (r, c) in jumps1:
                for nr, nc in jumps1[(r, c)]:
                    q.append((nr, nc, j + 1, 2))

        if m == 2:
            if (r, c) == (er2, ec2):
                print(j)
                return
            if (r, c) in seen2:
                continue
            seen2.add((r, c))

            if (r, c) in jumps2:
                for nr, nc in jumps2[(r, c)]:
                    q.append((nr, nc, j + 1, 3))

        if m == 3:
            if (r, c) == (er3, ec3):
                print(j)
                return
            if (r, c) in seen3:
                continue
            seen3.add((r, c))

            if (r, c) in jumps3:
                for nr, nc in jumps3[(r, c)]:
                    q.append((nr, nc, j + 1, 1))

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
