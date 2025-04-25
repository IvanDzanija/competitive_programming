// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma, popcnt")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF (int)1e9 + 1
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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	vector<ll> prefix(m, INF), suffix(m, -1);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (ll i = 0; i < m; ++i) {
		cin >> b[i];
	}
	ll ind = 0;
	for (ll i = 0; i < n; ++i) {
		if (a[i] >= b[ind]) {
			prefix[ind] = i;
			++ind;
		}
		if (ind == m) {
			break;
		}
	}
	ind = m - 1;
	for (ll i = n - 1; i >= 0; --i) {
		if (a[i] >= b[ind]) {
			suffix[ind] = i;
			--ind;
		}
		if (ind == -1) {
			break;
		}
	}
	if (prefix[m - 1] < INF || suffix[0] > -1) {
		cout << 0 << endl;
		return;
	}
	if (m == 1) {
		cout << b[0] << endl;
		return;
	}

	ll ans = INF;
	if (suffix[1] > -1) {
		ans = min(ans, b[0]);
	}
	if (prefix[m - 2] <= n) {
		ans = min(ans, b[m - 1]);
	}
	for (ll i = 1; i < m - 1; ++i) {
		if (prefix[i - 1] < suffix[i + 1]) {
			ans = min(ans, b[i]);
		}
	}
	cout << ((ans == INF) ? -1 : ans) << endl;

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
