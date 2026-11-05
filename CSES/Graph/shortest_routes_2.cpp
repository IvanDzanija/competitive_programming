#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

#define INF (int)1e9 + 1
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

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));
	for (ll i = 0; i < n; ++i) {
		dist[i][i] = 0;
	}
	for (ll i = 0; i < m; ++i) {
		ll x, y, w;
		cin >> x >> y >> w;
		--x;
		--y;
		if (w < dist[x][y]) {

			dist[x][y] = w;
			dist[y][x] = w;
		}
	}
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			for (ll k = 0; k < n; ++k) {
				if (dist[i][k] == LLONG_MAX || dist[j][i] == LLONG_MAX) {
					continue;
				}
				dist[j][k] = min(dist[i][k] + dist[j][i], dist[j][k]);
			}
		}
	}
	for (ll i = 0; i < q; ++i) {
		ll x, y;
		cin >> x >> y;
		--x;
		--y;
		if (dist[x][y] == LLONG_MAX) {
			cout << -1 << "\n";
		} else {
			cout << dist[x][y] << endl;
		}
	}
	return 0;
}
