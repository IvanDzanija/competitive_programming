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
	vector<string> grid;
	vector<char> moves;
	int read = 0;
	int sr = 0;
	int sc = 0;
	while (getline(input, line)) {
		if (line.empty()) {
			read = 1;
			continue;
		}
		if (read == 0) {
			for (ll i = 0; i < line.size(); ++i) {
				if (line[i] == '@') {
					sr = grid.size();
					sc = i;
				}
			}
			grid.push_back(line);
		} else {
			for (auto x : line) {
				moves.push_back(x);
			}
		}
	}

	map<char, pair<int, int>> mp;
	mp['>'] = make_pair(0, 1);
	mp['<'] = make_pair(0, -1);
	mp['^'] = make_pair(-1, 0);
	mp['v'] = make_pair(1, 0);
	for (auto x : moves) {
		int dr = mp[x].first;
		int dc = mp[x].second;
		bool pos = true;
		int rr = sr;
		int cc = sc;
		vector<pair<int, int>> box;
		while (pos) {
			rr += dr;
			cc += dc;
			if (grid[rr][cc] == '#') {
				pos = false;
				break;
			} else if (grid[rr][cc] == '.') {
				break;
			} else {
				box.push_back(make_pair(rr, cc));
			}
		}
		if (!pos) {
			continue;
		} else {
			grid[sr][sc] = '.';
			grid[sr + dr][sc + dc] = '@';
			sr += dr;
			sc += dc;
			if (box.size() > 0) {
				auto fb = box[0];
				auto lb = box[box.size() - 1];
				grid[fb.first][fb.second] = '.';
				grid[lb.first + dr][lb.second + dc] = 'O';
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i < grid.size(); ++i) {
		for (ll j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == 'O') {
				ans += (i * 100 + j);
			}
			// cout << grid[i][j];
		}
		// cout << endl;
	}
	cout << ans << endl;
	return 0;
}
