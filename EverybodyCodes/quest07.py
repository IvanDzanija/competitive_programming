import sys


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


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    NG = open("B.in").read().strip().split("\n")
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G))
    print(part2(G, NG))
    return 0


if __name__ == "__main__":
    main()
