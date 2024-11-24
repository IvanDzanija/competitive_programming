import sys


def part1(a, r, c):
    ans = 0
    for i, row in enumerate(a):
        for j, ch in enumerate(row):
            if ch == "#":
                ans += 1
                a[i][j] = 1
            else:
                a[i][j] = 0
    pans = 0
    it = 0
    while pans != ans:
        pans = ans
        it += 1
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                curr = a[i][j]
                if curr < it:
                    continue
                c1 = a[i - 1][j] - curr
                c2 = a[i + 1][j] - curr
                c3 = a[i][j + 1] - curr
                c4 = a[i][j - 1] - curr
                if c1 >= 0 and c2 >= 0 and c3 >= 0 and c4 >= 0:
                    a[i][j] += 1
                    ans += 1

    return ans


def part3(a, r, c):
    ans = 0
    for i, row in enumerate(a):
        for j, ch in enumerate(row):
            if ch == "#":
                ans += 1
                a[i][j] = 1
            else:
                a[i][j] = 0
    pans = 0
    it = 0
    while pans != ans:
        pans = ans
        it += 1
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                curr = a[i][j]
                if curr < it:
                    continue
                c1 = a[i - 1][j] - curr
                c2 = a[i + 1][j] - curr
                c3 = a[i][j + 1] - curr
                c4 = a[i][j - 1] - curr
                c5 = a[i - 1][j - 1] - curr
                c6 = a[i + 1][j + 1] - curr
                c7 = a[i - 1][j + 1] - curr
                c8 = a[i + 1][j - 1] - curr
                if (
                    c1 >= 0
                    and c2 >= 0
                    and c3 >= 0
                    and c4 >= 0
                    and c5 >= 0
                    and c6 >= 0
                    and c7 >= 0
                    and c8 >= 0
                ):
                    a[i][j] += 1
                    ans += 1

    return ans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    NG = [["."] * (C + 2)]
    for g in G:
        ng = ["."]
        for ch in g:
            ng.append(ch)
        ng.append(".")
        NG.append(ng)
    NG.append(["."] * (C + 2))
    # print(part1(NG, R, C))
    # part2 is same and part1 just bigger grid
    # print(part3(NG, R, C))
    return 0


if __name__ == "__main__":
    main()
