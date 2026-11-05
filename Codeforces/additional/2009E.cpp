#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <limits>

#define INF (ll)1e18 + 9
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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll total = (2 * k + n - 1) * n / 2;
		ll r = n;

		ll mid_ind = (k + n - 1 + k) / 2 + 1;
		ll midi = (k + mid_ind) * (mid_ind - (k - 1)) / 2;
		ll ans = abs(midi - (total - midi));

		ll low = 0;
		ll high = mid_ind;
		while (low + 1 < high) {
			// cout << low << ' ' << high << endl;
			ll mid = (low + high) / 2;
			ll sum = (k + mid) * (mid - (k - 1)) / 2;
			ll curr = sum - (total - sum);
			// cout << mid << ' ' << sum << ' ' << curr << endl;
			if (curr < 0) {
				low = mid;
			} else {
				high = mid;
			}
			ans = min(ans, abs(curr));
		}
		low = mid_ind;
		high = k + n - 1;
		while (low + 1 < high) {
			ll mid = (low + high) / 2;
			ll sum = (k + mid) * (mid - (k - 1)) / 2;
			ll curr = sum - (total - sum);
			if (curr < 0) {
				low = mid;
			} else {
				high = mid;
			}
			ans = min(ans, abs(curr));
		}

		cout << ans << endl;
	}
	return 0;
}
