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
    plants = dict()
    graph = dict()
    branches = list()

    free = re.compile(r"free branch with thickness (\d+)")
    plant = re.compile(r"branch to Plant (\d+) with thickness (\d+)")
    degree = dict()
    energy = dict()
    for x in a:
        x = x.split(":\n")
        plant_def = x[0].split(" with ")
        name = int(plant_def[0].split(" ")[1])
        size = int(plant_def[1].split(" ")[1])
        plants[name] = size

        branch_def = x[1]
        degree[name] = 0
        energy[name] = 0

        for line in branch_def.split("\n"):
            line = line.strip("- ").strip()

            m = free.fullmatch(line)
            if m:
                thickness = int(m.group(1))
                branches.append(name)
                energy[name] += thickness
                continue

            m = plant.fullmatch(line)
            if m:
                plant_num = int(m.group(1))
                thickness = int(m.group(2))
                if plant_num not in graph.keys():
                    graph[plant_num] = dict()
                graph[plant_num][name] = thickness
                degree[name] += 1

    q = list()
    for name in branches:
        q.append(name)

    while q:
        r = q.pop()

        curr = energy[r]
        if curr < plants[r]:
            curr = 0
        ans = curr
        if r in graph:
            for v, weight in graph[r].items():
                if v not in energy:
                    energy[v] = 0
                energy[v] += curr * weight

                degree[v] -= 1
                if degree[v] == 0:
                    q.append(v)

    print(ans)


def part2(a):
    ans = 0
    plants = dict()
    graph = dict()
    branches = list()

    free = re.compile(r"free branch with thickness (-?\d+)")
    plant = re.compile(r"branch to Plant (\d+) with thickness (-?\d+)")
    init_degree = dict()
    init_energy = dict()
    for x in a[:-1]:
        x = x.split(":\n")
        plant_def = x[0].split(" with ")
        name = int(plant_def[0].split(" ")[1])
        size = int(plant_def[1].split(" ")[1])
        plants[name] = size

        branch_def = x[1]
        init_degree[name] = 0
        init_energy[name] = 0

        for line in branch_def.split("\n"):
            line = line.strip("- ").strip()

            m = free.fullmatch(line)
            if m:
                thickness = int(m.group(1))
                branches.append(name)
                init_energy[name] += thickness
                continue

            m = plant.fullmatch(line)
            if m:
                plant_num = int(m.group(1))
                thickness = int(m.group(2))
                if plant_num not in graph.keys():
                    graph[plant_num] = dict()
                graph[plant_num][name] = thickness
                init_degree[name] += 1

    for x in a[-1].split("\n")[1:]:
        x = x.split(" ")
        res = 0
        q = list()
        degree = deepcopy(init_degree)
        energy = deepcopy(init_energy)
        for i, name in enumerate(sorted(branches)):
            mul = int(x[i])
            q.append((name, mul))

        while q:
            r, mul = q.pop()
            curr = energy[r]
            if curr < plants[r]:
                curr = 0
            curr *= mul
            res = curr
            if r in graph:
                for v, weight in graph[r].items():
                    if v not in energy:
                        energy[v] = 0
                    energy[v] += curr * weight

                    degree[v] -= 1
                    if degree[v] == 0:
                        q.append((v, 1))
        ans += res
    print(ans)


def part3(a):
    ans = 0
    plants = dict()
    graph = dict()
    branches = list()

    free = re.compile(r"free branch with thickness (-?\d+)")
    plant = re.compile(r"branch to Plant (\d+) with thickness (-?\d+)")
    init_degree = dict()
    init_energy = dict()

    sol = dict()
    for x in a[:-1]:
        x = x.split(":\n")
        plant_def = x[0].split(" with ")
        name = int(plant_def[0].split(" ")[1])
        size = int(plant_def[1].split(" ")[1])
        plants[name] = size

        branch_def = x[1]
        init_degree[name] = 0
        init_energy[name] = 0

        for line in branch_def.split("\n"):
            line = line.strip("- ").strip()

            m = free.fullmatch(line)
            if m:
                thickness = int(m.group(1))
                branches.append(name)
                init_energy[name] += thickness
                continue

            m = plant.fullmatch(line)
            if m:
                plant_num = int(m.group(1))
                thickness = int(m.group(2))
                if plant_num in branches:
                    if thickness < 0:
                        sol[plant_num - 1] = 0
                    else:
                        sol[plant_num - 1] = 1
                if plant_num not in graph.keys():
                    graph[plant_num] = dict()
                graph[plant_num][name] = thickness
                init_degree[name] += 1

    sorted_branches = sorted(branches)

    def run_simulation(current_bits):
        res = 0
        q = list()
        degree = deepcopy(init_degree)
        energy = deepcopy(init_energy)

        for i, name in enumerate(sorted_branches):
            mul = int(current_bits[i])
            q.append((name, mul))

        while q:
            r, mul = q.pop()
            curr = energy[r]
            if curr < plants[r]:
                curr = 0
            curr *= mul
            res = curr

            if r in graph:
                for v, weight in graph[r].items():
                    if v not in energy:
                        energy[v] = 0
                    energy[v] += curr * weight

                    degree[v] -= 1
                    if degree[v] == 0:
                        q.append((v, 1))
        return res

    dragons = list()
    best_score = -1
    best_bits = []

    for x in a[-1].split("\n")[1:]:
        x = x.split(" ")
        bits = [int(b) for b in x]

        score = run_simulation(bits)
        dragons.append(score)

        if score > best_score:
            best_score = score
            best_bits = list(bits)

    current_bits = list(best_bits)
    max_res = best_score

    improved = True
    while improved:
        improved = False
        for i in range(len(current_bits)):
            current_bits[i] = 1 - current_bits[i]

            new_score = run_simulation(current_bits)

            if new_score > max_res:
                max_res = new_score
                improved = True
            else:
                current_bits[i] = 1 - current_bits[i]

    for x in dragons:
        if x > 0:
            ans += max_res - x

    print(ans)


def main():
    infile = sys.argv[1] if len(sys.argv) >= 2 else "A.in"
    G = open(infile).read().strip()
    G = G.split("\n\n")
    # part1(G)
    # part2(G)
    part3(G)
    return 0


if __name__ == "__main__":
    main()
