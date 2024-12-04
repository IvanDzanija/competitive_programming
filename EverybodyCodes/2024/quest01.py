def part1(a):
    ans = 0
    for c in a:
        if c == "B":
            ans += 1
        elif c == "C":
            ans += 3
        elif c == "D":
            ans += 5
    return ans


def part2(a):
    ans = 0

    for i in range(0, len(a), 2):
        s = a[i : i + 2]
        if "x" in s:
            ans += part1(s)
        else:
            ans += part1(s) + 2
    return ans


def part3(a):
    ans = 0
    for i in range(0, len(a), 3):
        s = a[i : i + 3]
        s = s.replace("x", "")
        if len(s) == 1:
            ans += part1(s)
        elif len(s) == 2:
            ans += part1(s) + 2
        elif len(s) == 3:
            ans += part1(s) + 6
    return ans


def main():
    a = input()
    # print(part1(a))
    # print(part2(a))
    # print(part3(a))
    return 0


if __name__ == "__main__":
    main()
