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
int count_bits(ll number) { return (int)log2(number) + 1; }
ll n, k;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	cin >> n >> k;
	vector<ll> path(n, 0);
	for (ll i = 0; i < n; ++i) {
		cin >> path[i];
	}
	vector<vector<ll>> p(k + 2, vector<ll>(n));
	for (ll i = 0; i <= k + 1; ++i) {
		for (ll j = 0; j < n; ++j) {
			p[i][j] = 0;
		}
	}

	if (path[0] != 0) {
		p[path[0]][0] = 1;
	} else {
		for (ll i = 1; i <= k; ++i) {
			p[i][0] = 1;
		}
	}
	for (ll i = 1; i < n; ++i) {
		if (path[i] != 0) {
			p[path[i]][i] = (p[path[i] - 1][i - 1] + p[path[i]][i - 1] +
							 p[path[i] + 1][i - 1]) %
							MOD;
		} else {
			for (ll j = 1; j <= k; ++j) {
				p[j][i] =
					(p[j - 1][i - 1] + p[j][i - 1] + p[j + 1][i - 1]) % MOD;
			}
		}
	}
	// for (ll i = 1; i <= k + 1; ++i) {
	// 	for (ll j = 0; j < n; ++j) {
	// 		cout << p[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	if (path[n - 1] != 0) {
		cout << p[path[n - 1]][n - 1] << endl;

	} else {
		ll ans = 0;
		for (ll i = 1; i <= k; ++i) {
			ans += p[i][n - 1];
			ans %= MOD;
		}
		cout << ans << endl;
	}

	return 0;
}
