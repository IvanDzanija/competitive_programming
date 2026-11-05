import sys


def part1(a):
    names = a.split("\n\n")[0].split(",")
    rules = a.split("\n\n")[1]
    b = dict()
    for line in rules.strip().splitlines():
        left, right = line.split(">")
        left = left.strip()
        right_values = [r.strip() for r in right.split(",")]
        b[left] = right_values

    for name in names:
        for i, x in enumerate(name):
            if i == len(name) - 1:
                print(name)
                return
            if not (x in b.keys() and name[i + 1] in b[x]):
                break


def part2(a):
    names = a.split("\n\n")[0].split(",")
    rules = a.split("\n\n")[1]
    b = dict()
    for line in rules.strip().splitlines():
        left, right = line.split(">")
        left = left.strip()
        right_values = [r.strip() for r in right.split(",")]
        b[left] = right_values

    ans = 0
    ind = 0
    for name in names:
        ind += 1
        for i, x in enumerate(name):
            if i == len(name) - 1:
                ans += ind
                break
            if not (x in b.keys() and name[i + 1] in b[x]):
                break
    print(ans)


def part3(a):
    names = a.split("\n\n")[0].split(",")
    rules = a.split("\n\n")[1]
    b = dict()
    for line in rules.strip().splitlines():
        left, right = line.split(">")
        left = left.strip()
        right_values = [r.strip() for r in right.split(",")]
        b[left] = right_values

    ans = set()

    def check(r):
        if r in ans or len(r) > 11:
            return
        if len(r) >= 7 and len(r) <= 11:
            ans.add(r)
        c = r[-1]
        if c in b.keys():
            for mr in b[c]:
                check(r + mr)

    ind = 0
    for name in names:
        if name in ans:
            continue
        ind += 1
        for i, x in enumerate(name):
            if i == len(name) - 1:
                check(name)
                break
            if not (x in b.keys() and name[i + 1] in b[x]):
                break
    print(len(ans))


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "a.in"
    G = open(infile).read().strip()
    # part1(G)
    # part2(G)
    # part3(G)


if __name__ == "__main__":
    main()
