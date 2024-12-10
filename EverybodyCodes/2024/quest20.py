import sys
from collections import deque

sys.setrecursionlimit(10**6)


def part1(g, R, C):
    ans = 0
    sr = 0
    sc = 0
    for i in range(R):
        for j in range(C):
            if g[i][j] == "S":
                sr = i
                sc = j
    ans = 0
    seen = set()
    q = deque()
    q.append((0, 1000, sr, sc, 0))
    while q:
        [time, alt, r, c, prev] = q.popleft()
        key = (r, c, prev, alt)
        if key in seen:
            continue
        seen.add(key)
        if time == 100:
            ans = max(ans, alt)
            continue
        if r < 0 or r >= R or g[r][c] == "#":
            continue
        time += 1
        if g[r][c] == ".":
            alt -= 1
        elif g[r][c] == "-":
            alt -= 2
        else:
            alt += 1
        if prev == 0:
            q.append((time, alt, r + 1, c, 0))
            q.append((time, alt, r, c + 1, 1))
            q.append((time, alt, r, c - 1, 2))
        elif prev == 1:
            q.append((time, alt, r + 1, c, 0))
            q.append((time, alt, r - 1, c, 3))
            q.append((time, alt, r, c + 1, 1))
        elif prev == 2:
            q.append((time, alt, r + 1, c, 0))
            q.append((time, alt, r - 1, c, 3))
            q.append((time, alt, r, c - 1, 2))
        else:
            q.append((time, alt, r - 1, c, 3))
            q.append((time, alt, r, c + 1, 1))
            q.append((time, alt, r, c - 1, 2))

    return ans


def part2(g, R, C):
    ans = 10000000000000
    sr = 0
    sc = 0
    for i in range(R):
        for j in range(C):
            if g[i][j] == "S":
                sr = i
                sc = j
    seen = dict()
    q = deque()
    q.append((0, 10000, sr, sc, 0, frozenset()))

    while q:
        [time, alt, r, c, prev, coll] = q.popleft()
        key = (r, c, prev, coll)

        # print()
        if time > ans:
            continue
        if key in seen:
            if seen[key] >= alt:
                continue
        seen[key] = alt
        if g[r][c] == "S" and len(coll) == 3 and alt >= 10000:
            ans = min(ans, time)
            continue
        if g[r][c] == "#" or (g[r][c] == "S" and time != 0):
            continue
        if g[r][c] == "B" and len(coll) != 1:
            continue
        if g[r][c] == "C" and len(coll) != 2:
            continue
        time += 1
        collected = set(coll)
        if g[r][c] in ["A", "B", "C"]:
            collected.add(g[r][c])
            alt -= 1
        elif g[r][c] == "-":
            alt -= 2
        elif g[r][c] == "+":
            alt += 1
        else:
            alt -= 1
        # print(time, alt, collected, r, c)
        if prev == 0:
            q.append((time, alt, r + 1, c, 0, frozenset(collected)))
            q.append((time, alt, r, c + 1, 1, frozenset(collected)))
            q.append((time, alt, r, c - 1, 2, frozenset(collected)))
        elif prev == 1:
            q.append((time, alt, r + 1, c, 0, frozenset(collected)))
            q.append((time, alt, r - 1, c, 3, frozenset(collected)))
            q.append((time, alt, r, c + 1, 1, frozenset(collected)))
        elif prev == 2:
            q.append((time, alt, r + 1, c, 0, frozenset(collected)))
            q.append((time, alt, r - 1, c, 3, frozenset(collected)))
            q.append((time, alt, r, c - 1, 2, frozenset(collected)))
        else:
            q.append((time, alt, r - 1, c, 3, frozenset(collected)))
            q.append((time, alt, r, c + 1, 1, frozenset(collected)))
            q.append((time, alt, r, c - 1, 2, frozenset(collected)))

    return ans


# exploits the input
def part3(g, R, C):
    alt = 384400
    sr = 0
    sc = 0
    for i in range(R):
        for j in range(C):
            if g[i][j] == "S":
                sr = i
                sc = j
    sr += 1
    sc += 2
    alt -= 1

    while alt > 0:
        sr += 1
        r = sr % R
        if (g[r][sc]) == ".":
            alt -= 1
        if g[r][sc] == "+":
            alt += 1

    return sr


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G, R, C))
    # print(part2(G, R, C))
    # print(part3(G, R, C))
    return 0


if __name__ == "__main__":
    main()
