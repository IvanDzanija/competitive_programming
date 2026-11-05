#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
	int R = 70;
	int C = 70;
	vector<vector<char>> grid(R + 1, vector<char>(C + 1, '.'));
	ll t = 1024;
	for (ll i = 0; i < t; ++i) {
		getline(input, line);
		ll x = stoll(line.substr(0, line.find(',')));
		line = line.substr(line.find(',') + 1);
		ll y = stoll(line);
		grid[y][x] = '#';
	}

	deque<tuple<int, int, int>> q;
	q.push_back(make_tuple(0, 0, 0));
	set<pair<int, int>> seen;
	ll ans = 0;
	while (!q.empty()) {
		auto [w, r, c] = q.front();
		auto key = make_pair(r, c);
		q.pop_front();
		if (r == R && c == C) {
			ans = w;
			break;
		}
		if (seen.count(key)) {
			continue;
		}
		seen.insert(key);
		cout << r << ' ' << c << endl;
		grid[r][c] = 'O';
		vector<pair<int, int>> next = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		for (auto [dr, dc] : next) {
			ll rr = r + dr;
			ll cc = c + dc;
			cout << rr << ' ' << cc << endl;
			if (rr >= 0 && rr <= R && cc <= C && cc >= 0 &&
				grid[rr][cc] != '#') {
				q.push_back(make_tuple(w + 1, rr, cc));
			}
		}
	}
	for (auto x : grid) {
		for (auto y : x) {
			cout << y;
		}
		cout << endl;
	}
	cout << ans << endl;
	return 0;
}
