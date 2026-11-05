// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <climits>
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

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<vector<ll>> vec(n);
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		vector<ll> curr(1, x);
		while (x >= 10) {
			string s = to_string(x);
			x = 0;
			for (ll j = 0; j < s.size(); ++j) {
				x += s[j] - '0';
			}
			curr.push_back(x);
		}
		vec[i] = curr;
	}
	bool upd = false;
	ll uleft = LLONG_MAX;
	ll uright = 0;
	vector<ll> f(n + 2, 0);
	vector<ll> curr(n + 2, 0);
	vector<ll> final(n, -1);
	for (ll i = 0; i < q; ++i) {
		ll t;
		cin >> t;
		if (t == 2) {
			ll x;
			cin >> x;
			--x;
			if (final[x] != -1) {
				cout << final[x] << endl;
			} else {
				ll ind = 0;
				if (upd) {
					if (uleft <= x && x <= uright) {
						for (ll j = uleft; j <= uright; ++j) {
							ind += f[j];
							f[j] = 0;
							curr[j] += ind;
							if (curr[j] >= vec[j].size()) {
								final[j] = vec[j][vec[j].size() - 1];
							}
						}
						f[uright + 1] = 0;
						upd = false;
						uleft = LLONG_MAX;
						uright = 0;
					}
				}
				ind = min(curr[x], (ll)vec[x].size() - 1);
				cout << vec[x][ind] << endl;
			}

		} else {
			upd = true;
			ll l, r;
			cin >> l >> r;
			--l, --r;
			uleft = min(uleft, l);
			uright = max(uright, r);
			++f[l];
			--f[r + 1];
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
