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
	vector<ll> a;
	ll total = 0;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		total += x;
		a.push_back(x);
	}
	ll dp[n][n];
	dp[n - 1][n - 1] = a[n - 1];
	for (ll i = n - 1; i >= 0; i--) {
		dp[i][i] = a[i];
		for (ll j = i + 1; j < n; ++j) {
			dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
		}
	}
	cout << (total + dp[0][n - 1]) / 2 << endl;

	return 0;
}
