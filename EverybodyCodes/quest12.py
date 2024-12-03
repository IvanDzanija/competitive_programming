import sys


def part1(g, R, C):
    targets = set()
    shooters = []
    for i in range(len(g)):
        g[i] = list(g[i])
        for j in range(len(g[i])):
            if g[i][j] == "T":
                targets.add((i, j))
            elif g[i][j] == "A":
                shooters.append((i, j))
            elif g[i][j] == "B":
                shooters.append((i, j))
            elif g[i][j] == "C":
                shooters.append((i, j))
    pow = 1
    ans = 0
    while len(targets) > 0:
        for i in range(len(shooters)):
            r = shooters[i][0]
            c = shooters[i][1]
            print(r, c)
            left = pow
            while left > 0:
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow
                r -= 1
                c += 1
                left -= 1

            left = pow
            while left > 0:
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow
                c += 1
                left -= 1
            if r < 0:
                c += -r
                r = 0
            while c < C and g[r][c] != "=":
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow
                r += 1
                c += 1
        pow += 1

    return ans


def part2(g, R, C):
    targets = set()
    values = dict()
    shooters = []
    for i in range(len(g)):
        g[i] = list(g[i])
        for j in range(len(g[i])):
            if g[i][j] == "T":
                targets.add((i, j))
                values[(i, j)] = 1
            elif g[i][j] == "H":
                targets.add((i, j))
                values[(i, j)] = 2
            elif g[i][j] == "A":
                shooters.append((i, j))
            elif g[i][j] == "B":
                shooters.append((i, j))
            elif g[i][j] == "C":
                shooters.append((i, j))
    pow = 1
    ans = 0
    while len(targets) > 0:
        for i in range(len(shooters)):
            r = shooters[i][0]
            c = shooters[i][1]
            left = pow
            while left > 0:
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow * values[(r, c)]
                r -= 1
                c += 1
                left -= 1

            left = pow
            while left > 0:
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow * values[(r, c)]
                c += 1
                left -= 1
            if r < 0:
                c += -r
                r = 0
            while c < C and g[r][c] != "=":
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow * values[(r, c)]
                r += 1
                c += 1
        pow += 1

    return ans


# implementation of algebraic solution: https://github.com/mmdoogie/everybody-codes/blob/main/ec_2024/ec_2024_12.py
def part3(g):
    ans = 0
    shooters = [(0, 0), (0, 1), (0, 2)]
    targets = []
    for x in g:
        print(x)

    def power(shooter, target):
        dx = target[0] - shooter[0]
        dy = target[1] - shooter[1]
        if dx == dy:
            return int(dx) * (1 + shooter[1])

    return ans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G, R, C))
    # print(part2(G, R, C))
    print(part3(G))
    return 0


if __name__ == "__main__":
    main()
