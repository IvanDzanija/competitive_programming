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
	vector<pair<ll, ll>> dp(1 << n, make_pair(0, 0));
	dp[0] = make_pair(1, 0);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (ll i = 1; i < (1 << n); ++i) {
		dp[i] = make_pair(n + 1, 0);
		for (ll j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				auto pr = dp[i ^ (1 << j)];
				if (pr.second + a[j] <= k) {
					pr.second += a[j];
				} else {
					++pr.first;
					pr.second = a[j];
				}
				dp[i] = min(pr, dp[i]);
			}
		}
	}
	cout << dp[(1 << n) - 1].first << endl;

	return 0;
}
