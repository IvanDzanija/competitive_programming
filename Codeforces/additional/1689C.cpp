// #pragma GCC optimization("Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,fmi,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define INF (ll)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;
struct custom_hash {
	static ull splitmix64(ull x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(ull x) const {
		static const ull FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
vector<ll> dp(3e5 + 5), sub(3e5 + 5);
void dfs(vector<vector<ll>> &tr, ll s, ll e) {
	dp[s] = 0, sub[s] = 1;
	ll cnt = 0;
	for (auto x : tr[s]) {
		if (x == e) {
			continue;
		}
		dfs(tr, x, s);
		sub[s] += sub[x];
		cnt += dp[x];
	}
	for (auto x : tr[s]) {
		if (x == e) {
			continue;
		}
		dp[s] = max(dp[s], cnt - dp[x] + sub[x] - 1);
	}
	return;
}
void solve(void) {
	ll n;
	cin >> n;
	vector<vector<ll>> tr(n);
	for (ll i = 0; i < n - 1; ++i) {
		ll x, y;
		cin >> x >> y;
		--x, --y;
		tr[x].push_back(y);
		tr[y].push_back(x);
	}
	dfs(tr, 0, -1);

	if (tr[0].size() == 1) {
		cout << sub[tr[0][0]] - 1 << endl;
	} else {
		cout << dp[0] << endl;
	}

	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
#ifdef LOCAL
		cout << "--------------------------------------------" << endl;
#endif
	}

#ifdef LOCAL
	cerr << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}
