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
	ll n;
	cin >> n;
	ll l, r;
	cin >> l >> r;
	--l, --r;
	vector<ll> mid, left, right;
	ll sum = 0;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		if (i < l) {
			left.push_back(x);
		} else if (i > r) {
			right.push_back(x);
		} else {
			mid.push_back(x);
			sum += x;
		}
	}
	sort(all(left));
	sort(all(right));
	sort(all(mid));

	ll lind = 0, rind = 0;
	ll s1 = 0, s2 = 0;
	ll t = 0;
	for (ll i = 0; t < r - l + 1;) {
		if (left.size() > lind && left[lind] < mid[i]) {
			s1 += left[lind];
			++lind;
		} else {
			s1 += mid[i];
			++i;
		}
		++t;
	}
	t = 0;
	for (ll i = 0; t < r - l + 1;) {
		++t;
		if (right.size() > rind && right[rind] < mid[i]) {
			s2 += right[rind];
			++rind;
		} else {
			s2 += mid[i];
			++i;
		}
	}
	cout << min(s2, (min(s1, sum))) << endl;

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
