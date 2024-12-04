import sys


def part1(g, R, C):
    targets = set()
    shooters = []
    for i in range(len(g)):
        g[i] = list(g[i])
        for j in range(len(g[i])):
            if g[i][j] == "T":
                targets.add((i, j))
            elif g[i][j] == "A":
                shooters.append((i, j))
            elif g[i][j] == "B":
                shooters.append((i, j))
            elif g[i][j] == "C":
                shooters.append((i, j))
    pow = 1
    ans = 0
    while len(targets) > 0:
        for i in range(len(shooters)):
            r = shooters[i][0]
            c = shooters[i][1]
            print(r, c)
            left = pow
            while left > 0:
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow
                r -= 1
                c += 1
                left -= 1

            left = pow
            while left > 0:
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow
                c += 1
                left -= 1
            if r < 0:
                c += -r
                r = 0
            while c < C and g[r][c] != "=":
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow
                r += 1
                c += 1
        pow += 1

    return ans


def part2(g, R, C):
    targets = set()
    values = dict()
    shooters = []
    for i in range(len(g)):
        g[i] = list(g[i])
        for j in range(len(g[i])):
            if g[i][j] == "T":
                targets.add((i, j))
                values[(i, j)] = 1
            elif g[i][j] == "H":
                targets.add((i, j))
                values[(i, j)] = 2
            elif g[i][j] == "A":
                shooters.append((i, j))
            elif g[i][j] == "B":
                shooters.append((i, j))
            elif g[i][j] == "C":
                shooters.append((i, j))
    pow = 1
    ans = 0
    while len(targets) > 0:
        for i in range(len(shooters)):
            r = shooters[i][0]
            c = shooters[i][1]
            left = pow
            while left > 0:
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow * values[(r, c)]
                r -= 1
                c += 1
                left -= 1

            left = pow
            while left > 0:
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow * values[(r, c)]
                c += 1
                left -= 1
            if r < 0:
                c += -r
                r = 0
            while c < C and g[r][c] != "=":
                if (r, c) in targets:
                    targets.remove((r, c))
                    ans += (3 - i) * pow * values[(r, c)]
                r += 1
                c += 1
        pow += 1

    return ans


class Shot:
    def __init__(self, x, y, left, value, power):
        self.x = x
        self.y = y
        self.left = left
        self.value = value
        self.power = power


def part3(g):
    ans = 0
    shooters = [(0, 0), (0, 1), (0, 2)]
    targets = []
    for x in g:
        r, c = x.split(" ")
        targets.append((int(r), int(c)))

    shots = []
    power = 0
    time = 0
    inRange = {}
    while len(targets) > 0:
        newShots = []
        for shot in shots:
            if shot.y < 0:
                continue
            if shot.left > 0:
                shot.left -= 1
                shot.x += 1
            else:
                shot.x += 1
                shot.y -= 1
            newShots.append(shot)
        shots = newShots[:]
        power += 1
        time += 1
        index = 1
        for shooter in shooters:
            currX = shooter[0] + time
            currY = shooter[1] + time
            currLeft = power
            currPower = power
            currValue = index
            current = Shot(
                x=currX, y=currY, left=currLeft, value=currValue, power=currPower
            )
            shots.append(current)
            index += 1

        for shot in shots:
            if (shot.x, shot.y) in inRange:
                inRange[(shot.x, shot.y)] = min(
                    shot.power * shot.value, inRange[(shot.x, shot.y)]
                )
            else:
                inRange[(shot.x, shot.y)] = shot.power * shot.value

        newTargets = []
        for target in targets:
            RR = target[0] - 1
            CC = target[1] - 1
            if (RR, CC) in inRange:
                ans += inRange[(RR, CC)]
                continue
            else:
                newTargets.append((RR, CC))
        targets = newTargets

    return ans


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    # print(part1(G, R, C))
    # print(part2(G, R, C))
    # print(part3(G))
    return 0


if __name__ == "__main__":
    main()
