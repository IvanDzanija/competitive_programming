import sys


def part1(a):
    a = int(a)
    ps = 0
    for i in range(1, (a // 2) + 2, 2):
        ps += i
        if ps > a:
            return (ps - a) * i
        elif ps == a:
            return 0


def part2(a):
    a = int(a)
    div = 1111
    block = 20240000
    ts = 1
    tw = 1
    pt = 1
    while ts < block:
        nt = (pt * a) % div
        pt = nt
        tw += 2
        ts += tw * nt
        print(ts, tw, nt)
    return (ts - block) * tw


def part3(a):
    a = int(a)
    div = 10
    block = 202400000
    ts = 1
    tw = 1
    th = 1
    pt = 1
    height = [1]
    fans = 0
    while fans >= 0:
        nt = (pt * a) % div + div
        pt = nt
        tw += 2
        ts += tw * nt
        for i in range(len(height)):
            height[i] += nt
        height.append(nt)
        ans = 0
        for i in range(len(height) - 1):
            curr = (a * tw * height[i]) % div
            if i > 0:
                ans += 2 * height[i]
                ans -= 2 * curr
            else:
                ans += height[i]
                ans -= curr
        fans = block - (ans + 2 * height[len(height) - 1])

    return -fans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    # print(part1(G))
    # print(part2(G))
    print(part3(G))
    return 0


if __name__ == "__main__":
    main()
