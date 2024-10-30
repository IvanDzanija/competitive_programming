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
		ll n;
		cin >> n;
		string s;
		cin >> s;
		ll ans = 0;
		ll left = 0;
		for (ll i = n - 1; i >= 0; --i) {

			if (s[i] == '0') {
				left = max(0ll, left - 1);
				ans += i + 1;
				continue;
			} else if (left + 1 > i) {
				left = max(0ll, left - 1);
				ans += i + 1;
			} else {
				++left;
			}
		}

		cout << ans << endl;
	}
	return 0;
}