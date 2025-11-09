import sys


class Node:
    l, r, m = None, None, None
    v = -1

    def __init__(self, val, l=None, r=None, m=None):
        self.v = val
        self.l = l
        self.r = r
        self.m = m


def part1(a):
    # a = a.split(":")[1]
    # a = list(map(int, a.split(",")))
    root = None
    curr = None
    for x in a:
        if root is None:
            root = Node(x)
            continue
        curr = root
        while curr is not None:
            if x < curr.v and curr.l is None:
                curr.l = Node(x)
                break
            elif x > curr.v and curr.r is None:
                curr.r = Node(x)
                break
            elif curr.m is not None:
                curr = curr.m
            else:
                curr.m = Node(x)
                break
    ans = ""
    res = list()

    while root is not None:
        curr = ""
        ans += str(root.v)
        if root.l is not None:
            curr += str(root.l.v)
        curr += str(root.v)
        if root.r is not None:
            curr += str(root.r.v)
        curr = int(curr)
        res.append(curr)
        root = root.m
    return (int(ans), res)


def part2(G):
    G = G.split("\n")
    mx = 0
    mn = float("inf")
    for row in G:
        a = row.split(":")[1]
        a = list(map(int, a.split(",")))
        x = part1(a)
        mx = max(mx, x[0])
        mn = min(mn, x[0])
    print(mx - mn)


def part3(G):
    G = G.split("\n")
    res = list()
    for row in G:
        a = row.split(":")[1]
        b = row.split(":")[0]
        a = list(map(int, a.split(",")))
        x = part1(a)
        res.append((x[0], x[1], int(b)))
    res = sorted(res, reverse=True)
    ans = 0
    for i, x in enumerate(res):
        ans += (i + 1) * x[2]
    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    # part1(G)
    # part2(G)
    part3(G)


if __name__ == "__main__":
    main()
