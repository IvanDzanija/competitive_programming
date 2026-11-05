#include <bits/stdc++.h>
#include <climits>
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
	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> ps(n + 1, 0);
	vector<ll> b(n, 0);
	ll ans = LLONG_MIN;
	for (ll i = 0; i < n; ++i) {
		cin >> b[i];
		ps[i + 1] = ps[i] + b[i];
	}
	multiset<ll> s;
	for (ll i = l; i <= r; ++i) {
		s.insert(ps[i]);
	}
	for (ll i = 1; i <= n && !s.empty(); ++i) {
		ll d = ps[i - 1];
		ans = max(ans, *(prev(s.end()))-d);
		s.erase(s.lower_bound(ps[l + i - 1]));
		if (i + r <= n) {
			s.insert(ps[i + r]);
		}
	}
	cout << ans << endl;
	return 0;
}
