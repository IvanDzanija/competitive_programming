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
void solve() {
	string s;
	cin >> s;
	if (s.size() == 3) {
		if (s[0] < s[1] && s[2] > s[1]) {
			cout << ": (" << endl;
		} else if (s[0] > s[1] && s[2] < s[1]) {
			cout << ": (" << endl;
		} else {
			cout << s[0] << ' ' << s[1] << ' ' << s[2] << endl;
		}
		return;
	}
	int n = s.size();
	if (s[0] == 'a') {
		int b = 0;
		for (ll i = 1; i < n; ++i) {
			if (s[i] == 'b') {
				b = i;
				break;
			}
		}
		if (b == 0) {
			cout << s[0] << ' ' << s[1] << ' ';
			for (ll i = 2; i < n; ++i) {
				cout << s[i];
			}
			cout << endl;
		} else if (b == n - 1) {
			for (ll i = 0; i < b - 1; ++i) {
				cout << s[i];
			}
			cout << ' ' << s[b - 1] << ' ' << s[b] << endl;
		} else {
			for (ll i = 0; i < b; ++i) {
				cout << s[i];
			}
			cout << ' ';
			for (ll i = b; i < n - 1; ++i) {
				cout << s[i];
			}
			cout << ' ' << s[n - 1] << endl;
		}
	} else {
		int a = 0;
		for (ll i = 1; i < n; ++i) {
			if (s[i] == 'a') {
				a = i;
				break;
			}
		}
		if (a == 0) {
			cout << s[0] << ' ' << s[1] << ' ';
			for (ll i = 2; i < n; ++i) {
				cout << s[i];
			}
			cout << endl;
		} else if (a == n - 1) {
			cout << s[0] << ' ';
			for (ll i = 1; i < a; ++i) {
				cout << s[i];
			}
			cout << ' ' << s[a] << endl;
		} else {
			for (ll i = 0; i < a; ++i) {
				cout << s[i];
			}
			cout << ' ' << s[a] << ' ';
			for (ll i = a + 1; i < n; ++i) {
				cout << s[i];
			}
			cout << endl;
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
