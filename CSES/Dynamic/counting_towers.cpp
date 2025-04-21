#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(1e9 + 7)

using ll = int64_t;
using ull = uint64_t;
using ld = long double;
const ll MAX = 1e6 + 6;
ll dp[MAX][2];
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;
int count_bits(ll number) { return (int)log2(number) + 1; }
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;

	dp[0][0] = 1;
	dp[0][1] = 1;
	for (ll i = 1; i < MAX; ++i) {
		dp[i][0] = (dp[i - 1][0] * 2 % MOD + dp[i - 1][1]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 4 % MOD) % MOD;
	}
	while (t--) {
		ll n;
		cin >> n;
		cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
	}

	return 0;
}
