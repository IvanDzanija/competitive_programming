#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <vector>

#define INF (int)1e9

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n, t;
	cin >> n >> t;
	ll ans = 0;
	vector<ll> ts;
	for (int i = 0; i < n; ++i) {
		ll y;
		cin >> y;
		ts.push_back(y);
	}

	ll lo = 1, hi = *min_element(ts.begin(), ts.end()) * t;
	while (lo <= hi) {
		ll mi = (lo + hi) / 2;
		ll rc = 0;
		for (int i = 0; i < n; ++i) {
			rc += (mi / ts[i]);
		}
		if (rc >= t) {
			ans = mi;
			hi = mi - 1;
		} else {
			lo = mi + 1;
		}
	}

	cout << ans << endl;
	return 0;
}
