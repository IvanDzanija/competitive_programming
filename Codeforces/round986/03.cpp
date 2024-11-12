#include <algorithm>
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
		int n, m, v;
		cin >> n >> m >> v;
		vector<int> a(n, 0);
		vector<ll> ldp(n + 1, 0), rdp(n + 1, 0);
		vector<ll> rps(n + 1, 0), lps(n + 1, 0);
		ll c = 0;
		ll total = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			c += a[i];
			total += a[i];
			ldp[i + 1] = ldp[i];
			lps[i + 1] = lps[i] + a[i];
			if (c >= v) {
				++ldp[i + 1];
				c = 0;
			}
		}
		c = 0;
		for (int i = n - 1; i >= 0; --i) {
			c += a[i];
			rdp[i] = rdp[i + 1];
			rps[i] = rps[i + 1] + a[i];
			if (c >= v) {
				++rdp[i];
				c = 0;
			}
		}
		// for (auto x : ldp) {
		// 	cout << x << ' ';
		// }
		// cout << endl;
		// for (auto x : rdp) {
		// 	cout << x << ' ';
		// }
		// cout << endl;
		// for (auto x : rps) {
		// 	cout << x << ' ';
		// }
		// cout << endl;
		// for (auto x : lps) {
		// 	cout << x << ' ';
		// }
		// cout << endl;
		ll ans = -1;
		for (ll i = n; i >= 0; --i) {
			ll cur = rdp[i];
			if (cur <= m) {
				ll x = lower_bound(all(ldp), m - cur) - ldp.begin();
				// cout << cur << ' ' << x << endl;
				if (x > i) {
					continue;
				} else {
					ll j = rps[i], k = lps[x], l = total - j - k;
					ans = max(ans, l);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
