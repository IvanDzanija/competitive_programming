// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
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
ll cnt = 0;
void solve() {
	ll n, q;
	cin >> n >> q;
	deque<pair<ll, ll>> dq;
	vector<vector<ll>> ans(n + 1);
	ll mx = 0;
	ll mxi;
	for (ll i = 1; i <= n; ++i) {
		ll x;
		cin >> x;
		if (x > mx) {
			mx = x;
			mxi = i;
		}
		dq.push_back(make_pair(x, i));
	}
	ll round = 0;
	while (true) {
		pair<ll, ll> first = dq.front();
		dq.pop_front();
		pair<ll, ll> second = dq.front();
		dq.pop_front();
		if (first.first == mx || second.first == mx) {
			break;
		}
		++round;
		if (first.first > second.first) {
			dq.push_front(first);
			dq.push_back(second);
			ans[first.second].push_back(round);
		} else {
			dq.push_front(second);
			dq.push_back(first);
			ans[second.second].push_back(round);
		}
	}
	for (ll i = 0; i < q; ++i) {
		ll x, k;
		cin >> x >> k;
		if (k > round) {
			if (x == mxi) {
				cout << k - round << endl;
			} else {
				cout << ans[x].size() << endl;
			}
		} else {
			auto it = upper_bound(all(ans[x]), k);
			cout << distance(ans[x].begin(), it) << endl;
		}
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
