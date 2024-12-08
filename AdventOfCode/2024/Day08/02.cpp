#include <bits/stdc++.h>
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
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	vector<string> grid;
	map<char, vector<pair<int, int>>> coords;
	while (getline(input, line)) {
		int r = grid.size();
		grid.push_back(line);
		for (int c = 0; c < line.size(); ++c) {
			if (line[c] != '.') {
				coords[line[c]].push_back(make_pair(r, c));
			}
		}
	}
	int R = grid.size();
	int C = grid[0].size();
	set<pair<int, int>> ans;
	for (auto x : coords) {
		for (ll i = 0; i < x.second.size(); ++i) {
			for (ll j = i + 1; j < x.second.size(); ++j) {
				auto [r1, c1] = x.second[i];
				auto [r2, c2] = x.second[j];
				ans.insert(make_pair(r1, c1));
				ans.insert(make_pair(r2, c2));
				int dr = r2 - r1;
				int dc = c2 - c1;
				int rr1 = r1 - dr;
				int cc1 = c1 - dc;
				while (rr1 >= 0 && cc1 >= 0 && rr1 < R && cc1 < C) {
					ans.insert(make_pair(rr1, cc1));
					rr1 -= dr;
					cc1 -= dc;
				}
				int rr2 = r2 + dr;
				int cc2 = c2 + dc;
				while (rr2 >= 0 && cc2 >= 0 && rr2 < R && cc2 < C) {
					ans.insert(make_pair(rr2, cc2));
					rr2 += dr;
					cc2 += dc;
				}
			}
		}
	}
	cout << ans.size() << endl;

	return 0;
}
