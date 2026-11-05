#include <bits/stdc++.h>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
#include <queue>

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
	while (getline(input, line)) {
		grid.push_back(line);
	}
	ll R = grid.size();
	ll C = grid[0].size();
	ll sr = 0;
	ll sc = 0;
	for (ll r = 0; r < R; ++r) {
		for (ll c = 0; c < C; ++c) {
			if (grid[r][c] == 'S') {
				sr = r;
				sc = c;
			}
		}
	}
	ll ans = INF;
	priority_queue<tuple<ll, ll, ll, ll>> q;
	q.push(make_tuple(0, sr, sc, 0));
	map<pair<ll, ll>, ll> vis;
	while (!q.empty()) {
		auto [w, r, c, dir] = q.top();
		q.pop();
		if (vis.count(make_pair(r, c))) {
			if (vis[make_pair(r, c)] <= w) {
				continue;
			}
		}
		if (grid[r][c] == 'E') {
			ans = min(ans, w);
			continue;
		}
		vis[make_pair(r, c)] = w;
		if (dir == 0) {
			if (grid[r][c + 1] != '#') {
				q.push(make_tuple(w + 1, r, c + 1, 0));
			}
			if (grid[r - 1][c] != '#') {
				q.push(make_tuple(w + 1001, r - 1, c, 1));
			}
			if (grid[r + 1][c] != '#') {
				q.push(make_tuple(w + 1001, r + 1, c, 2));
			}
		}
		if (dir == 3) {
			if (grid[r][c - 1] != '#') {
				q.push(make_tuple(w + 1, r, c - 1, 3));
			}
			if (grid[r - 1][c] != '#') {
				q.push(make_tuple(w + 1001, r - 1, c, 1));
			}
			if (grid[r + 1][c] != '#') {
				q.push(make_tuple(w + 1001, r + 1, c, 2));
			}
		}
		if (dir == 1) {
			if (grid[r - 1][c] != '#') {
				q.push(make_tuple(w + 1, r - 1, c, 1));
			}
			if (grid[r][c - 1] != '#') {
				q.push(make_tuple(w + 1001, r, c - 1, 3));
			}
			if (grid[r][c + 1] != '#') {
				q.push(make_tuple(w + 1001, r, c + 1, 0));
			}
		}
		if (dir == 2) {
			if (grid[r + 1][c] != '#') {
				q.push(make_tuple(w + 1, r + 1, c, 2));
			}
			if (grid[r][c - 1] != '#') {
				q.push(make_tuple(w + 1001, r, c - 1, 3));
			}
			if (grid[r][c + 1] != '#') {
				q.push(make_tuple(w + 1001, r, c + 1, 0));
			}
		}
	}
	cout << ans << endl;
	return 0;
}
