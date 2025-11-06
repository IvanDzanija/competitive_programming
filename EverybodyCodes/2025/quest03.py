import sys


def part1(a):
    s = sorted(a)
    seen = set()
    ans = 0
    for v in s:
        if v in seen:
            continue

        seen.add(v)
        ans += v
    print(ans)


def part2(a):
    s = sorted(a)
    seen = set()
    ans = 0
    ind = 0
    for v in s:
        if v in seen:
            continue
        if ind == 20:
            break
        seen.add(v)
        ind += 1
        ans += v
    print(ans)


def part3(a):
    s = sorted(a)
    d = {k: 0 for k in s}
    ans = 0
    for v in s:
        d[v] += 1
        ans = max(ans, d[v])
    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    G = list(map(int, G.split(",")))
    part1(G)
    part2(G)
    part3(G)
    return 0


if __name__ == "__main__":
    main()
