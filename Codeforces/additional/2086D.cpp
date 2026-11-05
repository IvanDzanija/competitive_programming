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
inline int ceil2(int a, int b) { return (a + b - 1) / b; }

inline long long mul(long long a, long long b) { return (a * b) % MOD; }

// Exponantiation by squaring
inline long long pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	long long res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

// Modular inverse for prime modulus
inline long long mod_inv(long long num) { return pow(num, MOD - 2); }

inline long long fact(ll a) {
	ll res = 1;
	for (ll i = 2; i <= a; ++i) {
		res = mul(res, i);
	}
	return res;
}

const ll maxN = 5e5 + 5;
ll factorial[maxN];
void precalc_factorial(void) {
	factorial[0] = 1;
	for (ll i = 1; i < maxN; i++) {
		factorial[i] = mul(factorial[i - 1], i);
	}
}

void solve(void) {
	int n = 26;
	vector<ll> vec(n, 0);

	ll len = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> vec[i];
		len += vec[i];
	}
	ll odd = ceil2(len, 2);
	vector<ll> dp(len + 1, 0);
	dp[0] = 1;
	for (ll i = 0; i < n; ++i) {
		ll curr = vec[i];
		if (curr == 0) {
			continue;
		}
		for (ll j = len; j >= 0; --j) {
			if (j + curr <= len) {
				dp[j + curr] += dp[j];
				dp[j + curr] %= MOD;
			}
		}
	}
	ll perm = mul(factorial[odd], factorial[len - odd]);
	for (ll i = 0; i < n; ++i) {
		if (vec[i] < 1) {
			continue;
		}
		perm = mul(perm, mod_inv(factorial[vec[i]]));
	}

	cout << mul(perm, dp[odd]) << endl;

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
