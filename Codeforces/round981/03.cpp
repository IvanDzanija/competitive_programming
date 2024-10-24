#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; ++i) {
		ll n, ans = 0;
		cin >> n;
		ll in[n];
		for (ll j = 0; j < n; ++j) {
			cin >> in[j];
		}
		for (ll j = 1; j <= n / 2; ++j) {
			if (in[j] == in[j - 1] or in[n - j] == in[n - j - 1]) {
				swap(in[j], in[n - j - 1]);
			}
		}
		for (ll j = 0; j < n - 1; ++j) {
			if (in[j] == in[j + 1]) {
				++ans;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
