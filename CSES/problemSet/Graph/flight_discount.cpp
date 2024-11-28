#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
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
int count_bits(ll number) { return (int)log2(number) + 1; }

vector<ll> dijkstra(vector<vector<pair<int, int>>> g, int start, int n) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
		pq;
	pq.push(make_pair(0ll, start));
	vector<ll> vis(n, -1);
	while (!pq.empty()) {
		auto [w, curr] = pq.top();
		pq.pop();
		if (vis[curr] != -1) {
			continue;
		}
		vis[curr] = w;
		for (auto i : g[curr]) {
			pq.push(make_pair(w + i.second, i.first));
		}
	}
	return vis;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	vector<vector<pair<int, int>>> gr(n);
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		--x;
		--y;
		g[x].push_back(make_pair(y, w));
		gr[y].push_back(make_pair(x, w));
	}

	vector<ll> vis1 = dijkstra(g, 0, n);
	vector<ll> vis2 = dijkstra(gr, n - 1, n);
	// for (auto x : vis1) {
	// 	cout << x << ' ';
	// }
	// cout << endl;
	// for (auto x : vis2) {
	// 	cout << x << ' ';
	// }
	// cout << endl;
	ll ans = LLONG_MAX;
	for (ll i = 0; i < n; ++i) {
		if (vis1[i] == -1) {
			continue;
		}
		for (auto x : g[i]) {
			if (vis2[x.first] == -1) {
				continue;
			}
			ans = min(ans, vis1[i] + x.second / 2 + vis2[x.first]);
		}
	}
	cout << ans << endl;

	return 0;
}
