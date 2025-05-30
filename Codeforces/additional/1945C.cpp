#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
int ceil2(int a, int b) { return (a + b - 1) / b; }
void solve() {
	ll n;
	cin >> n;
	vector<ll> p(1, 0);
	string s;
	cin >> s;
	for (ll i = 1; i <= n; ++i) {
		ll x = s[i - 1] - '0';
		p.push_back(x + p[i - 1]);
	}
	if (n & 1) {
		ll delta = 0;
		ll half = n / 2;
		ll index = half;
		while (true) {
			ll left = index - p[index];
			ll llimit = ceil2(index, 2);
			ll right = p[n] - p[index];
			ll rlimit = ceil2(n - index, 2);
			if (left >= llimit && right >= rlimit) {
				cout << index << endl;
				return;
			}
			if (index <= half) {
				++delta;
				index = half + delta;
			} else {
				index = half - delta;
			}
		}
	} else {
		ll delta = 0;
		ll half = n / 2;
		ll index = half;
		while (true) {
			ll left = index - p[index];
			ll llimit = ceil2(index, 2);
			ll right = p[n] - p[index];
			ll rlimit = ceil2(n - index, 2);
			// cout << index << ' ' << left << ' ' << llimit << ' ' << right <<
			// ' '
			// 	 << rlimit << endl;
			if (left >= llimit && right >= rlimit) {
				cout << index << endl;
				return;
			}
			if (index >= half) {
				++delta;
				index = half - delta;
			} else {
				index = half + delta;
			}
		}
	}

	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
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
