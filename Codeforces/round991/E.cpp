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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		string a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, INF));
		dp[0][0] = 0;
		for (ll i = 0; i < a.size(); ++i) {
			dp[i + 1][0] = dp[i][0] + (a[i] != c[i]);
		}
		for (ll i = 0; i < b.size(); ++i) {
			dp[0][i + 1] = dp[0][i] + (b[i] != c[i]);
		}
		// for (auto x : dp) {
		// 	for (auto y : x) {
		// 		cout << y << ' ';
		// 	}
		// 	cout << endl;
		// }
		for (int i = 1; i <= a.size(); ++i) {
			for (int j = 1; j <= b.size(); ++j) {
				int pos = i + j - 1;
				int c1 = dp[i][j - 1] + (b[j - 1] != c[pos]);
				int c2 = dp[i - 1][j] + (a[i - 1] != c[pos]);
				dp[i][j] = min(c1, c2);
			}
		}
		cout << dp[a.size()][b.size()] << endl;
	}
	return 0;
}
