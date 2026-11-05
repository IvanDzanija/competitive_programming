import sys
import math


def part1(g):
    turns = list(map(int, g[0].split(",")))
    d = [[], [], [], []]
    for x in g[2:]:
        f1 = x[0:3]
        f2 = x[4:7]
        f3 = x[8:11]
        f4 = x[12:15]
        if f1 != "   " and f1 != "":
            d[0].append(f1)
        if f2 != "   " and f2 != "":
            d[1].append(f2)
        if f3 != "   " and f3 != "":
            d[2].append(f3)
        if f4 != "   " and f4 != "":
            d[3].append(f4)
    c1 = turns[0] * 100 % len(d[0])
    c2 = turns[1] * 100 % len(d[1])
    c3 = turns[2] * 100 % len(d[2])
    c4 = turns[3] * 100 % len(d[3])
    return d[0][c1] + " " + d[1][c2] + " " + d[2][c3] + " " + d[3][c4]


def part2(g):
    loops = 202420242024
    turns = list(map(int, g[0].split(",")))
    d = [[] for _ in range(len(turns))]
    for x in g[2:]:
        for i in range(len(turns)):
            curr = x[i * 4 : i * 4 + 3]
            if curr != "   " and curr != "":
                d[i].append(curr)
    ans = 0
    pos = [0] * len(turns)

    visited = set()
    seen = 0
    while seen < loops:
        curr = ""
        for j in range(len(pos)):
            pos[j] += turns[j]
            pos[j] %= len(d[j])
            curr += d[j][pos[j]][0]
            curr += d[j][pos[j]][2]
        if tuple(pos) in visited:
            break
        visited.add(tuple(pos))
        vis = set()
        for x in curr:
            if x in vis:
                continue
            vis.add(x)
            cnt = curr.count(x)
            ans += max(0, cnt - 2)
        seen += 1
    ans *= loops // seen
    looped = seen * (loops // seen)

    rem = loops - looped
    for j in range(len(turns)):
        pos[j] = turns[j] * looped
        pos[j] %= len(d[j])

    for i in range(rem):
        curr = ""
        for j in range(len(pos)):
            pos[j] += turns[j]
            pos[j] %= len(d[j])
            curr += d[j][pos[j]][0]
            curr += d[j][pos[j]][2]
        vis = set()
        for x in curr:
            if x in vis:
                continue
            vis.add(x)
            cnt = curr.count(x)
            ans += max(0, cnt - 2)

    return ans


def part3(g):
    turns = list(map(int, g[0].split(",")))
    d = [[] for _ in range(len(turns))]
    for x in g[2:]:
        for i in range(len(turns)):
            curr = x[i * 4 : i * 4 + 3]
            if curr != "   " and curr != "":
                d[i].append(curr)

    def score(state):
        curr = ""
        res = 0
        for j in range(len(state)):
            curr += d[j][state[j]][0]
            curr += d[j][state[j]][2]
        # print(curr)
        vis = set()
        for x in curr:
            if x in vis:
                continue
            vis.add(x)
            cnt = curr.count(x)
            res += max(0, cnt - 2)
        return res

    memo = dict()

    def dp(left, state, minF=False):
        if left == 0:
            return 0
        key = (left, tuple(state), minF)
        if key in memo:
            return memo[key]
        ans = -1
        for dPos in [-1, 0, 1]:
            newState = state[::]
            for j in range(len(state)):
                newState[j] += (turns[j] + dPos + len(d[j])) % len(d[j])
                newState[j] %= len(d[j])
            # print(newState)
            newScore = score(newState)
            # print(newScore)
            newSScore = newScore + dp(left - 1, newState, minF)
            # print(newSScore)
            if ans == -1:
                ans = newSScore
            elif minF and ans > newSScore:
                ans = newSScore
            elif (not minF) and ans < newSScore:
                ans = newSScore
        memo[key] = ans
        return ans

    start = [0] * len(turns)
    pulls = 256
    return str(dp(pulls, start)) + " " + str((dp(pulls, start, True)))


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
