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
	ll t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> vec(n + 2);
		for (ll i = 1; i <= n; i++) {
			cin >> vec[i];
		}
		// for (auto x : vec) {
		// 	cout << x << endl;
		// }
		if (n == 1) {
			cout << 1 << endl;
		} else if ((n & 1) == 0) {
			ll ans = 0;
			for (int i = 1; i <= n; i += 2) {
				ans = max(ans, vec[i + 1] - vec[i]);
			}
			cout << ans << endl;
		} else {
			ll ans = INT64_MAX;
			for (int i = 1; i <= n; i += 2) {
				ll res = 0;
				for (int j = 1; j <= n; j++) {
					if (i == j)
						continue;
					res = max(res, vec[j + 1] - vec[j]);
					j++;
				}

				ans = min(ans, res);
			}
			cout << ans << endl;
		}
	}

	return 0;
}
