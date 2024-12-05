#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;
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
bool comp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
	if (a.first.first == b.first.first) {
		return a.first.second > b.first.second;
	}
	return a.first.first < b.first.first;
}
bool comp1(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
	if (a.first.second == b.first.second) {
		return a.first.first < b.first.first;
	}
	return a.first.second > b.first.second;
}
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<pair<pair<ll, ll>, ll>> a;
		set<pair<ll, ll>> dups;
		for (ll i = 0; i < n; ++i) {
			ll x, y;
			cin >> x >> y;
			a.push_back(make_pair(make_pair(x, y), i));
		}
		sort(all(a), comp);
		set<ll> right;
		vector<ll> ans(n, 0);

		for (int i = 0; i < n; ++i) {
			auto x = a[i];
			ll l = x.first.first, r = x.first.second, pos = x.second;
			auto key = make_pair(l, r);
			if (dups.count(key)) {
				ans[a[i - 1].second] = 0;
				continue;
			}
			dups.insert(key);
			auto it = right.lower_bound(r);
			right.insert(r);
			if (it != right.end()) {
				ans[pos] += *it - r;
			}
		}
		dups.clear();
		sort(all(a), comp1);
		set<ll> left;
		for (int i = 0; i < n; ++i) {
			auto x = a[i];
			ll l = x.first.first, r = x.first.second, pos = x.second;
			auto key = make_pair(l, r);
			if (dups.count(key)) {
				ans[a[i - 1].second] = 0;
				continue;
			}
			dups.insert(key);
			auto it = left.lower_bound(-l);
			left.insert(-l);
			if (it != left.end()) {
				ans[pos] += l + *it;
			}
		}
		for (auto x : ans) {
			cout << x << endl;
		}
	}
	return 0;
}
