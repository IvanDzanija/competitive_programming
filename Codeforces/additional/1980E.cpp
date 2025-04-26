// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma, popcnt")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
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
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m)), b(n, vector<ll>(m));
	set<vector<ll>> rows1, rows2;
	set<vector<ll>> cols1, cols2;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
		vector<ll> curr = a[i];
		sort(all(curr));
		rows1.insert(curr);
	}
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < m; ++j) {
			cin >> b[i][j];
		}
		vector<ll> curr = b[i];
		sort(all(curr));
		rows2.insert(curr);
	}
	if (rows1 != rows2) {
		cout << "NO" << endl;
		return;
	}
	for (ll j = 0; j < m; ++j) {
		vector<ll> curr(n);
		for (ll i = 0; i < n; ++i) {
			curr[i] = a[i][j];
		}
		sort(all(curr));
		cols1.insert(curr);
	}
	for (ll j = 0; j < m; ++j) {
		vector<ll> curr(n);
		for (ll i = 0; i < n; ++i) {
			curr[i] = b[i][j];
		}
		sort(all(curr));
		cols2.insert(curr);
	}
	if (cols2 == cols1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
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
