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
int count_bits(ll number) { return (int)log2(number) + 1; }
ll exp(ll b) {
	ll ans = 1;
	ll a = 2;
	while (b > 0) {
		if (b & 1)
			ans = (ans * a);
		a = (a * a);
		b /= 2;
	}
	return ans;
}

ll fun(ll n, ll i, ll k) {
	ll ans = 0;
	ll b = n % 4;
	if (b == 0) {
		ans = (ull)n;
	} else if (b == 1) {
		ans = (ull)1;
	} else if (b == 2) {
		ans = (ull)n + 1;
	} else {
		ans = (ull)0;
	}
	ll e = exp(i);
	ll t = n / e;
	if ((t * e) + k <= n && k != 0) {
		++t;
	}

	// cout << e << ' ' << t << ' ' << c << ' ' << ' ' << k << endl;

	ll a1;
	if (t & 1) {
		a1 = k;
	} else {
		a1 = 0;
	}

	ll a2;
	if (k != 0) {
		--t;
	}
	if (t % 4 == 0) {
		a2 = t;
	} else if (t % 4 == 1) {
		a2 = 1;
	} else if (t % 4 == 2) {
		a2 = t + 1;
	} else {
		a2 = 0;
	}
	// cout << bitset<16>(a1) << endl;
	// cout << bitset<16>(a2 <<= i) << endl;
	// cout << bitset<16>(ans) << endl;

	return ans ^ ((a2 <<= i) ^ a1);
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll l, r, i, k;
		cin >> l >> r >> i >> k;
		if (i == 0) {
			cout << 0 << endl;
			continue;
		}
		ll a1 = fun(r, i, k);
		// cout << a1 << endl;
		ll a2 = fun(l - 1, i, k);
		cout << (a1 ^ a2) << endl;
	}
	return 0;
}
