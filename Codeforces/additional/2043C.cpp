// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
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
void solve(void) {
	ll n;
	cin >> n;
	vector<ll> before;
	vector<ll> after;
	vector<ll> vec(n, 0);
	ll r = 0;
	bool bef = true;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		vec[i] = x;
		if (x == 0) {
			continue;
		}
		if (x != 1 && x != -1) {
			bef = false;
			r = x;
			continue;
		}
		if (bef) {
			before.push_back(x);
		} else {
			after.push_back(x);
		}
	}
	ll blow = 0, bhigh = 0;
	ll c = 0, d = 0;
	for (ll i = 0; i < (int)before.size(); ++i) {
		c += before[i];
		d += before[i];
		bhigh = max(bhigh, c);
		blow = min(blow, d);
		c = max(0ll, c);
		d = min(0ll, d);
	}
	if (bef) {
		cout << bhigh - blow + 1 << endl;
		for (ll i = blow; i <= bhigh; ++i) {
			cout << i << ' ';
		}
		cout << endl;
	} else {
		ll alow = 0, ahigh = 0;
		ll e = 0, f = 0;
		for (ll i = 0; i < (int)after.size(); ++i) {
			e += after[i];
			f += after[i];
			ahigh = max(ahigh, e);
			alow = min(alow, f);
			e = max(0ll, e);
			f = min(0ll, f);
		}
		set<ll> ans;
		for (ll i = blow; i <= bhigh; ++i) {
			ans.insert(i);
		}
		for (ll i = alow; i <= ahigh; ++i) {
			ans.insert(i);
		}
		ll lares = 0, hares = 0;
		ll a = 0;
		for (ll i = 0; i < (int)after.size(); ++i) {
			a += after[i];
			hares = max(hares, a);
			lares = min(lares, a);
		}
		a = 0;
		ll lbres = 0, hbres = 0;
		if (!before.empty()) {
			for (ll i = (int)before.size() - 1; i >= 0; --i) {
				a += before[i];
				hbres = max(hbres, a);
				lbres = min(lbres, a);
			}
		}
		for (ll i = lares + lbres; i <= hbres + hares; ++i) {
			ans.insert(i + r);
		}

		cout << ans.size() << endl;
		for (auto x : ans) {
			cout << x << ' ';
		}
		cout << endl;
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
