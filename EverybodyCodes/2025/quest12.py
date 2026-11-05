from functools import cache, cached_property
from collections import deque, Counter, OrderedDict
from itertools import *
import time
from math import *
import sys
from dataclasses import dataclass
import re
from builtins import pow


def part1(a):
    n = len(a)
    m = len(a[0])

    res = 0
    q = deque()
    q.append((0, 0))
    seen = set()
    while q:
        r, c = q.popleft()
        if (r, c) in seen:
            continue
        seen.add((r, c))
        res += 1
        curr = int(a[r][c])
        for dr, dc in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
            rr = r + dr
            cc = c + dc
            if rr < 0 or rr >= n or cc < 0 or cc >= m or int(a[rr][cc]) > curr:
                continue
            q.append((rr, cc))
    print(res)


def part2(a):
    n = len(a)
    m = len(a[0])

    res = 0
    q = deque()
    q.append((0, 0))
    q.append((n - 1, m - 1))
    seen = set()
    while q:
        r, c = q.popleft()
        if (r, c) in seen:
            continue
        seen.add((r, c))
        res += 1
        curr = int(a[r][c])
        for dr, dc in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
            rr = r + dr
            cc = c + dc
            if rr < 0 or rr >= n or cc < 0 or cc >= m or int(a[rr][cc]) > curr:
                continue
            q.append((rr, cc))
    print(res)


def part3(a):
    n = len(a)
    m = len(a[0])

    bseen = set()
    fans = 0
    for _ in range(3):
        ar, ac = -1, -1
        ans = 0
        sseen = set()

        for i in range(n):
            for j in range(m):
                if (i, j) in sseen:
                    continue
                res = 0
                q = deque()
                q.append((i, j))
                seen = set()
                while q:
                    r, c = q.popleft()
                    if (r, c) in seen or (r, c) in bseen:
                        continue
                    seen.add((r, c))
                    sseen.add((r, c))
                    res += 1
                    curr = int(a[r][c])
                    for dr, dc in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                        rr = r + dr
                        cc = c + dc
                        if (
                            rr < 0
                            or rr >= n
                            or cc < 0
                            or cc >= m
                            or int(a[rr][cc]) > curr
                        ):
                            continue
                        q.append((rr, cc))
                if res > ans:
                    ans = res
                    ar, ac = i, j

        q = deque()
        q.append((ar, ac))
        while q:
            r, c = q.popleft()
            if (r, c) in bseen:
                continue
            bseen.add((r, c))
            fans += 1
            curr = int(a[r][c])
            for dr, dc in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
                rr = r + dr
                cc = c + dc
                if rr < 0 or rr >= n or cc < 0 or cc >= m or int(a[rr][cc]) > curr:
                    continue
                q.append((rr, cc))

    print(fans)


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
