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
int count_bits(ll number) { return (int)log2(number) + 1; }
bool comp(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> a;
	for (ll i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		a.push_back(make_pair(x, y));
	}
	sort(all(a), comp);
	multiset<ll> s;

	ll ans = 0;
	for (ll i = 0; i < n; ++i) {
		if (s.size() > 0) {
			auto it = s.upper_bound(a[i].first);
			if (it != s.begin()) {
				s.erase(prev(it));
			}
		}
		if (s.size() < k) {
			s.insert(a[i].second);
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
