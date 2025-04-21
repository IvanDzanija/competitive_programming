#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;
ll n, t;
string grid[1000];
int vis[1000][1000];
char steps[1000][1000];

int legal(int x, int y) {

	if (x >= 0 && y >= 0 && x < n && y < t && grid[x][y] != '#' &&
		vis[x][y] == 0) {
		return 1;
	}

	return 0;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

	cin >> n >> t;

	int r, c;
	int er, ec;
	for (ll i = 0; i < n; ++i) {
		cin >> grid[i];
		for (int j = 0; j < t; ++j) {
			if (grid[i][j] == 'A') {
				r = i;
				c = j;
			} else if (grid[i][j] == 'B') {
				er = i;
				ec = j;
			}
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		vis[x][y] = 1;
		if (legal(x - 1, y)) {
			vis[x - 1][y] = 1;
			steps[x - 1][y] = 'U';
			q.push({x - 1, y});
		}

		if (legal(x, y + 1)) {
			vis[x][y + 1] = 1;
			steps[x][y + 1] = 'R';
			q.push({x, y + 1});
		}

		if (legal(x + 1, y)) {
			vis[x + 1][y] = 1;
			steps[x + 1][y] = 'D';
			q.push({x + 1, y});
		}

		if (legal(x, y - 1)) {
			vis[x][y - 1] = 1;
			steps[x][y - 1] = 'L';
			q.push({x, y - 1});
		}
	}
	if (vis[er][ec] == 1) {
		cout << "YES" << endl;
		vector<char> step;
		while (er != r || ec != c) {
			if (steps[er][ec] == 'U') {
				++er;
				step.push_back('U');
			} else if (steps[er][ec] == 'D') {
				--er;
				step.push_back('D');
			} else if (steps[er][ec] == 'L') {
				++ec;
				step.push_back('L');
			} else if (steps[er][ec] == 'R') {
				--ec;
				step.push_back('R');
			}
		}
		cout << step.size() << endl;
		for (int i = step.size() - 1; i >= 0; --i) {
			cout << step[i];
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
