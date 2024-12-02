import sys
from collections import deque


def part1(g, height, width):
    sr = 1
    sc = 0
    q = deque()
    q.append((sr, sc, 0))
    vis = set()
    ans = 0
    while len(q) > 0:
        r, c, w = q.popleft()
        if (r, c) in vis:
            continue
        if g[r][c] == "P":
            ans = max(ans, w)
        vis.add((r, c))
        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            rr = r + dr
            cc = c + dc
            if 0 <= rr < height and 0 <= cc < width and g[rr][cc] != "#":
                q.append((rr, cc, w + 1))

    return ans


def part2(g, height, width):
    q = deque()
    q.append((1, 0, 0))
    vis = set()
    ans = dict()
    while len(q) > 0:
        r, c, w = q.popleft()
        if (r, c) in vis:
            continue
        if g[r][c] == "P":
            ans[(r, c)] = w
        vis.add((r, c))
        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            rr = r + dr
            cc = c + dc
            if 0 <= rr < height and 0 <= cc < width and g[rr][cc] != "#":
                q.append((rr, cc, w + 1))
    q.append((69, 200, 0))
    vis = set()
    while len(q) > 0:
        r, c, w = q.popleft()
        print(g[r][c])
        if (r, c) in vis:
            continue
        if g[r][c] == "P":
            if w < ans[(r, c)]:
                ans[(r, c)] = w
        vis.add((r, c))
        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            rr = r + dr
            cc = c + dc
            if 0 <= rr < height and 0 <= cc < width and g[rr][cc] != "#":
                q.append((rr, cc, w + 1))
    return max(ans.values())


# slow... takes 40sec
def part3(g, height, width):
    ans = float("inf")
    for i in range(height):
        for j in range(width):
            if (g[i][j]) == ".":
                q = deque()
                q.append((i, j, 0))
                vis = set()
                csum = 0
                b = False
                while len(q) > 0:
                    r, c, w = q.popleft()
                    if w >= ans:
                        b = True
                        break
                    if (r, c) in vis:
                        continue
                    if g[r][c] == "P":
                        csum += w
                    vis.add((r, c))
                    for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                        rr = r + dr
                        cc = c + dc
                        if 0 <= rr < height and 0 <= cc < width and g[rr][cc] != "#":
                            q.append((rr, cc, w + 1))
                if not b:
                    ans = min(ans, csum)
    return ans


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
