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
ll ceil_div(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
void solve(void) {
	ll n;
	cin >> n;
	vector<ll> a(n), b(n), c(n);
	vector<vector<ll>> prefix(3, vector<ll>(n, 0));
	ll tot = 0, sum = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		tot += a[i];
		prefix[0][i] = tot;
	}
	for (ll i = 0; i < n; ++i) {
		cin >> b[i];
		sum += b[i];
		prefix[1][i] = sum;
	}
	sum = 0;
	for (ll i = 0; i < n; ++i) {
		cin >> c[i];
		sum += c[i];
		prefix[2][i] = sum;
	}
	ll tar = ceil_div(tot, 3);
	sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum >= tar) {
			ll ns = 0;
			for (ll j = i + 1; j < n; ++j) {
				ns += b[j];
				if (ns >= tar) {
					if (tot - prefix[2][j] >= tar) {
						cout << 1 << ' ' << i + 1 << ' ' << i + 2 << ' '
							 << j + 1 << ' ' << j + 2 << ' ' << n << endl;
						return;
					}
				}
			}
			ns = 0;
			for (ll j = i + 1; j < n; ++j) {
				ns += c[j];
				if (ns >= tar) {
					if (tot - prefix[1][j] >= tar) {
						cout << 1 << ' ' << i + 1 << ' ' << j + 2 << ' ' << n
							 << ' ' << i + 2 << ' ' << j + 1 << endl;
						return;
					}
				}
			}
			break;
		}
	}
	sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += b[i];
		if (sum >= tar) {
			ll ns = 0;
			for (ll j = i + 1; j < n; ++j) {
				ns += a[j];
				if (ns >= tar) {
					if (tot - prefix[2][j] >= tar) {
						cout << i + 2 << ' ' << j + 1 << ' ' << 1 << ' '
							 << i + 1 << ' ' << j + 2 << ' ' << n << endl;
						return;
					}
				}
			}
			ns = 0;
			for (ll j = i + 1; j < n; ++j) {
				ns += c[j];
				if (ns >= tar) {
					if (tot - prefix[0][j] >= tar) {
						cout << j + 2 << ' ' << n << ' ' << 1 << ' ' << i + 1
							 << ' ' << i + 2 << ' ' << j + 1 << endl;
						return;
					}
				}
			}
			break;
		}
	}
	sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += c[i];
		if (sum >= tar) {
			ll ns = 0;
			for (ll j = i + 1; j < n; ++j) {
				ns += a[j];
				if (ns >= tar) {
					if (tot - prefix[1][j] >= tar) {
						cout << i + 2 << ' ' << j + 1 << ' ' << j + 2 << ' '
							 << n << ' ' << 1 << ' ' << i + 1 << endl;
						return;
					}
				}
			}
			ns = 0;
			for (ll j = i + 1; j < n; ++j) {
				ns += b[j];
				if (ns >= tar) {
					if (tot - prefix[0][j] >= tar) {
						cout << j + 2 << ' ' << n << ' ' << i + 2 << ' '
							 << j + 1 << ' ' << 1 << ' ' << i + 1 << endl;
						return;
					}
				}
			}
			break;
		}
	}
	cout << -1 << endl;
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
