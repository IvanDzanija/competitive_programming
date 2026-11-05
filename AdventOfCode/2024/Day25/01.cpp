#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

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
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	string line;
	ifstream input("../input.txt");
	vector<vector<int>> locks;
	vector<vector<int>> keys;
	vector<string> grid;
	while (getline(input, line)) {
		if (line.empty()) {
			if (grid[0][0] == '#') {
				vector<int> lock;
				for (int c = 0; c < grid[0].size(); ++c) {
					int h = 0;
					for (int r = 1; r < grid.size(); ++r) {
						if (grid[r][c] == '#') {
							++h;
						} else {
							break;
						}
					}
					lock.push_back(h);
				}
				locks.push_back(lock);
			} else if (grid[0][0] == '.') {
				vector<int> key;
				for (int c = 0; c < grid[0].size(); ++c) {
					int h = 0;
					for (int r = grid.size() - 2; r >= 0; --r) {
						if (grid[r][c] == '#') {
							++h;
						} else {
							break;
						}
					}
					key.push_back(h);
				}
				keys.push_back(key);
			}

			grid.clear();
		} else {
			grid.push_back(line);
		}
	}
	if (grid[0][0] == '#') {
		vector<int> lock;
		for (int c = 0; c < grid[0].size(); ++c) {
			int h = 0;
			for (int r = 1; r < grid.size(); ++r) {
				if (grid[r][c] == '#') {
					++h;
				} else {
					break;
				}
			}
			lock.push_back(h);
		}
		locks.push_back(lock);
	} else if (grid[0][0] == '.') {
		vector<int> key;
		for (int c = 0; c < grid[0].size(); ++c) {
			int h = 0;
			for (int r = grid.size() - 2; r >= 0; --r) {
				if (grid[r][c] == '#') {
					++h;
				} else {
					break;
				}
			}
			key.push_back(h);
		}
		keys.push_back(key);
	}

	int height = 5;
	ll ans = 0;
	for (auto x : keys) {
		for (auto y : locks) {
			bool f = false;
			for (int i = 0; i < x.size(); ++i) {
				if (x[i] + y[i] > height) {
					f = true;
					break;
				}
			}
			if (!f) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
