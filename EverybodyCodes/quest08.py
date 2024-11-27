import sys


def part1(a):
    a = int(a)
    ps = 0
    for i in range(1, (a // 2) + 2, 2):
        ps += i
        if ps > a:
            return (ps - a) * i
        elif ps == a:
            return 0


def part2(a):
    a = int(a)
    div = 1111
    block = 20240000
    ts = 1
    tw = 1
    th = 1
    pt = 1
    while ts < block:
        nt = (pt * a) % div
        pt = nt
        tw += 2
        ts += tw * nt
    return (ts - block) * tw


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    # print(part1(G))
    print(part2(G))
    return 0


if __name__ == "__main__":
    main()
