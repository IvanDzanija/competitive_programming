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
using indexed_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag,
							  tree_order_statistics_node_update>;
int count_bits(ll number) { return (int)log2(number) + 1; }
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	multiset<int> l, r;
	ll s1 = 0, s2 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i >= k) {
			if (l.find(a[i - k]) != l.end()) {
				l.erase(l.find(a[i - k]));
				s1 = s1 - a[i - k];
			} else {
				r.erase(r.find(a[i - k]));
				s2 = s2 - a[i - k];
			}
		}
		ll sz1 = l.size(), sz2 = r.size();
		if (sz1 <= sz2) {
			l.insert(a[i]);
			s1 = s1 + a[i];
		} else {
			r.insert(a[i]);
			s2 = s2 + a[i];
		}
		sz1 = l.size(), sz2 = r.size();
		if (sz1 > 0 && sz2 > 0) {
			auto it1 = prev(l.end());
			auto it2 = r.begin();
			if (*it1 > *it2) {
				s1 += (*it2 - *it1);
				s2 += (*it1 - *it2);
				l.insert(*it2);
				r.insert(*it1);
				l.erase(it1);
				r.erase(it2);
			}
		}
		if (i >= (k - 1)) {
			ll med = *prev(l.end());
			cout << (med * sz1 - s1) + (s2 - med * sz2) << ' ';
		}
	}
	cout << endl;
	return 0;
}
