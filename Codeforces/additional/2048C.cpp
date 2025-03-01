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
	ll n = s.size();
	if (n == 1) {
		cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << 1 << endl;
		return;
	}
	ll zero = 0;
	while (zero < n && s[zero] != '0') {
		++zero;
	}
	if (zero == n) {
		cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << endl;
	} else {
		ll left = 0, right = 0, size = n - zero;
		string first = s.substr(zero, size);
		deque<char> second;
		for (ll i = 0; i < size; ++i) {
			second.push_back(s[i]);
		}
		string ans = "";
		for (ll i = 1; i + size <= n; ++i) {
			string res;
			for (ll j = 0; j < size; ++j) {
				res += (second[j] != first[j]) ? '1' : '0';
			}
			if (res > ans) {
				left = i;
				right = i + size - 1;
				ans = res;
			}
			second.pop_front();
			second.push_back(s[i - 1 + size]);
		}
		cout << 1 << ' ' << n << ' ' << left << ' ' << right << endl;
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
