from functools import cache, cached_property
from collections import deque, Counter, OrderedDict
from itertools import *
from math import *
import sys
from dataclasses import dataclass
import re
from builtins import pow
from heapq import heappush, heappop, heappushpop, heapify, heapreplace


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n")
    R = len(G)
    C = len(G[0])
    return 0


if __name__ == "__main__":
    main()
