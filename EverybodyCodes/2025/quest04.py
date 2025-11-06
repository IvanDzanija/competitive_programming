import sys


def part1(a):
    ans = 0


def part2(a):
    ans = 0


def part3(a):
    ans = 0
    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    G = list(map(int, G.split(",")))
    part1(G)
    part2(G)
    part3(G)


if __name__ == "__main__":
    main()
