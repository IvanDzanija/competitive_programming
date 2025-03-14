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
bool comp(const pair<ll, set<ll>> &a, const pair<ll, set<ll>> &b) {
	return a.second.size() > b.second.size();
}
void solve(void) {
	ll n;
	cin >> n;
	vector<pair<ll, set<ll>>> vec(n);
	for (ll i = 0; i < n; ++i) {
		vec[i].first = i;
	}
	for (ll i = 0; i < n - 1; ++i) {
		ll x, y;
		cin >> x >> y;
		--x, --y;
		vec[x].second.insert(y);
		vec[y].second.insert(x);
	}
	if (n <= 2) {
		cout << 0 << endl;
		return;
	}
	sort(all(vec), comp);
	if (vec[0].second.count(vec[1].first)) {
		if (vec[0].second.size() == vec[1].second.size()) {
			ll s = vec[0].second.size();
			for (ll i = 0; i < n && vec[i].second.size() == s; ++i) {
				for (ll j = i + 1; j < n && vec[j].second.size() == s; ++j) {
					if (!vec[i].second.count(vec[j].first)) {
						cout << vec[i].second.size() + vec[j].second.size() - 1
							 << endl;
						return;
					}
				}
			}
		} else {
			for (ll i = 1;
				 i < n && vec[i].second.size() == vec[1].second.size(); ++i) {
				if (!vec[0].second.count(vec[i].first)) {
					cout << vec[0].second.size() + vec[i].second.size() - 1
						 << endl;
					return;
				}
			}
		}
	} else {
		cout << vec[0].second.size() + vec[1].second.size() - 1 << endl;
		return;
	}
	cout << vec[0].second.size() + vec[1].second.size() - 2 << endl;

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
