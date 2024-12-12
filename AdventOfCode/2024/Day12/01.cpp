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
vector<string> grid;
int R;
int C;
int res;
int a;
set<pair<int, int>> seen;
void dfs(int r, int c) {
	int p = 4;
	if (seen.count(make_pair(r, c))) {
		return;
	}

	++a;
	seen.insert(make_pair(r, c));
	vector<pair<int, int>> next = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	for (auto [dr, dc] : next) {
		int rr = r + dr;
		int cc = c + dc;
		if (rr >= 0 && rr < R && cc >= 0 && cc < C &&
			grid[r][c] == grid[rr][cc]) {
			dfs(rr, cc);
			--p;
		}
	}
	res += p;
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
			dfs(r, c);
			ans += a * res;
		}
	}
	cout << ans << endl;

	return 0;
}
