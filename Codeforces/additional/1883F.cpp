// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <bits/stdc++.h>
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
	ll n;
	cin >> n;
	ll ans = n * (n + 1) / 2;
	map<ll, vector<ll>> mp;
	vector<ll> left;
	vector<ll> vec(n, 0);
	for (ll i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		vec[i - 1] = x;
		mp[x].push_back(i);
		if (mp[x].size() > 1) {
			ans -= (n - i);
			left.push_back(i);
		}
	}
	map<ll, ll> prev;
	for (ll i = 1; i <= n; ++i) {
		ll x = vec[i - 1];
		if (prev.count(x)) {
			auto it = lower_bound(all(left), prev[x]);
			ans -= (prev[x] - 1 - distance(left.begin(), it));
		}
		prev[x] = i;
	}
	for (auto x : mp) {
		if (x.second.size() > 1) {
			ans -= x.second.size();
		}
	}
	cout << ans << endl;
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
