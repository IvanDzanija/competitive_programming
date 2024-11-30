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
ll n, m;
int dp[1001][1 << 10];
ll ans = 0;
void fill(int c, int ind, int cmask, int nmask) {
	if (ind == n) {
		dp[c + 1][nmask] += dp[c][cmask];
		dp[c + 1][nmask] %= MOD;
		return;
	}
	if ((cmask) & (1 << ind)) {
		fill(c, ind + 1, cmask, nmask);
	} else {
		fill(c, ind + 1, cmask, nmask | (1 << ind));
		if (ind + 1 < n && !(cmask & (1 << (ind + 1)))) {
			fill(c, ind + 2, cmask, nmask);
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			if (dp[i][j] > 0) {
				fill(i, 0, j, 0);
			}
		}
	}
	cout << dp[m][0] << endl;

	return 0;
}
