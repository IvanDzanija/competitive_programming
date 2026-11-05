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
	ll n, k, q;
	cin >> n >> k >> q;
	vector<vector<ll>> a(k, vector<ll>(n));
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < k; ++j) {
			ll x;
			cin >> x;
			if (i > 0) {
				a[j][i] = (a[j][i - 1] | x);
			} else {
				a[j][i] = x;
			}
		}
	}
	while (q--) {
		ll m;
		cin >> m;
		ll lo = 0;
		ll hi = n;
		while (m--) {
			ll x, y;
			char c;
			cin >> x >> c >> y;
			--x;
			if (c == '<') {
				hi = min(hi, ll(lower_bound(all(a[x]), y) - a[x].begin()));
			}

			else {
				lo = max(lo, ll(upper_bound(all(a[x]), y) - a[x].begin()));
			}
		}

		if (lo < hi) {
			cout << lo + 1 << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
