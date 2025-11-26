from functools import cache, cached_property
from collections import deque, Counter, OrderedDict
from itertools import *
from math import *
import sys
import heapq
from copy import deepcopy
from dataclasses import dataclass
import re
from builtins import pow

GRID_MOVES = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def part1(a):
    ans = 0
    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    part1(G)
    # part2(G)
    # part3(G)
    return 0


if __name__ == "__main__":
    main()
