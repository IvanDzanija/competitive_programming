// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma, popcnt")
// #pragma GCC optimization("unroll-loops")
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
void solve(void) {
	string s;
	cin >> s;
	ll n = s.size();
	ll size = 0, ssize = -1, nsize = -1;
	bool state = true;
	bool nts = false, stn = false, ntn = true;
	ll i = 0;
	for (; i < n; ++i) {
		if (s[i] == '+') {
			++size;
		} else if (s[i] == '-') {
			--size;
		} else if (s[i] == '1') {
			nsize = size;
			break;
		} else {
			if (size < 2) {
				cout << "NO" << endl;
				return;
			}
			ssize = size;
			state = false;
			break;
		}
	}
	for (; i < n; ++i) {
		if (s[i] == '+') {
			stn = true;
			ntn = true;
			++size;
		} else if (s[i] == '-') {
			--size;
			if (size < ssize) {
				nts = true;
				ssize = -1;
			}
			if (size <= nsize) {
				ntn = false;
				nsize = size;
			}
		} else if (s[i] == '1') {
			stn = false;
			nsize = size;
			if (!state) {
				if (nts) {
					nts = false;
					ssize = -1;
				} else {
					cout << "NO" << endl;
					return;
				}
				state = true;
			}
			nts = false;
			ssize = -1;
		} else {
			if (size < 2 || !ntn) {
				cout << "NO" << endl;
				return;
			}
			if (state) {
				if (!stn) {
					cout << "NO" << endl;
					return;
				}
			}
			if (ssize != -1) {
				ssize = min(size, ssize);
			} else {
				ssize = size;
			}
			nts = false;
			state = false;
		}
	}
	cout << "YES" << endl;
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
