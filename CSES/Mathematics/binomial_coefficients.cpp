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
const ll maxN = 1e6 + 5;
ll factorial[maxN];
void precalc_factorial(void) {
	factorial[0] = 1;
	for (ll i = 1; i < maxN; ++i) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
}
inline ll pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}
	ll res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}

	return res;
}
inline ll mod_inv(ll a) { return pow(a, MOD - 2); }
void solve(void) {
	ll a, b;
	cin >> a >> b;
	cout << factorial[a] * mod_inv(factorial[b]) % MOD *
				mod_inv(factorial[a - b]) % MOD
		 << endl;
	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll tc = 1;
	cin >> tc;
	precalc_factorial();
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
