// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (ll)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;
struct custom_hash {
	static ull splitmix64(ull x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(ull x) const {
		static const ull FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
bool found = false;
set<int> visited;
stack<int> res;
void dfs(vector<vector<int>> &vec, vector<int> &col, int node, int prev) {
	if (node != prev && col[node] == 1) {
		found = true;
		res.push(node);
		return;
	}
	if (visited.count(node) || found) {
		return;
	}
	visited.insert(node);
	col[node] = 1;
	res.push(node);
	for (int u : vec[node]) {
		dfs(vec, col, u, node);
		if (found) {
			return;
		}
	}
	if (!found) {
		col[node] = 0;
		res.pop();
	}
	return;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(n + 1);

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		vec[x].push_back(y);
	}
	vector<int> col(n + 1, 0);
	int k = 0;
	while (!found && ++k <= n) {
		dfs(vec, col, k, 0);
	}
	if (!found) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		vector<int> ans;
		int start = res.top();
		res.pop();
		ans.push_back(start);
		int node = -1;
		while (node != start) {
			node = res.top();
			res.pop();
			ans.push_back(node);
		}
		cout << ans.size() << endl;
		for (int i = ans.size() - 1; i >= 0; --i) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
#ifdef LOCAL
		cout << "--------------------------------------------" << endl;
#endif
	}

#ifdef LOCAL
	cerr << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}
