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
	ll n, t;
	cin >> n >> t;
	int coins[n];
	for (ll i = 0; i < n; ++i) {
		cin >> coins[i];
	}
	vector<ll> dp(t + 1, 0);
	dp[0] = 1;
	for (ll j = 0; j < n; ++j) {
		for (ll i = 1; i <= t; ++i) {
			if (coins[j] > i) {
				continue;
			}
			dp[i] += dp[i - coins[j]];
			dp[i] %= MOD;
		}
	}
	cout << dp[t] << endl;

	return 0;
}
