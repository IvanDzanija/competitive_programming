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
	vector<ll> a(n, 0);
	indexed_multiset<ll> s;
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		if (i < k) {
			s.insert(a[i]);
		}
	}

	ll c = 0;
	for (ll i = k; i <= n; ++i) {
		if (k & 1) {
			cout << *s.find_by_order(k / 2) << ' ';
		} else {
			cout << *s.find_by_order(k / 2 - 1) << ' ';
		}
		s.erase(s.upper_bound(a[c]));
		++c;
		s.insert(a[i]);
	}
	cout << endl;

	return 0;
}
