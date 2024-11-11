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
		ll n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		ll x = 0, y = 0;
		bool c = false;
		ll j = 0;
		while (j < 100) {
			++j;
			for (ll i = 0; i < s.size(); ++i) {
				if (s[i] == 'N') {
					++y;
				} else if (s[i] == 'S') {
					--y;
				} else if (s[i] == 'E') {
					++x;
				} else {
					--x;
				}
				if (x == a and y == b) {
					c = true;
				}
			}
		}
		if (!c) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
