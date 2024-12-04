import sys
from queue import PriorityQueue


def part1(g, h, w):
    sr = 0
    sc = 0
    er = 0
    ec = 0
    for i in range(h):
        g[i] = list(g[i])
        for j in range(w):
            if g[i][j] == "S":
                sr = i
                sc = j
                g[i][j] = "0"
            elif g[i][j] == "E":
                er = i
                ec = j
                g[i][j] = "0"
    pq = PriorityQueue()
    pq.put((0, sr, sc))
    vis = set()
    ans = []
    while not pq.empty():
        cw, r, c = pq.get()
        # print(cw, l, r, c)
        if (r, c) in vis or c == "#":
            continue
        if r == er and c == ec:
            ans.append(cw)
        l = int(g[r][c])
        vis.add((r, c))
        g[r][c] = "#"
        if r - 1 >= 0 and g[r - 1][c] != "#":
            nl = int(g[r - 1][c])
            nw = min(abs(l - nl), abs(l + 10 - nl), abs(l - 10 - nl))
            pq.put((cw + nw + 1, r - 1, c))
        if r + 1 < h and g[r + 1][c] != "#":
            nl = int(g[r + 1][c])
            nw = min(abs(l - nl), abs(l + 10 - nl), abs(l - 10 - nl))
            pq.put((cw + nw + 1, r + 1, c))
        if c + 1 < w and g[r][c + 1] != "#":
            nl = int(g[r][c + 1])
            nw = min(abs(l - nl), abs(l + 10 - nl), abs(l - 10 - nl))
            pq.put((cw + nw + 1, r, c + 1))
        if c - 1 >= 0 and g[r][c - 1] != "#":
            nl = int(g[r][c - 1])
            nw = min(abs(l - nl), abs(l + 10 - nl), abs(l - 10 - nl))
            pq.put((cw + nw + 1, r, c - 1))

    return max(ans)


def part3(g, h, w):
    sr = 0
    sc = 0
    ends = set()
    for i in range(h):
        g[i] = list(g[i])
        for j in range(w):
            if g[i][j] == "S":
                ends.add((i, j))
                g[i][j] = "0"
            elif g[i][j] == "E":
                sr = i
                sc = j
                g[i][j] = "0"
    pq = PriorityQueue()
    pq.put((0, sr, sc))
    vis = set()
    while not pq.empty():
        cw, r, c = pq.get()
        # print(cw, l, r, c)
        if (r, c) in vis or c == "#":
            continue
        if (r, c) in ends:
            return cw
        l = int(g[r][c])
        vis.add((r, c))
        g[r][c] = "#"
        if r - 1 >= 0 and g[r - 1][c] != "#":
            nl = int(g[r - 1][c])
            nw = min(abs(l - nl), abs(l + 10 - nl), abs(l - 10 - nl))
            pq.put((cw + nw + 1, r - 1, c))
        if r + 1 < h and g[r + 1][c] != "#":
            nl = int(g[r + 1][c])
            nw = min(abs(l - nl), abs(l + 10 - nl), abs(l - 10 - nl))
            pq.put((cw + nw + 1, r + 1, c))
        if c + 1 < w and g[r][c + 1] != "#":
            nl = int(g[r][c + 1])
            nw = min(abs(l - nl), abs(l + 10 - nl), abs(l - 10 - nl))
            pq.put((cw + nw + 1, r, c + 1))
        if c - 1 >= 0 and g[r][c - 1] != "#":
            nl = int(g[r][c - 1])
            nw = min(abs(l - nl), abs(l + 10 - nl), abs(l - 10 - nl))
            pq.put((cw + nw + 1, r, c - 1))

    return 0


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G, R, C))
    # part2 is the same as part1 just bigger gri
    print(part3(G, R, C))
    return 0


if __name__ == "__main__":
    main()
