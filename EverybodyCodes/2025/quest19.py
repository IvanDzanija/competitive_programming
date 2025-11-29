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
    holes = dict()
    last = -1
    for x in a:
        x = list(map(int, x.split(",")))
        x_c = x[0]
        y_s = x[1]
        last = max(last, x_c + 1)
        if x_c not in holes:
            holes[x_c] = list()
        for dy in range(x[2]):
            holes[x_c].append(y_s + dy)

    q = deque()
    q.append((0, 0, 0))
    seen = set()
    while q:
        x, y, s = q.popleft()
        if x == last:
            print(s)
            return
        if x in holes and y not in holes[x]:
            continue

        if (x, y) in seen:
            continue
        seen.add((x, y))
        for dx, dy in [(1, -1), (1, 1)]:
            xx = x + dx
            yy = y + dy
            if yy < 0:
                continue
            if dy == 1:
                q.append((xx, yy, s + 1))
            else:
                q.append((xx, yy, s))

    print(ans)


def part3(a):
    ans = 0
    holes = dict()
    last = -1
    for x in a:
        x = list(map(int, x.split(",")))
        x_c = x[0]
        y_s = x[1]
        last = max(last, x_c)
        if x_c not in holes:
            holes[x_c] = list()
        holes[x_c].append((y_s, y_s + x[2] - 1))

    holes_x = sorted(holes.keys())

    prev_x = 0
    intervals = dict()
    intervals[0] = [(0, 0)]

    for i, h_x in enumerate(holes_x):
        intervals[h_x] = list()
        curr = holes[h_x]

        dist = h_x - prev_x

        for prev_min, prev_max in intervals[prev_x]:
            reach_min = prev_min - dist
            reach_max = prev_max + dist

            for ay, by in curr:
                start = max(reach_min, ay)
                end = min(reach_max, by)

                if start <= end:
                    if start % 2 != h_x % 2:
                        start += 1
                    if end % 2 != h_x % 2:
                        end -= 1

                    if start <= end:
                        intervals[h_x].append((start, end))

        prev_x = h_x

    min_y = min(interval[0] for interval in intervals[last])

    ans = (last + min_y) // 2

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
