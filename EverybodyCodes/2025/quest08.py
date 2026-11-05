import sys


def part1(a):
    a = list(map(int, a.split(",")))
    ans = 0
    for i, x in enumerate(a):
        if i == len(a) - 1:
            break
        if x == a[i + 1] - 16 or x == a[i + 1] + 16:
            ans += 1
    print(ans)


def part2(a):
    a = list(map(int, a.split(",")))
    ans = 0
    r = dict()
    for i, x in enumerate(a):
        if i != len(a) - 1:
            m = a[i + 1]
            if x not in r.keys():
                r[x] = [m]
            else:
                r[x].append(m)
            if m not in r.keys():
                r[m] = [x]
            else:
                r[m].append(x)

            s = min(m, x)
            e = max(x, m)
            for j in range(s + 1, e):
                if j not in r.keys():
                    continue
                for k in r[j]:
                    if k < s or k > e:
                        ans += 1
    print(ans)


def part3(a):
    a = list(map(int, a.split(",")))
    ans = 0
    r = dict()
    for i, x in enumerate(a):
        if i != len(a) - 1:
            m = a[i + 1]
            if x not in r.keys():
                r[x] = [m]
            else:
                r[x].append(m)
            if m not in r.keys():
                r[m] = [x]
            else:
                r[m].append(x)

    for x in range(1, 257):
        for m in range(x, 257):
            curr = 0
            for j in range(x + 1, m):
                if j not in r.keys():
                    continue
                for k in r[j]:
                    if k < x or k > m:
                        curr += 1
            if x in r.keys() and m in r[x]:
                curr += 1
            ans = max(ans, curr)
    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    # part1(G)
    # part2(G)
    # part3(G)


if __name__ == "__main__":
    main()
