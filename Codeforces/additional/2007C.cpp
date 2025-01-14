#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unistd.h>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
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

void solve() {
	int n;
	ll a, b;
	cin >> n >> a >> b;
	a = gcd(a, b);
	multiset<ll> c;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		c.insert(x);
	}
	ll ans = *prev(c.end()) - *c.begin();
	ll t = *prev(c.end());
	for (int i = 0; i < n; ++i) {
		ll low = *c.begin();
		ll curr = t - low;
		ll q = curr / a;
		low += (q * a);
		c.erase(c.begin());
		c.insert(low);
		ans = min(*prev(c.end()) - *c.begin(), ans);
	}
	for (int i = 0; i < n; ++i) {
		ll low = *c.begin();
		ll high = *prev(c.end());
		ll curr = high - low;
		ll q = curr / a;
		low += (q * a);
		curr = high - low;
		if (low <= high && low >= *next(c.begin())) {
			ans = min(high - *next(c.begin()), ans);
		}
		if (low + a - high < curr) {
			low += a;
		}
		c.erase(c.begin());
		c.insert(low);
		ans = min(*prev(c.end()) - *c.begin(), ans);
	}

	cout << ans << endl;

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
	cerr << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}
