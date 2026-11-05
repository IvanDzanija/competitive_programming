from functools import cache, cached_property
import heapq
import bisect
from collections import deque, Counter, OrderedDict
from itertools import *
from math import *
import sys
from queue import PriorityQueue
from dataclasses import dataclass
import re
from builtins import pow

GRID_MOVES = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def part1(a):
    ans = 0
    a = a[0].split(",")
    e = (-1, -1)
    r, c = 0, 0
    dir = "U"
    walls = set()
    top, bot, left, right = float("inf"), float("-inf"), float("inf"), float("-inf")
    for x in a:
        d, v = x[0], x[1:]
        if d == "L":
            if dir == "U":
                dir = d
            elif dir == "D":
                dir = "R"
            elif dir == "R":
                dir = "U"
            else:
                dir = "D"
        else:
            if dir == "U":
                dir = d
            elif dir == "D":
                dir = "L"
            elif dir == "R":
                dir = "D"
            else:
                dir = "U"
        for i in range(int(v)):
            if dir == "U":
                r -= 1
            elif dir == "D":
                r += 1
            elif dir == "R":
                c += 1
            else:
                c -= 1

            walls.add((r, c))
            top = min(top, r)
            bot = max(bot, r)
            left = min(left, c)
            right = max(right, c)
        e = (r, c)
    q = deque()
    q.append((0, 0, 0))
    while q:
        r, c, s = q.popleft()
        if (r, c) == e:
            ans = s
            break
        if (r, c) in walls:
            continue
        walls.add((r, c))
        for dr, dc in GRID_MOVES:
            rr = r + dr
            cc = c + dc
            if rr < top or rr > bot or cc < left or cc > right:
                continue
            q.append((rr, cc, s + 1))

    print(ans)


def part2(a):
    ans = 0
    a = a[0].split(",")
    e = (-1, -1)
    r, c = 0, 0
    dir = "U"
    walls = set()
    top, bot, left, right = float("inf"), float("-inf"), float("inf"), float("-inf")
    for x in a:
        d, v = x[0], x[1:]
        if d == "L":
            if dir == "U":
                dir = d
            elif dir == "D":
                dir = "R"
            elif dir == "R":
                dir = "U"
            else:
                dir = "D"
        else:
            if dir == "U":
                dir = d
            elif dir == "D":
                dir = "L"
            elif dir == "R":
                dir = "D"
            else:
                dir = "U"
        for i in range(int(v)):
            if dir == "U":
                r -= 1
            elif dir == "D":
                r += 1
            elif dir == "R":
                c += 1
            else:
                c -= 1
            walls.add((r, c))
            top = min(top, r)
            bot = max(bot, r)
            left = min(left, c)
            right = max(right, c)
        e = (r, c)

    q = deque()
    q.append((0, 0, 0))
    while q:
        r, c, s = q.popleft()
        if (r, c) == e:
            ans = s
            break
        if (r, c) in walls:
            continue
        walls.add((r, c))

        for dr, dc in GRID_MOVES:
            rr = r + dr
            cc = c + dc
            if rr < top or rr > bot or cc < left or cc > right:
                continue
            q.append((rr, cc, s + 1))

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
