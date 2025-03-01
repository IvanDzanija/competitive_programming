// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> vec(n, 0);
	for (ll i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	if (k >= 3) {
		cout << 0 << endl;
	} else if (k == 1) {
		ll ans = LLONG_MAX;
		for (ll i = 0; i < n; ++i) {
			ans = min(ans, vec[i]);
			for (ll j = i + 1; j < n; ++j) {
				ans = min(ans, abs(vec[i] - vec[j]));
			}
		}
		cout << ans << endl;
	} else if (k == 2) {
		ll ans = LLONG_MAX;
		sort(all(vec));
		for (ll i = 0; i < n; ++i) {
			ans = min(ans, vec[i]);
			for (ll j = i + 1; j < n; ++j) {
				ll curr = abs(vec[i] - vec[j]);
				ans = min(ans, curr);
				auto it = lower_bound(all(vec), curr);
				if (it != vec.end()) {
					ans = min(ans, abs(curr - *it));
				}
				if (it != vec.begin()) {
					ans = min(ans, abs(curr - *prev(it)));
				}
			}
		}
		cout << ans << endl;
	}

	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll tc = 1;
	cin >> tc;
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
