import sys
from queue import PriorityQueue


def part1(g):
    ans = {}
    gr = {}
    for x in g:
        f = x.split(":")[0]
        nodes = x.split(":")[1].split(",")
        gr[f] = nodes
    vis = set()
    pq = PriorityQueue()
    pq.put(("RR", "", 0))
    while not pq.empty():
        top = pq.get()
        if top[0] in vis:
            continue
        vis.add(top)
        if top[0] not in gr:
            continue
        next = gr[top[0]]
        print(next)
        for y in next:
            if y != "@":
                pq.put((y, top[1] + top[0], top[2] + 1))
            else:
                if top[2] + 1 not in ans:
                    ans[top[2] + 1] = [top[1] + top[0] + "@"]
                else:
                    ans[top[2] + 1].append(top[1] + top[0] + "@")
    for x in ans.items():
        if len(x[1]) == 1:
            return x[1][0]
    return 0


def part2(g):
    ans = {}
    gr = {}
    for x in g:
        f = x.split(":")[0]
        nodes = x.split(":")[1].split(",")
        gr[f] = nodes
    vis = set()
    pq = PriorityQueue()
    pq.put(("RR", "", 0))
    while not pq.empty():
        top = pq.get()
        if top[0] in vis:
            continue
        vis.add(top)
        if top[0] not in gr:
            continue
        next = gr[top[0]]
        print(next)
        for y in next:
            if y != "@":
                pq.put((y, top[1] + top[0][0], top[2] + 1))
            else:
                if top[2] + 1 not in ans:
                    ans[top[2] + 1] = [top[1] + top[0][0] + "@"]
                else:
                    ans[top[2] + 1].append(top[1] + top[0][0] + "@")
    for x in ans.items():
        if len(x[1]) == 1:
            return x[1][0]
    return 0


def part3(g):
    ans = {}
    gr = {}
    for x in g:
        f = x.split(":")[0]
        nodes = x.split(":")[1].split(",")
        gr[f] = nodes
    vis = set()
    pq = PriorityQueue()
    pq.put(("RR", "", 0))
    while not pq.empty():
        top = pq.get()
        if top[0] in vis:
            continue
        vis.add(top)
        if top[0] not in gr:
            continue
        next = gr[top[0]]
        # print(next, top)
        for y in next:
            if y != "@" and y != "ANT" and y != "BUG":
                pq.put((y, top[1] + top[0][0], top[2] + 1))
            else:
                if top[2] + 1 not in ans:
                    ans[top[2] + 1] = [top[1] + top[0][0] + "@"]
                else:
                    ans[top[2] + 1].append(top[1] + top[0][0] + "@")
    for x in ans.items():
        if len(x[1]) == 1:
            return x[1][0]
    return 0


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G))
    # print(part2(G))
    print(part3(G))
    return 0


if __name__ == "__main__":
    main()
