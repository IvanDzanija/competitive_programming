// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
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
void solve(void) {
	ll n, m, d;
	cin >> n >> m >> d;
	vector<ll> pos(1, 1);
	ll useful = 0;
	ll useless = 0;
	for (ll i = 1; i <= m; ++i) {
		ll x;
		cin >> x;
		if (x == 1) {
			++useful;
			continue;
		}
		pos.push_back(x);
	}
	pos.push_back(n + 1);
	m = pos.size() - 2;
	ll ind = -1;
	for (ll i = 1; i <= m; ++i) {
		ll left = pos[i] - pos[i - 1] - 1;
		ll right = pos[i + 1] - pos[i] - 1;
		ll before = left / d + right / d;
		ll after = (pos[i + 1] - pos[i - 1] - 1);
		after /= d;
		if (before < after) {
			++useful;
		} else {
			++useless;
			ind = i;
		}
	}
	ll ans = 0;
	ll last = 1;
	pos.pop_back();
	m = pos.size();
	for (ll i = 0; i < m; ++i) {
		if (ind == i) {
			continue;
		}
		ans += (pos[i] - last - 1) / d + 1;
		last = pos[i];
	}
	ans += (n - last) / d;
	if (useless > 0) {
		cout << ans << ' ' << useless << endl;
	} else {
		cout << ans << ' ' << useful << endl;
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
