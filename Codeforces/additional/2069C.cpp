#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (ll)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(998244353)

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

const ll mx = 2e5 - 1;

signed main(void) {
	ll t;
	scanf("%lld", &t);
	int power_of_two[mx] = {1};
	for (ll i = 1; i < mx; ++i) {
		power_of_two[i] = (power_of_two[i - 1] << 1);
		if (power_of_two[i] > MOD) {
			power_of_two[i] -= MOD;
		}
	}
	while (t--) {
		ll ans = 0;
		ll n;
		scanf("%lld", &n);
		int ones[mx];
		int bef_ones[mx];
		ll a = 0;
		int threes[mx];
		int bef_threes[mx];
		ll b = 0;
		int first[mx];
		int db[mx];
		memset(db, 0, mx);
		ll c = 0;
		ll cnt = 0;
		ll last = 0;
		bool slow = true;
		ll x;
		for (ll i = 0; i < n; ++i) {
			scanf("%lld", &x);
			if (x == 1) {
				if (a > 0 && bef_ones[a - 1] == cnt) {
					++db[a - 1];
					slow = false;
					continue;
				}
				ones[a] = i;
				bef_ones[a++] = cnt;
			} else if (x == 2) {
				++cnt;
			} else {
				last = i;
				threes[b] = i;
				bef_threes[b++] = cnt;
				while (c < a) {
					first[c++] = b - 1;
				}
			}
		}
		if (slow) {
			for (ll i = 0; i < a && ones[i] < last && i < c; ++i) {
				ll k = bef_ones[i];
				for (ll j = first[i]; j < b; ++j) {
					ans += (power_of_two[bef_threes[j] - k] - 1);
				}
				if (ans > MOD) {
					ans %= MOD;
				}
			}
		} else {
			for (ll i = 0; i < a && ones[i] < last && i < c; ++i) {
				ll k = bef_ones[i];
				ll j = first[i];
				ll current = power_of_two[bef_threes[j] - k] - 1;
				for (ll j = first[i] + 1; j < b; ++j) {
					current += (power_of_two[bef_threes[j] - k] - 1);
					if (current > MOD) {
						current -= MOD;
					}
				}
				ans += current;
				if (ans > MOD) {
					ans -= MOD;
				}
				if (db[i] > 0) {
					ans += (db[i] * current) % MOD;
				}
			}
		}
		printf("%lld\n", ans);
#ifdef LOCAL
		cout << "--------------------------------------------" << endl;
#endif
	}

#ifdef LOCAL
	cerr << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}
