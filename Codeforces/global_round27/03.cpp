#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
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
		if (n & 1) {
			cout << n << endl;
			for (ll i = 4; i < n - 1; ++i) {
				cout << i << ' ';
			}
			cout << "2 1 3 " << n - 1 << ' ' << n << endl;
		} else if (n == 6) {
			cout << "7 \n1 2 4 6 5 3 " << endl;
			;

		} else {
			ll k = count_bits(n);

			cout << (2 << (k - 1)) - 1 << endl;
			for (ll i = 4; i < ((1 << (k - 1)) - 2); ++i) {
				cout << i << ' ';
			}
			for (ll i = ((1 << (k - 1))); i < n; ++i) {
				cout << i << ' ';
			}
			cout << "2 1 3 " << ((1 << (k - 1)) - 2) << ' '
				 << ((1 << (k - 1)) - 1) << ' ' << n << endl;
		}
	}
	return 0;
}
