#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <set>

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
	multiset<ll> list;
	vector<ll> saved(n, 0);
	for (ll i = 0; i < n; ++i) {
		cin >> saved[i];
		list.insert(saved[i]);
	}
	if (n < 3) {
		cout << "IMPOSSIBLE" << endl;

	} else {
		auto hold = list.upper_bound(x);
		bool flag = false;
		auto it = list.begin();
		vector<ll> values;
		while (!flag) {
			if (it == hold) {
				flag = true;
			}
			auto lo = next(it);
			auto hi = prev(list.upper_bound(x - *lo - *it));
			// cout << *lo << " " << *hi << endl;
			while (!(hi == lo || *hi < *lo)) {
				// cout << *it << ' ' << *lo << " " << *hi << endl;
				if (*it + *lo + *hi == x) {
					// cout << *lo << " " << *hi << ' ' << *it << endl;
					flag = true;
					values.push_back(*it);
					values.push_back(*lo);
					values.push_back(*hi);
					lo = hi;
				} else if (*it + *lo + *hi > x) {
					hi = prev(hi);
				} else {
					lo = next(lo);
				}
			}
			it = next(it);
		}
		if (values.size() == 0) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			for (ll i = 0; i < n; ++i) {
				for (int j = 0; j < values.size(); ++j) {
					if (values[j] == saved[i]) {
						cout << i + 1 << ' ';
						values.erase(values.begin() + j);
						break;
					}
				}
			}
			cout << endl;
		}
	}

	return 0;
}
