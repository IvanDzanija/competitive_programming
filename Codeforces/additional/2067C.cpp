// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
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
inline int count_digits(ll num) {
	if (num < 10)
		return 1;
	if (num < 100)
		return 2;
	if (num < 1000)
		return 3;
	if (num < 10000)
		return 4;
	if (num < 100000)
		return 5;
	if (num < 1000000)
		return 6;
	if (num < 10000000)
		return 7;
	if (num < 100000000)
		return 8;
	if (num < 1000000000)
		return 9;
	if (num < 10000000000)
		return 10;
	if (num < 100000000000)
		return 11;
	if (num < 1000000000000)
		return 12;
	if (num < 10000000000000)
		return 13;
	if (num < 100000000000000)
		return 14;
	if (num < 1000000000000000)
		return 15;
	if (num < 10000000000000000)
		return 16;
	if (num < 100000000000000000)
		return 17;
	if (num < 1000000000000000000)
		return 18;
	if (num < 10000000000000000000ULL)
		return 19;

	return 20;
}

void solve() {
	ll n;
	cin >> n;
	ll ans = INF;
	queue<tuple<ll, ll, ll>> q;
	q.push(make_tuple(n, 0, 0));
	set<ll> seen;
	while (!q.empty()) {
		auto [l, d, z] = q.front();
		q.pop();
		if (seen.count(l)) {
			continue;
		}
		seen.insert(l);
		ll dig = count_digits(l);
		ll k = l;
		for (ll i = 0; i < dig; ++i) {
			if (k % 10 == 7) {
				cout << d << endl;
				return;
			}
			k /= 10;
		}
		if (z == 0) {
			ll t = 9;
			for (ll i = 1; i <= dig; ++i) {
				q.push(make_tuple(t + l, d + 1, i));
				t *= 10;
				t += 9;
			}
		} else {
			ll t = 9;
			for (ll i = 1; i < z; ++i) {
				t *= 10;
				t += 9;
			}
			q.push(make_tuple(t + l, d + 1, z));
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
