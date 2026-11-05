#include <bits/stdc++.h>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
vector<string> grid;
int R;
int C;
int res;
int a;
set<pair<int, int>> seen;
void bfs(int r, int c) {
	if (seen.count(make_pair(r, c))) {
		return;
	}
	deque<tuple<int, int, int, int, int, int>> q;
	q.push_back(make_tuple(r, c, 0, 0, 0, 0));
	while (!q.empty()) {
		auto [r, c, n, e, s, w] = q.front();
		q.pop_front();
		if (seen.count(make_pair(r, c))) {
			continue;
		}
		++a;
		seen.insert(make_pair(r, c));
		vector<pair<int, int>> next;
		if (r + 1 < 0 || r + 1 >= R || grid[r + 1][c] != grid[r][c]) {
			if (!s) {
				if (!((c - 1 >= 0 && grid[r][c - 1] == grid[r][c] &&
					   seen.count(make_pair(r, c - 1)) &&
					   grid[r + 1][c - 1] != grid[r][c]) ||
					  (c + 1 < C && grid[r][c + 1] == grid[r][c] &&
					   seen.count(make_pair(r, c + 1)) &&
					   grid[r + 1][c + 1] != grid[r][c]))) {
					++res;
				}
			}
			s = 1;
		} else {
			s = 0;
			next.push_back(make_pair(r + 1, c));
		}
		if (r - 1 < 0 || grid[r - 1][c] != grid[r][c]) {
			if (!n) {
				if (!((c - 1 >= 0 && grid[r][c - 1] == grid[r][c] &&
					   seen.count(make_pair(r, c - 1)) &&
					   grid[r - 1][c - 1] != grid[r][c]) ||
					  (c + 1 < C && grid[r][c + 1] == grid[r][c] &&
					   seen.count(make_pair(r, c + 1)) &&
					   grid[r - 1][c + 1] != grid[r][c]))) {
					++res;
				}
			}
			n = 1;
		} else {
			n = 0;
			next.push_back(make_pair(r - 1, c));
		}
		if (c + 1 >= C || grid[r][c + 1] != grid[r][c]) {
			if (!e) {
				if (!((r - 1 >= 0 && grid[r - 1][c] == grid[r][c] &&
					   seen.count(make_pair(r - 1, c)) &&
					   grid[r - 1][c + 1] != grid[r][c]) ||
					  (r + 1 < C && grid[r + 1][c] == grid[r][c] &&
					   seen.count(make_pair(r + 1, c)) &&
					   grid[r + 1][c + 1] != grid[r][c]))) {
					++res;
				}
			}
			e = 1;
		} else {
			e = 0;
			next.push_back(make_pair(r, c + 1));
		}
		if (c - 1 < 0 || grid[r][c - 1] != grid[r][c]) {
			if (!w) {
				if (!((r - 1 >= 0 && grid[r - 1][c] == grid[r][c] &&
					   seen.count(make_pair(r - 1, c)) &&
					   grid[r - 1][c - 1] != grid[r][c]) ||
					  (r + 1 < C && grid[r + 1][c] == grid[r][c] &&
					   seen.count(make_pair(r + 1, c)) &&
					   grid[r + 1][c - 1] != grid[r][c]))) {
					++res;
				}
			}
			w = 1;
		} else {
			w = 0;
			next.push_back(make_pair(r, c - 1));
		}
		for (auto x : next) {
			q.push_back(make_tuple(x.first, x.second, n, e, s, w));
		}
	}

	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	while (getline(input, line)) {
		grid.push_back(line);
	}
	R = grid.size();
	C = grid[0].size();
	ll ans = 0;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			a = 0;
			res = 0;
			bfs(r, c);
			ans += a * res;
		}
	}
	cout << ans << endl;
	return 0;
}
