#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	for (ll id = 0; id < t; ++id) {
		ll n;
		cin >> n;
		ll maxX = 0, maxY = 0;
		for (int i = 0; i < n; ++i) {
			ll x, y;
			cin >> x >> y;
			if (x > maxX)
				maxX = x;
			if (y > maxY)
				maxY = y;
		}
		cout << 2 * maxX + 2 * maxY << endl;
	}

	return 0;
}
