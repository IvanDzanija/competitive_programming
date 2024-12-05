#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
bool comp(pair<pair<ll, ll>, ll> f, pair<pair<ll, ll>, ll> s) {
	if (f.first.first == s.first.first) {
		return f.first.second > s.first.second;
	}
	return f.first.first < s.first.first;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<pair<int, int>, int>> a;
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			a.push_back(make_pair(make_pair(x, y), i));
		}
		vector<int> ans(n, 0);
		sort(all(a), comp);
		indexed_set<int> set;
		for (int i = 0; i < n; ++i) {
			auto curr = a[i].first.second;
			if (set.find(curr) != set.end()) {
				ans[a[i].second] = 0;
				ans[a[i - 1].second] = 0;
				continue;
			}
			set.insert(curr);
			int pos = set.order_of_key(curr);
			if (pos == set.size() - 1) {
				ans[a[i].second] = 0;
				continue;
			} else {
			}
		}
		for (auto x : ans) {
			cout << x << endl;
		}
	}
	return 0;
}
