#include <bits/stdc++.h>
#include <cstdio>
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
	string line;
	vector<string> grid;
	ifstream input("../input.txt");
	while (getline(input, line)) {
		grid.push_back(line);
	}
	int R = grid.size();
	int C = grid[0].size();
	ll sr = 0;
	ll sc = 0;
	for (ll i = 0; i < R; ++i) {
		for (ll j = 0; j < C; ++j) {
			if (grid[i][j] == 'S') {
				sr = i;
				sc = j;
			}
		}
	}
	ll res = 0;
	queue<tuple<int, int, int>> q;
	set<pair<int, int>> seen;
	vector<vector<ll>> dist(R, vector<ll>(C, -1));
	q.push(make_tuple(0, sr, sc));
	while (!q.empty()) {
		auto [w, r, c] = q.front();
		q.pop();
		auto key = make_pair(r, c);
		if (seen.count(key)) {
			continue;
		}
		seen.insert(key);
		dist[r][c] = w;
		if (grid[r][c] == 'E') {
			res = w;
			break;
		}
		vector<pair<int, int>> next = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
		for (auto [dr, dc] : next) {
			int rr = r + dr;
			int cc = c + dc;
			if (rr >= 0 && cc >= 0 && cc < C && rr < R && grid[rr][cc] != '#') {
				q.push(make_tuple(w + 1, rr, cc));
			}
		}
	}
	int cutoff = 100;
	set<pair<int, int>> ans;
	queue<tuple<int, int, int, int, int, int>> nq;
	set<pair<int, int>> visited;
	map<pair<int, int>, pair<int, int>> visited_cheat;
	map<int, set<pair<int, int>>> chs;
	nq.push(make_tuple(0, sr, sc, -1, -1, 20));
	while (!nq.empty()) {
		auto [w, r, c, s, e, time] = nq.front();
		nq.pop();

		auto key = make_pair(r, c);
		if (w + 100 > res) {
			continue;
		}
		if (visited.count(key) && time == 20) {
			continue;
		}
		if (time == 20) {
			visited.insert(key);
		}
		if (time != 20) {
			auto cheat_key = make_pair(s, e);
			if (grid[r][c] != '#' && dist[r][c] >= w + cutoff) {
				ans.insert(cheat_key);
			}
			if (visited_cheat.count(cheat_key)) {
				if (visited_cheat[cheat_key].first >= time) {
					continue;
				}
			}
			visited_cheat[cheat_key] = make_pair(time, w);
		}
		if (time == 0) {
			continue;
		}
		vector<pair<int, int>> next = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
		for (auto [dr, dc] : next) {
			int rr = r + dr;
			int cc = c + dc;
			if (rr >= 0 && cc >= 0 && cc < C && rr < R) {
				if (time == 20 && grid[rr][cc] != '#') {
					nq.push(make_tuple(w + 1, rr, cc, r * C + c, rr * C + cc,
									   time - 1));
					nq.push(make_tuple(w + 1, rr, cc, -1, -1, 20));
				} else if (time == 20 && grid[rr][cc] == '#') {
					nq.push(make_tuple(w + 1, rr, cc, r * C + c, rr * C + cc,
									   time - 1));
				} else if (time > 1 && time < 20) {
					nq.push(
						make_tuple(w + 1, rr, cc, s, rr * C + cc, time - 1));
				} else if (time == 1 && grid[rr][cc] != '#') {
					nq.push(
						make_tuple(w + 1, rr, cc, s, rr * C + cc, time - 1));
				}
			}
		}
	}

	cout << ans.size() << endl;
	return 0;
}
