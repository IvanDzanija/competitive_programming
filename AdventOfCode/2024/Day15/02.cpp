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
	map<char, string> two;
	two['.'] = "..";
	two['#'] = "##";
	two['O'] = "[]";
	two['@'] = "@.";
	while (getline(input, line)) {
		if (line.empty()) {
			read = 1;
			continue;
		}
		if (read == 0) {
			string curr;
			for (ll i = 0; i < line.size(); ++i) {
				curr.append(two[line[i]]);
			}
			for (ll i = 0; i < curr.size(); ++i) {
				if (curr[i] == '@') {
					sr = grid.size();
					sc = i;
				}
			}
			grid.push_back(curr);
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
		vector<pair<int, int>> box;
		set<pair<int, int>> seen;
		box.push_back(make_pair(sr, sc));
		for (int i = 0; i < box.size(); ++i) {
			int rr = box[i].first + dr;
			int cc = box[i].second + dc;
			if (seen.count(make_pair(rr, cc))) {
				continue;
			}
			seen.insert(make_pair(rr, cc));
			if (grid[rr][cc] == '#') {
				pos = false;
				break;
			} else if (grid[rr][cc] == ']') {
				box.push_back(make_pair(rr, cc));
				seen.insert(make_pair(rr, cc));
				box.push_back(make_pair(rr, cc - 1));
				seen.insert(make_pair(rr, cc - 1));
			} else if (grid[rr][cc] == '[') {
				box.push_back(make_pair(rr, cc));
				seen.insert(make_pair(rr, cc));
				box.push_back(make_pair(rr, cc + 1));
				seen.insert(make_pair(rr, cc + 1));
			}
		}
		if (!pos) {
			continue;
		} else {
			if (box.size() > 1) {
				auto ng = grid;
				for (ll i = 1; i < box.size(); ++i) {
					grid[box[i].first][box[i].second] = '.';
				}
				for (ll i = 1; i < box.size(); ++i) {
					grid[box[i].first + dr][box[i].second + dc] =
						ng[box[i].first][box[i].second];
				}
			}
			grid[sr][sc] = '.';
			grid[sr + dr][sc + dc] = '@';
			sr += dr;
			sc += dc;
		}
	}
	ll ans = 0;
	for (ll i = 0; i < grid.size(); ++i) {
		for (ll j = 0; j < grid[0].size(); ++j) {
			if (grid[i][j] == '[') {
				ans += (i * 100 + j);
			}
			// cout << grid[i][j];
		}
		// cout << endl;
	}
	cout << ans << endl;
	return 0;
}
