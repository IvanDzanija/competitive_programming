import sys


def find(x, link):
    while x != link[x]:
        x = link[x]
    return x


def same(a, b, link):
    return find(a, link) == find(b, link)


def unite(a, b, link, size):
    a = find(a, link)
    b = find(b, link)

    if size[a] < size[b]:
        a, b = b, a
    size[a] += size[b]
    link[b] = a
    return size, link


def part1(g, R, C):
    pos = []
    for i in range(R):
        for j in range(C):
            if g[i][j] == "*":
                pos.append((i, j))
    edges = []
    vis = set()
    for i in range(len(pos)):
        for j in range(len(pos)):
            if i == j:
                continue
            if (i, j) in vis or (j, i) in vis:
                continue
            vis.add((i, j))
            dist = abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1])
            edges.append((dist, i, j))
    edges = sorted(edges)
    # print(edges)
    ans = len(pos)
    link = [i for i in range(len(pos))]
    size = [1] * len(pos)
    for w, a, b in edges:
        if not same(a, b, link):
            size, link = unite(a, b, link, size)
            ans += w
    return ans


def part3(g, R, C):
    pos = []
    for i in range(R):
        for j in range(C):
            if g[i][j] == "*":
                pos.append((i, j))
    edges = []
    vis = set()
    mp = dict()
    for i in range(len(pos)):
        for j in range(len(pos)):
            if i == j:
                continue
            if (i, j) in vis or (j, i) in vis:
                continue
            vis.add((i, j))
            dist = abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1])
            if dist < 6:
                edges.append((dist, i, j))
                mp[(i, j)] = dist
                mp[(j, i)] = dist
    # print(edges)
    edges = sorted(edges)
    link = [i for i in range(len(pos))]
    size = [1] * len(pos)
    weights = dict()
    for w, a, b in edges:
        if not same(a, b, link):
            size, link = unite(a, b, link, size)
            weights[(a, b)] = w
            weights[(b, a)] = w
    graphs = []
    gc = dict()
    gcc = 0
    for i in range(len(link)):
        if link[i] == i:
            gc[link[i]] = gcc
            gcc += 1
            ng = [i]
            graphs.append(ng)
    for i in range(len(link)):
        if link[i] != i:
            ind = gc[find(link[i], link)]
            graphs[ind].append(i)
    ans = []
    for x in graphs:
        cans = len(x)
        # print(cans)
        visited = set()
        for i in x:
            for j in x:
                if i == j:
                    continue
                if (i, j) in visited or (j, i) in visited:
                    continue
                visited.add((i, j))
                visited.add((j, i))
                if (i, j) in weights:
                    cans += weights[(i, j)]
        ans.append(cans)
    ans = sorted(ans)
    return ans[-1] * ans[-2] * ans[-3]


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G, R, C))
    # part2 is the same as part1  just bigger grid
    # print(part3(G, R, C))
    return 0


if __name__ == "__main__":
    main()
