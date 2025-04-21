#include <algorithm>
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
	ll n, x;
	cin >> n >> x;
	vector<pair<ll, ll>> a;
	for (ll i = 0; i < n; ++i) {
		ll z;
		cin >> z;
		a.push_back(make_pair(z, i + 1));
	}
	sort(all(a));
	int pos = 0;
	for (ll i = 0; i < n - 3 && pos == 0; ++i) {
		for (ll j = i + 1; j < n - 2 && pos == 0; ++j) {
			ll lo = j + 1;
			ll hi = n - 1;
			while (lo < hi && pos == 0) {
				ll sum = a[i].first + a[j].first + a[lo].first + a[hi].first;
				if (sum == x) {
					pos = 1;
					cout << a[i].second << ' ' << a[j].second << ' '
						 << a[lo].second << ' ' << a[hi].second << endl;
				} else if (sum < x) {
					++lo;
				} else {
					--hi;
				}
			}
		}
	}
	if (pos == 0) {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
