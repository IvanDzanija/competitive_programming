#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using ll = int64_t;

int main(void) {
	int n, m;
	std::cin >> n >> m;
	std::pair<ll, ll> start;
	std::vector<std::string> grid;
	for (int i = 0; i < n; ++i) {
		std::string row;
		std::cin >> row;
		for (int j = 0; j < m; ++j) {
		}
		grid.push_back(row);
	}

	std::set<std::pair<int, int>> seen;
	std::vector<char> path;
	int foundEnd = 0;
	std::deque<std::pair<int, int>> q;
	while (!(seen.size() == n * m || foundEnd)) {
		std::pair<int, int> current;
		if (seen.count(current)) {
			continue;
		} else if (grid.at(current.first).at(current.second) == 'B') {
			foundEnd = 1;
		}
	}

	return 0;
}
