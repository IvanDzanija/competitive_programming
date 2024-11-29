#include <bits/stdc++.h>
#include <chrono> // For measuring time
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
#include <unordered_set>

using namespace std::chrono;

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;
struct PairHash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(pair<int, int> x) const {
		static const uint64_t FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x.first + FIXED_RANDOM) +
			   splitmix64(x.second + FIXED_RANDOM);
	}
};
int count_bits(ll number) { return (int)log2(number) + 1; }
vector<char> ans;
vector<char> fans;
unordered_set<pair<int, int>, PairHash> visited;
int h, w;
char ng[1000][1000];

void find(int r, int c, int lr, int lc, int s) {
	if (ans.size() > s) {
		return;
	}
	if (r == lr && c == lc && ans.size() == s) {
		fans = ans;
		return;
	}
	pair<int, int> top = make_pair(r, c);
	if (ng[r][c] == '#' || ng[r][c] == 'M' || visited.count(top)) {
		return;
	}
	visited.insert(top);
	if (r - 1 >= 0 && ng[r - 1][c] == '.') {
		ans.push_back('U');
		find(r - 1, c, lr, lc, s);
		ans.pop_back();
	}
	if (r + 1 < h && ng[r + 1][c] == '.') {
		ans.push_back('D');
		find(r + 1, c, lr, lc, s);
		ans.pop_back();
	}
	if (c - 1 >= 0 && ng[r][c - 1] == '.') {
		ans.push_back('L');
		find(r, c - 1, lr, lc, s);
		ans.pop_back();
	}
	if (c + 1 < w && ng[r][c + 1] == '.') {
		ans.push_back('R');
		find(r, c + 1, lr, lc, s);
		ans.pop_back();
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	cin >> h >> w;
	int sr, sc;
	vector<pair<int, int>> monst;
	char grid[h][w];
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> grid[i][j];
			ng[i][j] = grid[i][j];
			if (grid[i][j] == 'A') {
				sr = i;
				sc = j;
			}
			if (grid[i][j] == 'M') {
				monst.push_back(make_pair(i, j));
			}
		}
	}
	queue<pair<int, int>> nq;
	for (auto x : monst) {
		nq.push(make_pair(x.first, x.second));
	}
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(sr, sc), 0));
	unordered_set<pair<ll, ll>, PairHash> vis;
	unordered_set<pair<ll, ll>, PairHash> v;
	int j = 0;
	bool f = false;
	while (!q.empty()) {
		++j;
		if (j & 1) {
			int p = q.size();
			while (p--) {
				auto top = q.front();
				int r = top.first.first;
				int c = top.first.second;
				int s = top.second;
				q.pop();
				if (vis.count(top.first) || grid[r][c] == '#' ||
					grid[r][c] == 'M') {
					continue;
				}
				vis.insert(top.first);
				if (r == 0 || c == 0 || c == w - 1 || r == h - 1) {
					cout << "YES" << endl;
					cout << s << endl;
					find(sr, sc, r, c, s);
					for (auto x : fans) {
						cout << x;
					}
					cout << endl;
					return 0;
				}
				if (r - 1 >= 0 && grid[r - 1][c] == '.') {
					q.push(make_pair(make_pair(r - 1, c), s + 1));
				}
				if (r + 1 < h && grid[r + 1][c] == '.') {
					q.push(make_pair(make_pair(r + 1, c), s + 1));
				}
				if (c - 1 >= 0 && grid[r][c - 1] == '.') {
					q.push(make_pair(make_pair(r, c - 1), s + 1));
				}
				if (c + 1 < w && grid[r][c + 1] == '.') {
					q.push(make_pair(make_pair(r, c + 1), s + 1));
				}
			}

		} else {
			ll z = nq.size();
			while (z > 0) {
				--z;
				auto top = nq.front();
				int r = top.first;
				int c = top.second;
				nq.pop();
				vis.insert(top);
				if (r - 1 >= 0 && grid[r - 1][c] != '#') {
					nq.push(make_pair(r - 1, c));
					grid[r - 1][c] = '#';
				}
				if (r + 1 < h && grid[r + 1][c] != '#') {
					nq.push(make_pair(r + 1, c));
					grid[r + 1][c] = '#';
				}
				if (c - 1 >= 0 && grid[r][c - 1] != '#') {
					nq.push(make_pair(r, c - 1));
					grid[r][c - 1] = '#';
				}
				if (c + 1 < w && grid[r][c + 1] != '#') {
					nq.push(make_pair(r, c + 1));
					grid[r][c + 1] = '#';
				}
			}
		}
	}
	if (!f) {
		cout << "NO" << "\n";
	}
	return 0;
}
