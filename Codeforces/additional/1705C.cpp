// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma, popcnt")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
void solve(void) {
	ll n, c, q;
	cin >> n >> c >> q;
	string s;
	cin >> s;
	map<pair<ll, ll>, pair<ll, ll>> mp;
	ll rbound = n;
	for (ll i = 0; i < c; ++i) {
		ll l, r;
		cin >> l >> r;
		--l, --r;
		mp[make_pair(rbound, rbound + r - l)] = make_pair(l, r);
		rbound = rbound + r - l + 1;
	}
	for (ll i = 0; i < q; ++i) {
		ll x;
		cin >> x;
		--x;
		if (x < n) {
			cout << s[x] << endl;
		} else {
			bool found = false;
			while (!found) {
				auto it = mp.upper_bound(make_pair(x, LLONG_MAX));
				assert(it != mp.begin());
				it = prev(it);
				auto check = it->second;
				ll dist = x - it->first.first;
				x = check.first + dist;
				if (x < n) {
					cout << s[x] << endl;
					found = true;
				}
			}
		}
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
