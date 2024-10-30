#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>

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
	ll n;
	cin >> n;
	vector<int> coins(n, 0);
	for (ll i = 0; i < n; ++i) {
		cin >> coins[i];
	}
	sort(all(coins));
	// set<ll> sums;

	// for (ll i = 0; i < n; ++i) {
	// 	ll curr = coins[i];
	// 	set<ll> tmp;
	// 	tmp.insert(curr);
	// 	for (auto x : sums) {
	// 		tmp.insert(curr + x);
	// 	}
	// 	sums.merge(tmp);
	// }

	// cout << sums.size() << endl;
	// for (auto x : sums) {
	// 	cout << x << ' ';
	// }
	// cout << endl;

	// DP arr approach
	ll s = accumulate(coins.begin(), coins.end(), 0LL);
	vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
	dp[0][0] = 1;
	for (ll i = 1; i <= n; ++i) {
		ll coin = coins[i - 1];
		for (ll j = 0; j <= s; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j >= coin && dp[i - 1][j - coin]) {
				dp[i][j] = 1;
			}
		}
	}
	ll ans = accumulate(dp[n].begin() + 1, dp[n].end(), 0LL);
	cout << ans << endl;
	for (ll i = 1; i <= s; ++i) {
		if (dp[n][i]) {
			cout << i << ' ';
		}
	}
	cout << endl;

	return 0;
}
