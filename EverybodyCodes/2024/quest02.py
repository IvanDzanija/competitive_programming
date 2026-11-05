import sys


def part1(a, b):
    ans = 0
    for c in a:
        for w in b:
            if c in w:
                ans += 1
    return ans


def part2(a, b):
    ans = 0
    r = set()
    for ar in a:
        r.add(ar)
    for si in a:
        r.add(si[::-1])
    for l in b:
        for w in l.split(" "):
            s = set()
            for z in r:
                pos1 = w.find(z)
                while pos1 != -1:
                    for i in range(len(z)):
                        s.add(pos1 + i)
                    pos1 = w.find(z, pos1 + 1)
            ans += len(s)
    return ans


def part3(a, b):
    ans = 0
    r = set()
    for ar in a:
        r.add(ar)
    for si in a:
        r.add(si[::-1])
    rmod = len(b[0])
    cmod = len(b)
    pos = set()
    for i, l in enumerate(b):
        l += l
        for z in r:
            pos1 = l.find(z)
            while pos1 != -1:
                for j in range(len(z)):
                    pos.add((i, (pos1 + j) % rmod))
                pos1 = l.find(z, pos1 + 1)
    for i in range(len(b[0])):
        l = ""
        for j in range(len(b)):
            l += b[j][i]
        for z in r:
            pos1 = l.find(z)
            while pos1 != -1:
                for k in range(len(z)):
                    pos.add(((pos1 + k) % cmod, i))
                pos1 = l.find(z, pos1 + 1)
    ans = len(pos)
    return ans


def main():
    input = sys.stdin.read()
    a = input.splitlines()
    # print(part1(a[0].split(','),a[1].split(' ')))
    # print(part2(a[0].split(","), a[1:]))
    # print(part3(a[0].split(","), a[1:]))
    return 0


if __name__ == "__main__":
    main()
