import sys
from collections import deque


def part1(g):
    states = deque()
    states.append("A")
    dict = {}
    for x in g:
        xs = x.split(":")
        dict[xs[0]] = xs[1].split(",")
    for i in range(4):
        count = len(states)
        for j in range(count):
            top = states.popleft()
            for x in dict[top]:
                states.append(x)

    return len(states)


def part2(g):
    states = deque()
    states.append("Z")
    dict = {}
    for x in g:
        xs = x.split(":")
        dict[xs[0]] = xs[1].split(",")
    for i in range(10):
        count = len(states)
        for j in range(count):
            top = states.popleft()
            for x in dict[top]:
                states.append(x)
    return len(states)


def closure(prev, dict):
    new = {x: 0 for x in dict}

    for x, y in prev.items():
        for z in dict[x]:
            new[z] += y
    return new


def part3(g):
    dict = {}
    for x in g:
        xs = x.split(":")
        dict[xs[0]] = xs[1].split(",")
    ans = []
    for start in dict:
        curr = {x: 0 for x in dict.keys()}
        curr[start] = 1
        for i in range(20):
            curr = closure(curr, dict)

        res = 0
        for x in curr.values():
            res += x
        ans.append(res)
    return max(ans) - min(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G))
    # print(part2(G))
    # print(part3(G))
    return 0


if __name__ == "__main__":
    main()
