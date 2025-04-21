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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n, 0);
	ll max = 0;
	ll sum = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > max) {
			max = a[i];
		}
		sum += a[i];
	}
	ll lo = max;
	ll hi = sum;
	ll ans = 0;
	while (hi >= lo) {
		ll mid = (hi + lo) / 2;
		ll r = k;
		ll z = 0;
		for (ll i = 0; i < n && r > 0; ++i) {
			if (mid == 7) {
			}
			if (a[i] + z <= mid) {
				z += a[i];
			} else if (a[i] + z > mid && r > 0) {
				z = a[i];
				--r;
			}
		}
		if (r > 0) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << ans << endl;

	return 0;
}
