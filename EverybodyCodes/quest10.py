import sys


def transpose(g):
    gg = []
    for j in range(len(g[0])):
        ir = ""
        for i in range(len(g)):
            ir += g[i][j]
        gg.append(ir)
    # print(gg)
    return gg


def part1(g):
    ans = ""
    gg = transpose(g)
    for i in range(2, 6):
        for j in range(2, 6):
            cr = g[i]
            cc = gg[j]
            cr = cr.replace(".", "")
            cc = cc.replace(".", "")
            # print(cr, cc)
            for x in cr:
                if x in cc:
                    ans += x
    return ans


def part2(g):
    ans = 0
    dict = {
        "A": 1,
        "B": 2,
        "C": 3,
        "D": 4,
        "E": 5,
        "F": 6,
        "G": 7,
        "H": 8,
        "I": 9,
        "J": 10,
        "K": 11,
        "L": 12,
        "M": 13,
        "N": 14,
        "O": 15,
        "P": 16,
        "Q": 17,
        "R": 18,
        "S": 19,
        "T": 20,
        "U": 21,
        "V": 22,
        "W": 23,
        "X": 24,
        "Y": 25,
        "Z": 26,
    }
    h = len(g)
    # print(h)
    w = len(g[0])
    cr = 0
    cc = 0
    while cr < h:
        while cc < w:
            curr = []
            for i in range(8):
                cl = g[cr + i][cc : cc + 8]
                curr.append(cl)
            cc += 9
            # print(curr)
            cnt = part1(curr)
            for i, x in enumerate(cnt):
                ans += (i + 1) * dict[x]
        cr += 9
        cc = 0
    return ans


# ugliest code ever
def p3Help(g):
    ans = ""
    ng = []
    ng.append(list(g[0]))
    ng.append(list(g[1]))
    gg = transpose(g)
    # print(g)
    for i in range(2, 6):
        temp = list(g[i])
        for j in range(2, 6):
            cr = g[i]
            cc = gg[j]
            f = False
            for x in cr:
                if x == ".":
                    continue
                if x in cc:
                    temp[j] = x
                    f = True
            if not f:
                temp[j] = "?"
        ng.append(temp)
    ng.append(list(g[6]))
    ng.append(list(g[7]))
    ngg = transpose(ng)
    for i in range(2, len(ng) - 2):
        cr = ng[i]
        for j in range(2, len(ng[0]) - 2):
            cc = list(ngg[j])
            curr = {}
            if ng[i][j] == "?":
                for x in cr:
                    if x in curr:
                        curr[x] += 1
                    else:
                        curr[x] = 1
                for x in cc:
                    if x in curr:
                        curr[x] += 1
                    else:
                        curr[x] = 1
            count = 0
            poss = ""
            for x in curr:
                if curr[x] == 1:
                    count += 1
                    poss = x
            if count == 1:
                ng[i][j] = poss
                for k in range(8):
                    if (ng[k][j]) == "?":
                        ng[k][j] = poss
                for k in range(8):
                    if ng[i][k] == "?":
                        ng[i][k] = poss
    for i in range(2, 6):
        for j in range(2, 6):
            if ng[i][j] != "?":
                ans += ng[i][j]
    return ans, ng


# continuation of ugly code
def part3(rg):
    ans = 0
    g = []
    for i, val in enumerate(rg):
        g.append(list(val))
    dict = {
        "A": 1,
        "B": 2,
        "C": 3,
        "D": 4,
        "E": 5,
        "F": 6,
        "G": 7,
        "H": 8,
        "I": 9,
        "J": 10,
        "K": 11,
        "L": 12,
        "M": 13,
        "N": 14,
        "O": 15,
        "P": 16,
        "Q": 17,
        "R": 18,
        "S": 19,
        "T": 20,
        "U": 21,
        "V": 22,
        "W": 23,
        "X": 24,
        "Y": 25,
        "Z": 26,
    }
    h = len(g)
    # print(h)
    w = len(g[0])
    psolve = -1
    nsolve = 0
    solved = set()
    while nsolve != psolve:
        solvInd = 0
        psolve = nsolve
        cr = 0
        cc = 0
        while cr + 2 < h:
            while cc + 2 < w:
                solvInd += 1
                curr = []
                for i in range(8):
                    cl = g[cr + i][cc : cc + 8]
                    curr.append(cl)
                cnt, grid = p3Help(curr)
                if len(cnt) != 16 or solvInd in solved:
                    cc += 6
                    continue
                if solvInd not in solved:
                    nsolve += 1
                    solved.add(solvInd)
                for i in range(8):
                    for j in range(8):
                        RR = i + cr
                        CC = j + cc
                        if g[RR][CC] == "?":
                            g[RR][CC] = grid[i][j]
                for tile in grid:
                    print(tile)
                for i in range(8):
                    test = ""
                    for j in range(8):
                        RR = i + cr
                        CC = j + cc
                        test += g[RR][CC]
                    print(test)

                for i, x in enumerate(cnt):
                    ans += (i + 1) * dict[x]
                cc += 6
            cr += 6
            cc = 0

    return ans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G))
    # print(part2(G))
    # print(part3(G))
    return 0


if __name__ == "__main__":
    main()
