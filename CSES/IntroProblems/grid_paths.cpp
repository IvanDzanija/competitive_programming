#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9

using ll = int64_t;
using namespace __gnu_pbds;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

int ans;
int grid[9][9];
void solve(std::string path, int r, int c, int ind) {
	if (ind == 48 && r == 7 && c == 1) {
		++ans;
		return;
	}
	if (ind == 48)
		return;
	if (r == 7 && c == 1) {
		return;
	}
	if (grid[r - 1][c] == 1 && grid[r + 1][c] == 1 && grid[r][c - 1] == 0 &&
		grid[r][c + 1] == 0) {
		return;
	}
	if (grid[r][c - 1] == 1 && grid[r][c + 1] == 1 && grid[r - 1][c] == 0 &&
		grid[r + 1][c] == 0) {
		return;
	}
	if (grid[r - 1][c - 1] == 1 && grid[r][c - 1] == 0 && grid[r - 1][c] == 0) {
		return;
	}
	if (grid[r + 1][c + 1] == 1 && grid[r][c + 1] == 0 && grid[r + 1][c] == 0) {
		return;
	}
	if (grid[r + 1][c - 1] == 1 && grid[r][c - 1] == 0 && grid[r + 1][c] == 0) {
		return;
	}
	if (grid[r - 1][c + 1] == 1 && grid[r][c + 1] == 0 && grid[r - 1][c] == 0) {
		return;
	}
	grid[r][c] = 1;
	char curr = path.at(ind);
	if (curr == '?') {
		if (r < 7 && grid[r + 1][c] == 0) {
			solve(path, r + 1, c, ind + 1);
		}
		if (c < 7 && grid[r][c + 1] == 0) {
			solve(path, r, c + 1, ind + 1);
		}
		if (r > 1 && grid[r - 1][c] == 0) {
			solve(path, r - 1, c, ind + 1);
		}
		if (c > 1 && grid[r][c - 1] == 0) {
			solve(path, r, c - 1, ind + 1);
		}
	} else if (r < 7 && curr == 'D' && grid[r + 1][c] == 0) {
		solve(path, r + 1, c, ind + 1);
	} else if (r > 1 && curr == 'U' && grid[r - 1][c] == 0) {
		solve(path, r - 1, c, ind + 1);
	} else if (c < 7 && curr == 'R' && grid[r][c + 1] == 0) {
		solve(path, r, c + 1, ind + 1);
	} else if (c > 1 && curr == 'L' && grid[r][c - 1] == 0) {
		solve(path, r, c - 1, ind + 1);
	}
	grid[r][c] = 0;
	return;
}

int main(void) {
	ans = 0;
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::string input;
	std::cin >> input;

	for (int i = 0; i < 9; i++) {
		grid[0][i] = 1;
		grid[8][i] = 1;
		grid[i][0] = 1;
		grid[i][8] = 1;
	}
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			grid[i][j] = 0;
		}
	}

	solve(input, 1, 1, 0);
	std::cout << ans << std::endl;

	return 0;
}
