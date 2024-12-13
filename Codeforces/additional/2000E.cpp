#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

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
		ll n, m, k;
		cin >> n >> m >> k;
		ll w;
		cin >> w;
		vector<ll> a(w, 0);
		for (ll i = 0; i < w; ++i) {
			cin >> a[i];
		}
		if (n < m) {
			swap(n, m);
		}
		ll ans = 0;
		sort(all(a));
		vector<int> mp(n * m, 0);
		for (ll r = 0; r + k <= n; ++r) {
			for (ll c = 0; c + k <= m; ++c) {
				for (ll dr = 0; dr < k; ++dr) {
					for (ll dc = 0; dc < k; ++dc) {
						ll rr = r + dr;
						ll cc = c + dc;
						if (rr < n && cc < m) {
							ll curr = rr * m + cc;
							++mp[curr];
						}
					}
				}
			}
		}
		sort(all(mp), greater<>());
		ll pos = a.size() - 1;
		for (ll i = 0; i < w; ++i) {
			ans += (a[pos--] * mp[i]);
		}

		cout << ans << endl;
	}
	return 0;
}
