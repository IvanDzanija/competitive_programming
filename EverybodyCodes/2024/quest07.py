import sys
import itertools


def part1(g):
    ans = []
    for x in g:
        f = x.split(":")[0]
        s = x.split(":")[1]
        s = s.split(",")
        j = 0
        while len(s) < 10:
            s.append(s[j])
            j += 1
        c = 10
        ca = 0
        for y in s:
            if y == "+":
                c += 1
            elif y == "-":
                c -= 1
                if c < 0:
                    c = 0
            ca += c
        ans.append((ca, f))
    ans.sort(reverse=True)
    nans = ""
    for x in ans:
        nans += x[1]
    return nans


def part2(g, ng):
    gg = []
    for i in range(1, len(ng[0])):
        gg.append(ng[0][i])
    for i in range(1, len(ng) - 1):
        gg.append(ng[i][len(ng[0]) - 1])
    for x in ng[len(ng) - 1][::-1]:
        gg.append(x)
    for i in range(1, len(ng) - 1):
        gg.append(ng[i][0])
    gg.append("=")
    ans = []
    for x in g:
        f = x.split(":")[0]
        s = x.split(":")[1]
        s = s.split(",")
        c = 10
        ca = 0
        i = 0
        for k in range(10):
            for y in gg:
                if y == "+":
                    c += 1
                elif y == "-":
                    c -= 1
                    if c < 0:
                        c = 0
                elif s[i] == "+":
                    c += 1
                elif s[i] == "-":
                    c -= 1
                    if c < 0:
                        c = 0
                else:
                    assert y == "=" and s[i] == "="
                ca += c
                i += 1
                i %= len(s)
        ans.append((ca, f))
    ans.sort(reverse=True)
    print(ans)
    nans = ""
    for x in ans:
        nans += x[1]
    return nans


def part3(g, ng):
    ans = 0
    perms = set(itertools.permutations("+++++---==="))
    gg = []
    w = len(ng[0])
    h = len(ng)
    clen = w * h
    for i in range(len(ng)):
        if len(ng[i]) < w:
            ng[i] += " " * (w - (len(ng[i])))
    dir = 0
    r = 0
    c = 1
    while ng[r][c] != "S":
        gg.append(ng[r][c])
        # print(len(gg), clen)
        # print(gg)
        if dir == 0:
            if c + 1 < w and ng[r][c + 1] != " ":
                c += 1
            else:
                if r + 1 < h and ng[r + 1][c] != " ":
                    r += 1
                    dir = 1
                elif r - 1 >= 0 and ng[r - 1][c] != " ":
                    r -= 1
                    dir = 2
        elif dir == 1:
            # print(r + 1)
            if r + 1 < h and ng[r + 1][c] != " ":
                r += 1
            else:
                if c + 1 < w and ng[r][c + 1] != " ":
                    c += 1
                    dir = 0
                elif c - 1 >= 0 and ng[r][c - 1] != " ":
                    c -= 1
                    dir = 3
        elif dir == 2:
            if r - 1 >= 0 and ng[r - 1][c] != " ":
                r -= 1
            else:
                if c + 1 < w and ng[r][c + 1] != " ":
                    c += 1
                    dir = 0
                elif c - 1 >= 0 and ng[r][c - 1] != " ":
                    c -= 1
                    dir = 3
        elif dir == 3:
            if c - 1 >= 0 and ng[r][c - 1] != " ":
                c -= 1
            else:
                if r + 1 < h and ng[r + 1][c] != " ":
                    r += 1
                    dir = 1
                elif r - 1 >= 0 and ng[r - 1][c] != " ":
                    r -= 1
                    dir = 2
    # print(gg)
    gg.append("=")
    ca = 0
    s = g[0].split(":")[1]
    s = s.split(",")
    i = 0
    c = 10
    for k in range(2024):
        for y in gg:
            if y == "+":
                c += 1
            elif y == "-":
                c -= 1
                if c < 0:
                    c = 0
            elif s[i] == "+":
                c += 1
            elif s[i] == "-":
                c -= 1
                if c < 0:
                    c = 0
            else:
                assert y == "=" and s[i] == "="
            ca += c
            i += 1
            i %= len(s)
    print(ca)
    for x in perms:
        ccurr = 0
        c = 10
        for k in range(2024):
            for y in gg:
                if y == "+":
                    c += 1
                elif y == "-":
                    c -= 1
                    if c < 0:
                        c = 0
                elif x[i] == "+":
                    c += 1
                elif x[i] == "-":
                    c -= 1
                    if c < 0:
                        c = 0
                else:
                    assert y == "=" and x[i] == "="
                ccurr += c
                i += 1
                i %= len(x)
        if ca < ccurr:
            ans += 1
    return ans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    NG = open("B.in").read().strip().split("\n")
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G))
    # print(part2(G, NG))
    print(part3(G, NG))

    return 0


if __name__ == "__main__":
    main()
