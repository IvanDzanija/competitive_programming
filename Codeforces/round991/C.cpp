#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;
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
map<tuple<int, int, int>, bool> memo;
bool find(int rem, int i2, int i3) {
	rem %= 9;
	// cout << rem << ' ' << i2 << ' ' << i3 << endl;
	if (rem == 0) {
		return true;
	}
	auto key = make_tuple(rem, i2, i3);
	if (memo.count(key)) {
		return memo[key];
	}
	if (i2 > 0) {
		if (find(rem + 2, i2 - 1, i3)) {
			memo[key] = true;
			return true;
		}
	}
	if (i3 > 0) {
		if (find(rem + 6, i2, i3 - 1)) {
			memo[key] = true;
			return true;
		}
	}
	memo[key] = false;
	return false;
}
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		ll tot = 0;
		int i2 = 0;
		int i3 = 0;
		for (auto x : s) {
			int y = x - '0';
			tot += y;
			if (y == 2) {
				++i2;
			} else if (y == 3) {
				i3++;
			}
		}
		if (tot % 9 == 0) {
			cout << "YES" << endl;
		} else {
			int rem = tot % 9;
			// cout << rem << endl;
			if (find(rem, i2, i3)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
