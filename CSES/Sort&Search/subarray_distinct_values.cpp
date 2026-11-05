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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n, 0);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}
	map<ll, ll> m;
	ll lo = 0, hi = 0, ans = 0, dist = 0;
	while (hi < n) {
		if (m.find(a[hi]) == m.end() || m[a[hi]] == 0) {
			++dist;
		}
		if (m.find(a[hi]) == m.end()) {
			m.emplace(make_pair(a[hi], 1));
		} else {
			++m[a[hi]];
		}
		while (dist > k) {
			--m[a[lo]];
			if (m[a[lo]] == 0) {
				--dist;
			}
			++lo;
		}
		ans += hi - lo + 1;
		+hi;
	}
	cout << ans << endl;
	return 0;
}
