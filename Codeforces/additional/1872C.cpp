// #pragma GCC optimization("Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
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
const ll maxN = 1e7 + 5;
vector<ll> sieve(maxN, -1);

void precalc_sieve(void) {

	for (int p = 2; p * p <= maxN; p++) {

		if (sieve[p] == -1) {

			for (int i = p * p; i <= maxN; i += p)
				if (sieve[i] == -1) {
					sieve[i] = p;
				}
		}
	}
}
inline ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }
void solve(void) {
	ll l, r;
	cin >> l >> r;
	if (r <= 3) {
		cout << -1 << endl;
		return;
	} else if (!(r & 1)) {
		cout << 2 << ' ' << r - 2 << endl;
	} else {
		if (l == r) {
			if (sieve[r] == -1) {
				cout << -1 << endl;
			} else {
				ll x = r / sieve[r];
				cout << sieve[r] * ceil_div(x, 2) << ' ' << x / 2 * sieve[r]
					 << endl;
			}

		} else {
			cout << 2 << ' ' << r - 3 << endl;
		}
	}
	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll tc = 1;
	cin >> tc;
	precalc_sieve();
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
