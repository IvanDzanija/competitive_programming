import sys


def part1(n, m):
    p = 0
    for i in range(len(m)):
        w, s = m[i][0], m[i][1:]
        if w == "L":
            p -= int(s)
            p = max(0, p)
        else:
            p += int(s)
            p = min(p, len(n) - 1)
    print(n[p])


def part2(n, m):
    p = 0
    for i in range(len(m)):
        w, s = m[i][0], m[i][1:]
        if w == "L":
            p -= int(s)
            p += len(n)
            p %= len(n)
        else:
            p += int(s)
            p %= len(n)
    print(n[p])


def part3(n, m):
    p = 0
    for i in range(len(m)):
        w, s = m[i][0], m[i][1:]
        if w == "L":
            p = -(int(s) % len(n))
            n[0], n[p] = n[p], n[0]
        else:
            p = int(s) % len(n)
            n[0], n[p] = n[p], n[0]
    print(n[0])


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    n, m = G[0].split(","), G[2].split(",")
    part1(n, m)
    part2(n, m)
    part3(n, m)
    return 0


if __name__ == "__main__":
    main()
