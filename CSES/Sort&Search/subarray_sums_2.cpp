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
	vector<ll> num(n, 0);
	vector<ll> vec(n + 1, 0);
	vec[0] = x;
	for (ll i = 0; i < n; ++i) {
		cin >> num[i];
		vec[i + 1] = vec[i] + num[i];
	}

	ll ans = 0;
	map<ll, ll> vis;
	for (ll i = 0; i <= n; ++i) {
		if (vis.count(vec[i] - x)) {
			ans += vis[vec[i] - x];
		}
		if (vis.count(vec[i])) {
			++vis[vec[i]];
		} else {
			vis[vec[i]] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
