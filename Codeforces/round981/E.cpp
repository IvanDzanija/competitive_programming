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
		ll perm[n];
		for (ll j = 0; j < n; ++j) {
			ll ins;
			cin >> ins;
			perm[j] = ins - 1;
		}
		vector<int> visited(n, 0);
		for (ll j = 0; j < n; ++j) {
			if (visited[j] == 1) {
				continue;
			}
			ll c = 0;
			for (ll k = j; visited[k] != 1; k = perm[k]) {
				visited[k] = 1;
				++c;
			}
			ans += (c - 1) / 2;
		}

		cout << ans << endl;
	}

	return 0;
}
