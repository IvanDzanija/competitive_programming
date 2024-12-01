import sys
from json.encoder import INFINITY


# think it's wrong but passed/ can't prove greedy works
def part1(g):
    stamps = [1, 3, 5, 10]
    ans = 0
    i = 3
    for x in g:
        x = int(x)
        for i in range(3, -1, -1):
            while x - stamps[i] >= 0:
                ans += 1
                x -= stamps[i]
    return ans


# https://www.cses.fi/problemset/task/1634
# coin minimization dp
def part2(g):
    g = list(map(int, g))
    stamps = [1, 3, 5, 10, 15, 16, 20, 24, 25, 30]
    dp = [INFINITY] * (max(g) + 1)
    dp[0] = 0
    for i in range(1, max(g) + 1):
        for j in range(len(stamps)):
            if i < stamps[j]:
                continue
            if dp[i - stamps[j]] == INFINITY:
                continue
            dp[i] = min(1 + dp[i - stamps[j]], dp[i])
    ans = 0
    for x in g:
        ans += dp[x]
    return ans


# precompute dp
def part3(g):
    g = list(map(int, g))
    stamps = [1, 3, 5, 10, 15, 16, 20, 24, 25, 30, 37, 38, 49, 50, 74, 75, 100, 101]
    dp = [INFINITY] * (max(g) + 1)
    dp[0] = 0
    for i in range(1, max(g) + 1):
        for j in range(len(stamps)):
            if i < stamps[j]:
                continue
            if dp[i - stamps[j]] == INFINITY:
                continue
            dp[i] = min(1 + dp[i - stamps[j]], dp[i])
    ans = 0
    for x in g:
        curr = INFINITY
        lo = x // 2
        hi = x // 2
        if x & 1:
            hi += 1
        for y in range(50):
            curr = min(curr, dp[lo - y] + dp[hi + y])
        ans += curr
    return ans


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
