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
	string s1, s2;
	cin >> s1 >> s2;
	ll r = s1.size();
	ll c = s2.size();
	ll dp[r + 1][c + 1];

	for (ll i = 0; i <= r; ++i) {
		dp[i][0] = i;
	}
	for (ll i = 0; i <= c; ++i) {
		dp[0][i] = i;
	}

	for (ll i = 1; i <= r; ++i) {
		for (ll j = 1; j <= c; ++j) {
			ll a = dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1);
			ll b = dp[i - 1][j] + 1;
			ll c = dp[i][j - 1] + 1;
			dp[i][j] = min(min(a, b), c);
		}
	}
	// for (ll i = 0; i <= r; ++i) {
	// 	for (ll j = 0; j <= c; ++j) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	cout << dp[r][c] << endl;
	return 0;
}
