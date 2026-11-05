import sys


class comp:
    x = 0
    y = 0

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"[{self.x},{self.y}]"

    def copy(self):
        return comp(self.x, self.y)


def add(a, b):
    return comp(a.x + b.x, a.y + b.y)


def sub(a, b):
    return comp(a.x - b.x, a.y - b.y)


def mul(a, b):
    return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x)


def div(a, b):
    return comp(int(a.x / b.x), int(a.y / b.y))


def part1(a):
    ans = comp(0, 0)
    for i in range(3):
        ans = mul(ans, ans)
        ans = div(ans, comp(10, 10))
        ans = add(ans, a)
    print(ans)


def part2(a):
    curr = a.copy()
    res = 0
    for _ in range(101):
        for _ in range(101):
            ans = comp(0, 0)
            for _ in range(100):
                ans = mul(ans, ans)
                ans = div(ans, comp(100000, 100000))
                ans = add(ans, curr)
                if (
                    ans.x > 1000000
                    or ans.x < -1000000
                    or ans.y < -1000000
                    or ans.y > 1000000
                ):
                    break
            else:
                res += 1
            curr.x += 10
        curr.x = a.x
        curr.y += 10
    print(res)


def part3(a):
    curr = a.copy()
    res = 0
    for _ in range(1001):
        for _ in range(1001):
            ans = comp(0, 0)
            for _ in range(100):
                ans = mul(ans, ans)
                ans = div(ans, comp(100000, 100000))
                ans = add(ans, curr)
                if (
                    ans.x > 1000000
                    or ans.x < -1000000
                    or ans.y < -1000000
                    or ans.y > 1000000
                ):
                    break
            else:
                res += 1
            curr.x += 1
        curr.x = a.x
        curr.y += 1
    print(res)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    G = G.replace("A=[", "")
    G = G.replace("]", "")
    f = G.split(",")
    a = comp(int(f[0]), int(f[1]))

    part1(a)
    part2(a)
    part3(a)


if __name__ == "__main__":
    main()
