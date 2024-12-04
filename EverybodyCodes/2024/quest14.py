import sys
from collections import deque


def part1(g):
    ans = 0
    c = 0
    for x in g[0].split(","):
        if x[0] == "U":
            c += int(x[1:])
        elif x[0] == "D":
            c -= int(x[1:])
        ans = max(ans, c)
    return ans


def part2(g):
    ans = set()
    for i in range(len(g)):
        print(g[i])
        print()
        cx = 0
        cy = 0
        cz = 0
        for x in g[i].split(","):
            print(x)
            if x[0] == "U":
                for j in range(int(x[1:])):
                    cy += 1
                    ans.add((cx, cy, cz))
            elif x[0] == "D":
                for j in range(int(x[1:])):
                    cy -= 1
                    ans.add((cx, cy, cz))
            elif x[0] == "R":
                for j in range(int(x[1:])):
                    cx += 1
                    ans.add((cx, cy, cz))
            elif x[0] == "L":
                for j in range(int(x[1:])):
                    cx -= 1
                    ans.add((cx, cy, cz))
            elif x[0] == "F":
                for j in range(int(x[1:])):
                    cz += 1
                    ans.add((cx, cy, cz))
            elif x[0] == "B":
                for j in range(int(x[1:])):
                    cz -= 1
                    ans.add((cx, cy, cz))
    return len(ans)


def part3(g):
    leaves = set()
    main = set()
    paths = set()
    for i in range(len(g)):
        cx = 0
        cy = 0
        cz = 0
        for x in g[i].split(","):
            if x[0] == "U" and cx == 0 and cz == 0:
                for j in range(int(x[1:]) + 1):
                    main.add((cx, cy + j, cz))
            if x[0] == "U":
                for j in range(int(x[1:])):
                    cy += 1
                    paths.add((cx, cy, cz))
            elif x[0] == "D":
                for j in range(int(x[1:])):
                    cy -= 1
                    paths.add((cx, cy, cz))
            elif x[0] == "R":
                for j in range(int(x[1:])):
                    cx += 1
                    paths.add((cx, cy, cz))
            elif x[0] == "L":
                for j in range(int(x[1:])):
                    cx -= 1
                    paths.add((cx, cy, cz))
            elif x[0] == "F":
                for j in range(int(x[1:])):
                    cz += 1
                    paths.add((cx, cy, cz))
            elif x[0] == "B":
                for j in range(int(x[1:])):
                    cz -= 1
                    paths.add((cx, cy, cz))
        leaves.add((cx, cy, cz))
    ans = float("inf")
    for mx, my, mz in main:
        q = deque()
        q.append((mx, my, mz, 0))
        vis = set()
        lvis = []
        while len(q) > 0:
            x, y, z, s = q.popleft()
            if (x, y, z) in vis:
                continue
            if (x, y, z) in leaves:
                lvis.append(s)
                if len(lvis) >= len(leaves):
                    break
            vis.add((x, y, z))
            for dx, dy, dz in [
                (0, 0, 1),
                (0, 0, -1),
                (0, 1, 0),
                (0, -1, 0),
                (1, 0, 0),
                (-1, 0, 0),
            ]:
                xx = x + dx
                yy = y + dy
                zz = z + dz
                if (xx, yy, zz) in paths:
                    q.append((xx, yy, zz, s + 1))

        sm = sum(lvis)
        ans = min(ans, sm)

    return ans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G))
    # print(part2(G))
    print(part3(G))
    return 0


if __name__ == "__main__":
    main()
