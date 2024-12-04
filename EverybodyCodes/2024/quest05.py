import sys


def part1(g):
    for i in range(10):
        j = i % 4
        nj = (j + 1) % 4
        h = len(g[nj])
        curr = g[j][0]
        g[j].pop(0)
        pos = curr % (h * 2)
        if pos == 0:
            pos = h * 2
        if pos > h:
            if pos == h * 2:
                g[nj].insert(1, curr)
            else:
                pos %= h
                pos = h - (pos - 1)
                g[nj].insert(pos, curr)
        else:
            g[nj].insert(pos - 1, curr)
        ans = ""
        for j in range(4):
            ans += str(g[j][0])
        print(ans)
        if i == 9:
            return ans


def part2(g):
    d = dict()
    i = 0
    while True:
        j = i % 4
        i += 1
        nj = (j + 1) % 4
        h = len(g[nj])
        curr = g[j][0]
        g[j].pop(0)
        pos = curr % (h * 2)
        if pos == 0:
            pos = h * 2
        if pos > h:
            if pos == h * 2:
                g[nj].insert(1, curr)
            else:
                pos %= h
                pos = h - (pos - 1)
                g[nj].insert(pos, curr)
        else:
            g[nj].insert(pos - 1, curr)
        ans = ""
        for k in range(4):
            ans += str(g[k][0])
        print(ans)
        if (ans) not in d:
            d[ans] = 1
        else:
            d[ans] += 1
        if d[ans] == 2024:
            return int(ans) * i


def part3(g):
    s = set()
    sp = set()
    i = 0
    cnt = 0
    while True:
        j = i % 4
        i += 1
        nj = (j + 1) % 4
        h = len(g[nj])
        curr = g[j][0]
        g[j].pop(0)
        pos = curr % (h * 2)
        if pos == 0:
            pos = h * 2
        if pos > h:
            if pos == h * 2:
                g[nj].insert(1, curr)
            else:
                pos %= h
                pos = h - (pos - 1)
                g[nj].insert(pos, curr)
        else:
            g[nj].insert(pos - 1, curr)
        ans = ""
        for k in range(4):
            ans += str(g[k][0])
        # print(ans)
        s.add(int(ans))
        saver = ""
        for x in g:
            for y in x:
                saver += str(y)
        if saver in sp:
            cnt += 1
        else:
            sp.add(saver)
        if cnt == 100:
            return max(s)


def rotated(array_2d):
    list_of_tuples = zip(*array_2d[::-1])
    nl = [list(elem) for elem in list_of_tuples]
    list_of_tuples = zip(*nl[::-1])
    nl = [list(elem) for elem in list_of_tuples]
    list_of_tuples = zip(*nl[::-1])
    nl = [list(elem) for elem in list_of_tuples]
    return nl[::-1]


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    NG = []
    for x in G:
        NG.append(list(map(int, x.split(" "))))
    NG = rotated(NG)
    # print(part1(NG))
    # print(part2(NG))
    print(part3(NG))
    return 0


if __name__ == "__main__":
    main()
