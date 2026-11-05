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
bool calc(ll k, vector<ll> &vec) {
	int res[20];
	for (ll i = 0; i < 20; ++i) {
		res[i] = 0;
	}
	for (ll i = 0; i < k; ++i) {
		ll c = vec[i];
		for (ll j = 0; c > 0; ++j) {
			res[j] += (c & 1);
			c >>= 1;
		}
	}
	ll ind = 0;
	for (ll i = k; i < (int)vec.size(); ++i) {
		ll c = vec[i];
		for (ll j = 0; c > 0; ++j) {
			if (c & 1 && res[j] == 0) {
				return false;
			}
			res[j] += (c & 1);
			c >>= 1;
		}
		c = vec[ind];
		++ind;
		for (ll j = 0; c > 0; ++j) {
			res[j] -= (c & 1);
			if (c & 1 && res[j] == 0) {
				return false;
			}
			c >>= 1;
		}
	}
	return true;
}
ll bin_s(ll high, vector<ll> &vec) {
	ll low = 1, mid;
	while (low < high) {
		mid = (high + low) / 2;
		if (calc(mid, vec)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> vec(n, 0);
	for (ll i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	cout << bin_s(n, vec) << endl;
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
