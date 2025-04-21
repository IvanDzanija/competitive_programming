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

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n;
	cin >> n;
	string grid[n];
	ll ans[n + 1][n + 1];

	for (ll i = 0; i < n; ++i) {
		cin >> grid[i];
	}
	for (ll i = 0; i <= n; ++i) {
		for (ll j = 0; j <= n; ++j) {
			ans[i][j] = 0;
		}
	}
	if (grid[0][0] != '*') {
		ans[1][1] = 1;
	}

	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < n; ++j) {
			if (i + j == 0) {
				continue;
			} else {
				if (grid[i][j] != '*') {
					ans[i + 1][j + 1] = (ans[i][j + 1] + ans[i + 1][j]) % MOD;
				}
			}
		}
	}
	// for (ll i = 0; i < n + 1; ++i) {
	// 	for (ll j = 0; j < n + 1; ++j) {
	// 		cout << ans[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	cout << ans[n][n] << endl;

	return 0;
}
