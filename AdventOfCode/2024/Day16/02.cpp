#include <bits/stdc++.h>
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
	set<pair<ll, ll>> ans;
	vector<string> grid;
	ll res = INF;
	while (getline(input, line)) {
		grid.push_back(line);
	}
	ll R = grid.size();
	ll C = grid[0].size();
	ll sr = 0;
	ll sc = 0;
	ll er = 0;
	ll ec = 0;
	for (ll r = 0; r < R; ++r) {
		for (ll c = 0; c < C; ++c) {
			if (grid[r][c] == 'S') {
				sr = r;
				sc = c;
			}
			if (grid[r][c] == 'E') {
				er = r;
				ec = c;
			}
		}
	}
	priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>,
				   greater<tuple<ll, ll, ll, ll>>>
		q;
	q.push(make_tuple(0, sr, sc, 0));
	set<tuple<ll, ll, ll>> vis;
	map<tuple<ll, ll, ll>, ll> fdist;
	while (!q.empty()) {
		auto [w, r, c, dir] = q.top();
		q.pop();
		auto key = make_tuple(r, c, dir);
		if (w > res) {
			continue;
		}
		if (grid[r][c] == '#') {
			continue;
		}
		if (!fdist.count(key)) {
			fdist[key] = w;
		}
		if (grid[r][c] == 'E') {
			res = min(res, w);
		}
		if (vis.count(key)) {
			continue;
		}
		vis.insert(key);
		if (dir == 0) {
			q.push(make_tuple(w + 1, r, c + 1, 0));
			q.push(make_tuple(w + 1000, r, c, 1));
			q.push(make_tuple(w + 1000, r, c, 2));
		}
		if (dir == 3) {
			q.push(make_tuple(w + 1, r, c - 1, 3));
			q.push(make_tuple(w + 1000, r, c, 1));
			q.push(make_tuple(w + 1000, r, c, 2));
		}
		if (dir == 1) {
			q.push(make_tuple(w + 1, r + 1, c, 1));
			q.push(make_tuple(w + 1000, r, c, 0));
			q.push(make_tuple(w + 1000, r, c, 3));
		}
		if (dir == 2) {
			q.push(make_tuple(w + 1, r - 1, c, 2));
			q.push(make_tuple(w + 1000, r, c, 0));
			q.push(make_tuple(w + 1000, r, c, 3));
		}
	}
	priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>,
				   greater<tuple<ll, ll, ll, ll>>>
		pq;
	pq.push(make_tuple(0, er, ec, 0));
	pq.push(make_tuple(0, er, ec, 1));
	pq.push(make_tuple(0, er, ec, 2));
	pq.push(make_tuple(0, er, ec, 3));
	map<tuple<ll, ll, ll>, ll> bdist;
	vis.clear();
	while (!pq.empty()) {
		auto [w, r, c, dir] = pq.top();
		pq.pop();
		auto key = make_tuple(r, c, dir);
		if (grid[r][c] == '#') {
			continue;
		}
		if (w > res) {
			continue;
		}
		if (!bdist.count(key)) {
			bdist[key] = w;
		}
		if (vis.count(key)) {
			continue;
		}
		vis.insert(key);
		if (dir == 0) {
			pq.push(make_tuple(w + 1, r, c - 1, 0));
			pq.push(make_tuple(w + 1000, r, c, 2));
			pq.push(make_tuple(w + 1000, r, c, 1));
		}
		if (dir == 3) {
			pq.push(make_tuple(w + 1, r, c + 1, 3));
			pq.push(make_tuple(w + 1000, r, c, 2));
			pq.push(make_tuple(w + 1000, r, c, 1));
		}
		if (dir == 1) {
			pq.push(make_tuple(w + 1, r - 1, c, 1));
			pq.push(make_tuple(w + 1000, r, c, 0));
			pq.push(make_tuple(w + 1000, r, c, 3));
		}
		if (dir == 2) {
			pq.push(make_tuple(w + 1, r + 1, c, 2));
			pq.push(make_tuple(w + 1000, r, c, 0));
			pq.push(make_tuple(w + 1000, r, c, 3));
		}
	}
	for (ll r = 0; r < R; ++r) {
		for (ll c = 0; c < C; ++c) {
			for (ll dir = 0; dir < 4; ++dir) {
				auto key = make_tuple(r, c, dir);
				if (fdist.count(key) && bdist.count(key) &&
					fdist[key] + bdist[key] == res) {
					ans.insert(make_pair(r, c));
				}
			}
		}
	}

	cout << ans.size() << endl;
	return 0;
}
