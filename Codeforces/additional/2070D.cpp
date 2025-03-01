// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (ll)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(998244353)

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

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> depth(n + 1);
	vector<vector<ll>> t(n + 1);
	for (ll i = 2; i <= n; ++i) {
		ll x;
		cin >> x;
		t[x].push_back(i);
	}
	vector<ll> dp(n + 1, 0), tot(n + 1, 0);
	tot[0] = 1;
	queue<tuple<ll, ll, ll>> q;
	ll max_depth = 0;
	q.push(make_tuple(1, 0, 0));
	while (!q.empty()) {
		auto [node, dist, prev] = q.front();
		q.pop();
		max_depth = max(max_depth, dist);
		if (node == 1) {
			for (auto u : t[node]) {
				q.push(make_tuple(u, 1, node));
			}
		} else {
			for (auto u : t[node]) {
				q.push(make_tuple(u, dist + 1, node));
			}
			dp[node] = (tot[dist - 1] - dp[prev] + MOD) % MOD;
			tot[dist] = (dp[node] + tot[dist]) % MOD;
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= max_depth; ++i) {
		ans = (ans + tot[i]) % MOD;
	}
	cout << ans << endl;
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
