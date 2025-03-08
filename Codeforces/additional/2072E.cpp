// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
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
const int maxN = 500;

vector<int> hor;
vector<int> ver;

void precalc(void) {
	ll h = 0, v = 0;
	for (ll i = 0; i < maxN; ++i) {
		h += hor.size();
		hor.push_back(h);
	}
	for (ll i = 0; i < maxN; ++i) {
		v += ver.size() + 1;
		ver.push_back(v);
	}
}

void solve() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0 << endl;
		return;
	}
	ll ans = 0;
	int x = 0, y = 0;

	auto it = prev(upper_bound(all(hor), n));
	x = distance(hor.begin(), it);
	n -= *it;
	ans += x + 1;
	// cout << n << ' ' << ans << ' ' << x << ' ' << *it << endl;
	if (n > 0) {
		it = prev(upper_bound(all(ver), n));
		y = distance(ver.begin(), it) + 1;
		n -= *it;
		ans += y;
		// cout << n << ' ' << ans << ' ' << y << ' ' << *it << endl;
	}
	int r = 1, c = 1, diag = 0;
	while (n > 0) {
		if (r > x || c > y || n - 2 < 0) {
			break;
		}
		diag = r;
		++ans, ++r, ++c, n -= 2;
	}
	cout << ans + n << endl;
	for (ll i = 0; i <= x; ++i) {
		cout << i << ' ' << 0 << endl;
	}
	for (ll i = 1; i <= y; ++i) {
		cout << 0 << ' ' << i << endl;
	}
	for (ll i = 1; i <= diag; ++i) {
		cout << i << ' ' << i << endl;
	}
	x = diag + 1, y = -1;
	while (n--) {
		cout << x << ' ' << y << endl;
		++x, --y;
	}

	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll tc = 1;
	cin >> tc;
	precalc();
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
