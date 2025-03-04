#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<ll, ll>> rg;
	for (ll i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		rg.push_back(make_pair(x, y));
	}
	sort(rg.begin(), rg.end());
	ll ans = 0;
	ll t = 0;
	for (auto x : rg) {
		t += x.first;
		ans += (x.second - t);
	}
	cout << ans << endl;

	return 0;
}
