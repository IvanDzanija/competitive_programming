import sys
import math


def csum(a):
    ans = 0
    for i, x in enumerate(a):
        ans += (i + 1) * x
    return ans


def part1(a):
    a = list(map(int, a.split("\n")))

    corr = sum(a) / len(a)
    ans = 0
    rnd = 0


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    part1(G)
    # part2(G)
    # part3(G)


if __name__ == "__main__":
    main()
