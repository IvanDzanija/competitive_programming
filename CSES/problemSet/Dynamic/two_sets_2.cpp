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
	ll n;
	cin >> n;
	ll t = n * (n + 1) / 2;
	if (t & 1) {
		cout << 0 << endl;
	} else {
		t /= 2;
		vector<vector<ll>> dp(n, vector<ll>(t + 1, 0));
		dp[0][0] = 1;
		for (ll i = 1; i < n; ++i) {
			for (ll j = 0; j <= t; ++j) {
				dp[i][j] = dp[i - 1][j];
				ll l = j - i;
				if (l >= 0) {
					dp[i][j] += dp[i - 1][l];
					dp[i][j] %= MOD;
				}
			}
		}
		cout << dp[n - 1][t] << endl;
	}
	return 0;
}
