import sys
from collections import deque
from copy import deepcopy


def part1(g, R, C):
    q = deque()
    sr = 0
    sc = 0
    for j in range(C):
        if g[0][j] == ".":
            sc = j
    q.append((sr, sc, 0))
    vis = set()
    ans = 2
    while len(q) > 0:
        r, c, w = q.popleft()
        if g[r][c] == "H":
            ans *= w
            break
        if (r, c) in vis:
            continue
        vis.add((r, c))
        for dr, dc in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            rr = r + dr
            cc = c + dc
            if 0 <= rr < R and 0 <= cc < C and g[rr][cc] != "#":
                q.append((rr, cc, w + 1))
    return ans


def part2(g, R, C):
    q = deque()
    sr = 0
    sc = 0
    ans = 0
    targ = set()
    for i in range(R):
        for j in range(C):
            curr = g[i][j]
            if curr == "." and i == 0:
                sc = j
                continue
            if curr != "#" and curr != "." and curr != "~" and curr not in targ:
                targ.add(curr)
    masks = dict()
    ind = 0
    total = 0
    for x in targ:
        masks[x] = ind
        total |= 1 << ind
        ind += 1

    q.append((sr, sc, 0, 0))
    visited = [False for _ in range(R * C * (total + 1))]
    while len(q) > 0:
        r, c, w, items = q.popleft()
        k = items * R * C + r * C + c
        if visited[k]:
            continue
        visited[k] = True

        if r == sr and c == sc and items == total:
            ans = w
            break
        for dr, dc in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            rr = r + dr
            cc = c + dc
            if 0 <= rr < R and 0 <= cc < C and g[rr][cc] != "#" and g[rr][cc] != "~":
                if g[rr][cc] != ".":
                    newItems = items | (1 << masks[g[rr][cc]])
                    q.append((rr, cc, w + 1, newItems))
                else:
                    q.append((rr, cc, w + 1, items))

    return ans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G, R, C))
    print(part2(G, R, C))
    # part3 is the same as part2 just way bigger grid
    # runs for 20 minutes :)
    return 0


if __name__ == "__main__":
    main()
