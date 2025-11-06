import sys


def part1(a):
    ans = 2025
    prev = a[0]
    for i in range(1, len(a)):
        curr = prev / a[i]
        prev = a[i]
        ans *= curr
    print(ans)


def part2(a):
    ans = 1
    c = 10000000000000
    prev = a[0]
    for i in range(1, len(a)):
        curr = prev / a[i]
        prev = a[i]
        ans *= curr
    print(c / ans)


def part3(a):
    ans = 100
    prev = int(a[0])
    for i in range(1, len(a)):
        d = list(map(int, a[i].split("|")))
        if len(d) == 1:
            ans = ans * prev / int(a[i])
        else:
            ans = ans * prev / d[0]
            prev = d[1]

    print(int(ans))


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    # G = list(map(int, G.split("\n")))
    # G = G.split("\n")
    # part1(G)
    # part2(G)
    # part3(G)


if __name__ == "__main__":
    main()
