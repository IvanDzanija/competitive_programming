import sys
import copy
from collections import deque


moves = [(-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1)]


def part1(a):
    a = a.split("\n")
    q = deque()
    for i, x in enumerate(a):
        for j, y in enumerate(x):
            if y == "D":
                q.append((i, j, 1))
    n = len(a)
    ans = set()
    while q:
        r, c, s = q.popleft()
        if s == 5:
            break
        for dr, dc in moves:
            rr = r + dr
            cc = c + dc
            if rr < 0 or rr >= n or cc < 0 or cc >= n:
                continue
            q.append((rr, cc, s + 1))
            if a[rr][cc] == "S":
                ans.add((rr, cc))

    print(len(ans))


def part2(a):
    a = a.split("\n")
    q = deque()
    sheep = deque()
    for i, x in enumerate(a):
        for j, y in enumerate(x):
            if y == "D":
                q.append((i, j, 1))
            elif y == "S":
                sheep.append((i, j))

    n = len(a)
    ans = 0
    for i in range(1, 21):
        seen = set()
        visited = set()
        while q:
            r, c, s = q.popleft()
            if (r, c) in visited:
                continue
            visited.add((r, c))
            if s == i + 1:
                q.append((r, c, s))
                break

            for dr, dc in moves:
                rr = r + dr
                cc = c + dc
                if rr < 0 or rr >= n or cc < 0 or cc >= n or (rr, cc) in visited:
                    continue
                q.append((rr, cc, s + 1))
                if a[rr][cc] != "#":
                    seen.add((rr, cc))
        ls = len(sheep)
        for _ in range(ls):
            sr, sc = sheep.popleft()
            if (sr, sc) in seen or (sr + 1, sc) in seen:
                ans += 1
                continue
            sr += 1
            if sr != n:
                sheep.append((sr, sc))
    print(ans)


def part3(a):
    a = a.split("\n")
    sheep = dict()
    sr, sc = -1, -1
    for i, x in enumerate(a):
        for j, y in enumerate(x):
            if y == "D":
                sr, sc = i, j
            elif y == "S":
                sheep[j] = i

    n = len(a)
    m = len(a[0])
    memo = dict()

    def develop(r, c, sp, t):
        if len(sp) == 0:
            return 1
        help = list()
        for x in sorted(sp.keys()):
            help.append((x, sp[x]))
        key = (r, c, frozenset(help), t)
        tot = 0
        if key in memo:
            return memo[key]

        if not t:
            moved = False
            for sc, sr in sp.items():
                if sr + 1 == n:
                    moved = True
                elif (sr + 1, sc) != (r, c) or a[sr + 1][sc] == "#":
                    moved = True
                    nd = copy.deepcopy(sp)
                    nd[sc] = sr + 1
                    tot += develop(r, c, nd, True)

            if not moved:
                tot += develop(r, c, sp, True)

        else:
            for dr, dc in moves:
                rr = r + dr
                cc = c + dc
                ret = False
                if rr < 0 or rr >= n or cc < 0 or cc >= m:
                    continue

                sr = None
                if cc in sp.keys() and sp[cc] == rr and a[rr][cc] != "#":
                    sr = sp.pop(cc)
                tot += develop(rr, cc, sp, False)
                if sr is not None:
                    sp[cc] = sr

        memo[key] = tot
        return tot

    ans = develop(sr, sc, sheep, False)
    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    # part1(G)
    # part2(G)
    part3(G)


if __name__ == "__main__":
    main()
