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
bool comp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
	if (a.first.second == b.first.second) {
		return a.second < b.second;
	}
	return a.first.second < b.first.second;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n;
	cin >> n;
	ll m = 0;
	vector<pair<pair<ll, ll>, ll>> a;
	for (ll i = 0; i < n; ++i) {
		ll x, y, z;
		cin >> x >> y >> z;
		if (y > m) {
			m = y;
		}
		a.push_back(make_pair(make_pair(x, y), z));
	}
	sort(all(a), comp);
	ll ans = 0;
	map<ll, ll> dp;
	dp[0] = 0;
	ll p = 0;
	for (auto x : a) {
		auto it = prev(dp.lower_bound(x.first.first));
		ll z = (*it).second + x.second;
		if (z > ans) {
			ans = z;
		}
		dp[x.first.second] = p;
		dp[x.first.second] = max(z, dp[x.first.second]);
		p = dp[x.first.second];
	}
	// for (auto x : dp) {
	// 	cout << x.first << ' ' << x.second << endl;
	// }
	cout << ans << endl;

	return 0;
}
