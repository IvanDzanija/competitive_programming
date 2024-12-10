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
	vector<vector<int>> g;
	set<pair<int, int>> starts;
	while (getline(input, line)) {
		vector<int> temp;
		for (auto x : line) {
			if (x - '0' == 0) {
				starts.insert(make_pair(g.size(), temp.size()));
			}
			temp.push_back(x - '0');
		}
		g.push_back(temp);
	}
	// for (auto x : g) {
	// 	for (auto y : x) {
	// 		cout << y << ' ';
	// 	}
	// 	cout << endl;
	// }
	// for (auto x : starts) {
	// 	cout << x.first << ' ' << x.second << endl;
	// }
	ll res = 0;
	int R = g.size();
	int C = g[0].size();
	for (auto x : starts) {
		deque<tuple<int, int, int>> q;
		q.push_back(make_tuple(x.first, x.second, 0));
		while (!q.empty()) {
			auto [r, c, last] = q.front();
			q.pop_front();
			if (last == 9) {
				++res;
				continue;
			}
			vector<pair<int, int>> pos = {make_pair(1, 0), make_pair(-1, 0),
										  make_pair(0, 1), make_pair(0, -1)};
			for (auto x : pos) {
				int rr = r + x.first;
				int cc = c + x.second;
				if (rr >= 0 && rr < R && cc >= 0 && cc < C &&
					g[rr][cc] - 1 == last) {
					q.push_back(make_tuple(rr, cc, last + 1));
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
