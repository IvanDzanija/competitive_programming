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
map<ll, ll> start;
ll current_size, fin;
bool search_for(ll a) {
	ll first = a / 2;
	ll second = (a + 1) / 2;
	if (a == 0 || current_size < fin) {
		return false;
	}
	if (start.count(first) && start[first] > 0) {
		--start[first];
	} else {
		if (!search_for(first)) {
			return false;
		}
		--start[first];
	}
	if (start.count(second) && start[second] > 0) {
		--start[second];
	} else {
		if (!search_for(second)) {
			return false;
		}
		--start[second];
	}
	--current_size;
	start[a] = 1;
	return true;
}

void solve(void) {
	ll n, m;
	cin >> n >> m;
	vector<ll> end(m);
	current_size = n, fin = m;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		if (start.count(x)) {
			++start[x];
		} else {
			start[x] = 1;
		}
	}
	for (ll i = 0; i < m; ++i) {
		cin >> end[i];
	}
	bool ans = true;
	for (auto x : end) {
		if (start[x] > 0) {
			--start[x];
			continue;
		} else {
			if (!search_for(x)) {
				ans = false;
				break;
			}
			--start[x];
		}
	}
	if (!ans) {
		cout << "No" << endl;
	} else {
		for (auto x : start) {
			if (x.second > 0) {
				start.clear();
				cout << "No" << endl;
				return;
			}
		}
		cout << "Yes" << endl;
	}
	start.clear();
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
