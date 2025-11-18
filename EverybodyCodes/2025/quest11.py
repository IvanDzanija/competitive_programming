import sys


def csum(a):
    ans = 0
    for i, x in enumerate(a):
        ans += (i + 1) * x
    return ans


def part1(a):
    a = list(map(int, a.split("\n")))

    rnd = 0
    while True:
        flag = False
        for i, l in enumerate(a):
            if i == len(a) - 1:
                continue
            r = a[i + 1]
            if l > r:
                flag = True
                a[i] -= 1
                a[i + 1] += 1
        if not flag:
            break
        rnd += 1
        if rnd == 10:
            break
    if rnd == 10:
        print(csum(a))
        return

    while True:
        flag = False
        for i, l in enumerate(a):
            if i == len(a) - 1:
                continue
            r = a[i + 1]
            if r > l:
                flag = True
                a[i] += 1
                a[i + 1] -= 1
        if not flag:
            break
        rnd += 1
        if rnd == 10:
            break
    print(csum(a))


def part2(a):
    a = list(map(int, a.split("\n")))

    rnd = 0
    while True:
        flag = False
        for i, l in enumerate(a):
            if i == len(a) - 1:
                continue
            r = a[i + 1]
            if l > r:
                flag = True
                a[i] -= 1
                a[i + 1] += 1
        if not flag:
            break
        rnd += 1

    while True:
        flag = False
        for i, l in enumerate(a):
            if i == len(a) - 1:
                continue
            r = a[i + 1]
            if r > l:
                flag = True
                a[i] += 1
                a[i + 1] -= 1
        if not flag:
            break
        rnd += 1
    print(rnd)


def part3(a):
    a = list(map(int, a.split("\n")))
    corr = sum(a) / len(a)
    print(corr)
    ans = 0

    for x in a:
        if x < corr:
            ans += corr - x
        else:
            break
    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    # part1(G)
    # part2(G)
    # part3(G)


if __name__ == "__main__":
    main()
