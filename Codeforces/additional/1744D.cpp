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
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		while (!(x & 1)) {
			++res;
			x >>= 1;
		}
	}
	if (res >= n) {
		cout << 0 << endl;
		return;
	}
	int fin = res;
	vector<int> pos;
	for (int i = 1; i <= n; ++i) {
		int k = i;
		if (!(k & 1)) {
			int current = 0;
			while (!(k & 1)) {
				++current;
				++res;
				k >>= 1;
			}
			pos.push_back(current);
		}
	}

	if (res < n) {
		cout << -1 << endl;
	} else {
		int ans = 0;
		sort(all(pos));
		int ind = pos.size() - 1;
		while (fin < n) {
			fin += pos[ind];
			--ind;
			++ans;
		}
		cout << ans << endl;
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
