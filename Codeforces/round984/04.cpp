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
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		string s[n];
		for (ll i = 0; i < n; ++i) {
			cin >> s[i];
		}
		ll ans = 0;
		for (ll r = 0; r < min(n, m) / 2; ++r) {
			string c;
			for (ll j = r + 1; j < m - r; ++j) {
				c.push_back(s[r][j]);
			}
			// cout << "tu " << endl;
			for (ll i = r + 1; i < n - r; ++i) {
				c.push_back(s[i][m - 1 - r]);
			}
			for (ll j = m - 2 - r; j > r - 1; --j) {
				c.push_back(s[n - 1 - r][j]);
			}
			for (ll i = n - 2 - r; i > r - 1; --i) {
				c.push_back(s[i][r]);
			}
			c.push_back(c[0]);
			c.push_back(c[1]);
			c.push_back(c[2]);
			for (ll i = 0; i < c.size() - 3; ++i) {
				if (c.substr(i, 4) == "1543") {
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
