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
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n & 1) {
			if (n < 27) {
				cout << -1 << ' ';
			} else {
				int last = 1;
				cout << last << ' ';
				for (int i = last + 1; i < last + 5; ++i) {
					cout << i << ' ' << i << ' ';
				}
				cout << last << ' ';
				int nlast = last + 5;
				cout << nlast << ' ';
				for (int i = nlast + 1; i < nlast + 8; ++i) {
					cout << i << ' ' << i << ' ';
				}
				cout << last << ' ' << nlast << ' ';
				for (int i = 0; i < (n - 27) / 2; ++i) {
					cout << i + 27 << ' ' << i + 27 << ' ';
				}
			}

		} else {
			for (int i = 1; i <= n / 2; ++i) {
				cout << i << ' ' << i << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}
