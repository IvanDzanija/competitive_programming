import sys
from copy import deepcopy


def part1(g):
    seq = list(g[0])
    for i in range(2, len(g)):
        g[i] = list(g[i])
    g = g[2:]
    R = len(g)
    C = len(g[0])
    iter = 0
    rotation = [
        [-1, -1],
        [-1, 0],
        [-1, 1],
        [0, 1],
        [1, 1],
        [1, 0],
        [1, -1],
        [0, -1],
    ]
    for r in range(1, R - 1):
        for c in range(1, C - 1):
            curr = seq[iter % len(seq)]
            iter += 1
            pos = deepcopy(rotation)
            if curr == "L":
                pos = pos[::-1]
            for i in range(8):
                pos[i][0] += r
                pos[i][1] += c
            temp = g[pos[7][0]][pos[7][1]]
            for i in range(7, 0, -1):
                r1, c1 = pos[i]
                r2, c2 = pos[i - 1]
                g[r1][c1] = g[r2][c2]
            g[pos[0][0]][pos[0][1]] = temp
    ans = ""
    start = False
    for x in g:
        for y in x:
            if y == ">":
                start = True
            elif y == "<":
                start = False
                break
            elif start:
                ans += y
    return ans


def part2(g):
    seq = list(g[0])
    for i in range(2, len(g)):
        g[i] = list(g[i])
    g = g[2:]
    R = len(g)
    C = len(g[0])
    rotation = [
        [-1, -1],
        [-1, 0],
        [-1, 1],
        [0, 1],
        [1, 1],
        [1, 0],
        [1, -1],
        [0, -1],
    ]
    for _ in range(100):
        iter = 0
        for r in range(1, R - 1):
            for c in range(1, C - 1):
                curr = seq[iter % len(seq)]
                iter += 1
                pos = deepcopy(rotation)
                if curr == "L":
                    pos = pos[::-1]
                for i in range(8):
                    pos[i][0] += r
                    pos[i][1] += c
                temp = g[pos[7][0]][pos[7][1]]
                for i in range(7, 0, -1):
                    r1, c1 = pos[i]
                    r2, c2 = pos[i - 1]
                    g[r1][c1] = g[r2][c2]
                g[pos[0][0]][pos[0][1]] = temp
    ans = ""
    start = False
    # for x in g:
    #     print(x)
    for x in g:
        for y in x:
            if y == ">":
                start = True
            elif y == "<":
                start = False
                break
            elif start:
                ans += y
    return ans


def part3(g):
    seq = list(g[0])
    for i in range(2, len(g)):
        g[i] = list(g[i])
    g = g[2:]
    R = len(g)
    C = len(g[0])
    rotation = [[-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1]]
    grid = deepcopy(g)
    g = []
    for i in range(len(grid)):
        tmp = []
        for j in range(len(grid[0])):
            tmp.append((i, j))
        g.append(tmp)

    def mul(p1, p2):


    def exp(perm, left):
        if left == 1:
            return perm
        if left & 1:
            return mul(perm, exp(perm, left - 1))
        else:
            return exp(mul(perm, perm), left // 2)

    steps = 1048576000
    iter = 0
    for r in range(1, R - 1):
        for c in range(1, C - 1):
            curr = seq[iter % len(seq)]
            iter += 1
            pos = deepcopy(rotation)
            if curr == "L":
                pos = pos[::-1]
            for i in range(8):
                pos[i][0] += r
                pos[i][1] += c
            print(pos)
            temp = g[pos[7][0]][pos[7][1]]
            for i in range(7, 0, -1):
                r1, c1 = pos[i]
                r2, c2 = pos[i - 1]
                g[r1][c1] = g[r2][c2]
            g[pos[0][0]][pos[0][1]] = temp
    for x in g:
        print(x)
    ans = ""
    start = False
    # for x in g:
    #     print(x)
    for x in g:
        for y in x:
            if y == ">":
                start = True
            elif y == "<":
                start = False
                break
            elif start:
                ans += y
    return ans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    # print(part1(G))
    # print(part2(G))
    print(part3(G))
    return 0


if __name__ == "__main__":
    main()
