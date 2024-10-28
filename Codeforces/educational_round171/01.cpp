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
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll x, y, z;
		cin >> x >> y >> z;
		bool f = false;
		for (ll i = 0; i <= x && !f; ++i) {
			for (ll j = 0; j <= y && !f; ++j) {
				for (ll k = 0; k <= x && !f; ++k) {
					for (ll l = 0; l <= y && !f; ++l) {
						if (k == i && l == j) {
							continue;
						}
						if (sqrt(pow((i - k), 2) + pow((l - j), 2)) < z) {
							continue;
						} else {
							if (k <= y && l <= x) {
								f = true;
								cout << i << ' ' << j << ' ' << k << ' ' << l
									 << endl;
								cout << i << ' ' << k << ' ' << l << ' ' << j
									 << endl;
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
