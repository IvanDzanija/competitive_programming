import sys
import numpy as np


def part1(g):
    ans = 0
    m = min(g)
    for x in g:
        ans += x - m
    return ans


def part3(g):
    ans = 0
    ng = np.array(g)
    med = np.median(ng)
    for x in g:
        ans += abs(med - x)
    return int(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    G = list(map(int, G))
    # print(part1(G))
    # part2 is the same as part1 just bigger input
    print(part3(G))
    return 0


if __name__ == "__main__":
    main()
