import sys


def part1(a):
    ans = 0
    r = dict()
    for x in a:
        if x == "a" or x == "A":
            if x.isupper():
                if x in r.keys():
                    r[x] += 1
                else:
                    r[x] = 1
            else:
                ans += r[x.upper()]
    print(ans)


def part2(a):
    ans = 0
    r = dict()
    for x in a:
        if x.isupper():
            if x in r.keys():
                r[x] += 1
            else:
                r[x] = 1
        else:
            ans += r[x.upper()]
    print(ans)


def part3(a):
    a = a * 1000
    ans = 0
    r = dict()
    ir = dict()
    rr = dict()
    irr = dict()
    for i, x in enumerate(a):
        if x.isupper():
            if x not in r.keys():
                r[x] = list()
            r[x].append(i)

            m = x.lower()
            if m not in rr.keys():
                continue
            if m in irr.keys() and irr[m]:
                ind = irr[m]
            else:
                ind = 0
            while rr[m][ind] < i - 1000:
                ind += 1
            irr[m] = ind
            ans += len(rr[m]) - ind

        else:
            if x not in rr.keys():
                rr[x] = list()
            rr[x].append(i)

            m = x.upper()
            if m not in r.keys():
                continue
            if m in ir.keys() and ir[m]:
                ind = ir[m]
            else:
                ind = 0
            while r[m][ind] < i - 1000:
                ind += 1
            ir[m] = ind
            ans += len(r[m]) - ind
    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    # part1(G)
    # part2(G)
    # part3(G)


if __name__ == "__main__":
    main()
