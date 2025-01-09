#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
const ll INF = LLONG_MAX;
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
ll mul(ll x, ll y) { return (x * y) % MOD; }
ll pow_mod(ll x, int exp) {
	if (exp == 0) {
		return 1ULL;
	}
	if (exp == 1) {
		return x % MOD;
	}
	if (exp & 1) {
		return mul(x, pow_mod(x, exp - 1));
	} else {
		return pow_mod(mul(x, x), exp / 2);
	}
}
void solve() {
	ll n;
	cin >> n;
	vector<int> a(n, 0);
	vector<ll> psum;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		psum.push_back(sum);
	}
	ll res = 0;
	int k = (int)psum.size();
	for (int i = 0; i < n; ++i) {
		res += a[i] * ((psum[k - 1] - psum[i]) % MOD) % MOD;
		res %= MOD;
	}
	cout << res * pow_mod(n * (n - 1) / 2 % MOD, MOD - 2) % MOD << endl;
	return;
}
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
#ifdef LOCAL
		cout << "--------------------------------------------" << endl;
#endif
	}

#ifdef LOCAL
	cerr << endl
		 << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}
