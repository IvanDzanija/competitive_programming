from functools import cache, cached_property
from collections import deque, Counter, OrderedDict
from itertools import *
from math import *
import sys
from dataclasses import dataclass
import re
from copy import deepcopy
from builtins import pow
import heapq

GRID_MOVES = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def part1(a):
    ans = 0
    a = [list(s) for s in a]
    R = len(a)
    C = len(a[0])
    sr, sc = -1, -1
    for i in range(R):
        for j in range(C):
            if a[i][j] == "@":
                sr, sc = i, j

    q = deque()
    q.append((sr, sc))
    seen = set()

    rad = 10
    while q:
        r, c = q.popleft()
        if (r, c) in seen:
            continue
        seen.add((r, c))
        dist = (r - sr) ** 2 + (c - sc) ** 2
        if dist <= rad**2 and a[r][c] != "@":
            ans += int(a[r][c])

        for dr, dc in GRID_MOVES:
            rr = r + dr
            cc = c + dc
            if rr < 0 or rr >= R or cc < 0 or cc >= C:
                continue
            q.append((rr, cc))

    print(ans)


def part2(a):
    ans = 0
    a = [list(s) for s in a]
    R = len(a)
    C = len(a[0])
    sr, sc = -1, -1
    for i in range(R):
        for j in range(C):
            if a[i][j] == "@":
                sr, sc = i, j

    q = deque()
    q.append((sr, sc))
    seen = set()
    gr = dict()

    while q:
        r, c = q.popleft()
        if (r, c) in seen:
            continue
        seen.add((r, c))
        dist = (r - sr) ** 2 + (c - sc) ** 2
        ind = ceil(sqrt(dist))

        if dist <= ind**2 and a[r][c] != "@":
            if ind in gr.keys():
                gr[ind] += int(a[r][c])
            else:
                gr[ind] = int(a[r][c])

        for dr, dc in GRID_MOVES:
            rr = r + dr
            cc = c + dc
            if rr < 0 or rr >= R or cc < 0 or cc >= C:
                continue
            q.append((rr, cc))
    mx = 0
    for x, y in gr.items():
        if y > mx:
            mx = y
            ans = x * y

    print(ans)


def part3(a):
    ans = 0
    a = [list(s) for s in a]
    R = len(a)
    C = len(a[0])
    sr, sc = -1, -1
    lr, lc = -1, -1

    for i in range(R):
        for j in range(C):
            if a[i][j] == "S":
                sr, sc = i, j
                a[i][j] = "0"
            elif a[i][j] == "@":
                lr, lc = i, j

    for rad in range(1, R):
        blocked = set()
        for r in range(R):
            for c in range(C):
                if (r - lr) ** 2 + (c - lc) ** 2 <= rad**2:
                    blocked.add((r, c))
        time = float("inf")
        seen = dict()

        pq = list()
        heapq.heappush(pq, (0, sr, sc, 0))
        while pq:
            cost, r, c, ray = heapq.heappop(pq)

            if cost >= (rad + 1) * 30:
                continue

            if r == sr and c == sc and ray != 0:
                time = cost
                print(time * rad)
                return
                # break

            state = (r, c, ray)
            if state in seen and seen[state] <= cost:
                continue
            seen[state] = cost

            for dr, dc in GRID_MOVES:
                rr = r + dr
                cc = c + dc

                if (
                    rr < 0
                    or rr >= R
                    or cc < 0
                    or cc >= C
                    or (rr, cc) in blocked
                    or (rr, cc) == (lr, lc)
                ):
                    continue

                next_ray = ray
                if r >= lr:
                    if c == lc - 1 and cc == lc:
                        next_ray += 1
                    elif c == lc and cc == lc - 1:
                        next_ray -= 1

                next_cost = cost + int(a[rr][cc])

                heapq.heappush(pq, (next_cost, rr, cc, next_ray))

    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    # part1(G)
    # part2(G)
    part3(G)
    return 0


if __name__ == "__main__":
    main()
