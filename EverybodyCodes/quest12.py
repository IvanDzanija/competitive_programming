import sys


def part1(g):
    return 0


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    print(part1(G))
    return 0


if __name__ == "__main__":
    main()
