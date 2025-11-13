import sys


def part1(a):
    a = a.split("\n")
    r = list()
    for x in a:
        x = x.split(":")[1]
        r.append(x)
    f, s = 0, 0
    for i in range(len(r[0])):
        x = r[0][i]
        y = r[1][i]
        z = r[2][i]
        if x == z:
            s += 1
        if y == z:
            f += 1
    print(f * s)


def part2(a):
    a = a.split("\n")
    r = list()
    for x in a:
        x = x.split(":")[1]
        r.append(x)
    n = len(r)
    ans = 0
    pars = set()
    for j in range(n):
        if j in pars:
            continue
        pots = list()
        for k in range(n):
            if j == k:
                pots.append(list())
                continue
            curr = list()
            for i in range(len(r[0])):
                x = r[j][i]
                y = r[k][i]
                if x == y:
                    curr.append(1)
                else:
                    curr.append(0)
            pots.append(curr)
        for jj in range(n):
            if len(pots[jj]) == 0:
                continue
            for kk in range(jj + 1, n):
                f = 0
                s = 0
                if len(pots[kk]) == 0:
                    continue
                for ii in range(len(pots[jj])):
                    x = pots[jj][ii]
                    y = pots[kk][ii]
                    if x == 0 and y == 0:
                        break
                    if x == 1:
                        f += 1
                    if y == 1:
                        s += 1
                else:
                    ans += f * s
                    pars.add(jj)
                    pars.add(kk)
    print(ans)


def part3(a):
    a = a.split("\n")
    r = list()
    for x in a:
        x = x.split(":")[1]
        r.append(x)
    n = len(r)
    sizes = [1] * n
    links = [i for i in range(n)]

    def find(v):
        while v != links[v]:
            v = links[v]
        return v

    def unite(u, v):
        u, v = find(u), find(v)
        if u == v:
            return False
        if sizes[u] < sizes[v]:
            u, v = v, u
        links[v] = u
        sizes[u] += sizes[v]

    for j in range(n):
        pots = list()
        for k in range(n):
            if j == k:
                pots.append(list())
                continue
            curr = list()
            for i in range(len(r[0])):
                x = r[j][i]
                y = r[k][i]
                if x == y:
                    curr.append(1)
                else:
                    curr.append(0)
            pots.append(curr)
        for jj in range(n):
            if len(pots[jj]) == 0:
                continue
            for kk in range(jj + 1, n):
                f = 0
                s = 0
                if len(pots[kk]) == 0:
                    continue
                for ii in range(len(pots[jj])):
                    x = pots[jj][ii]
                    y = pots[kk][ii]
                    if x == 0 and y == 0:
                        break
                    if x == 1:
                        f += 1
                    if y == 1:
                        s += 1
                else:
                    unite(jj, kk)
                    unite(j, jj)
    lead = -1
    mx = 0
    for i, x in enumerate(sizes):
        if x > mx:
            mx = x
            lead = find(i)
    res = 0
    for i, x in enumerate(links):
        if find(i) == lead:
            res += i + 1
    print(res)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    # part1(G)
    # part2(G)
    # part3(G)


if __name__ == "__main__":
    main()
