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
	ll a, b;
	cin >> a >> b;
	ll dp[a + 1][b + 1];
	for (ll i = 1; i <= a; ++i) {
		for (ll j = 1; j <= b; ++j) {
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = INF;
		}
	}
	for (ll i = 1; i <= a; ++i) {
		for (ll j = 1; j <= b; ++j) {
			for (ll k = 1; k < i; ++k) {
				dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
			}
			for (ll k = 1; k < j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
			}
		}
	}
	cout << dp[a][b] << endl;
	return 0;
}
