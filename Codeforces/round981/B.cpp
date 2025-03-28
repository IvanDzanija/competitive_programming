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
		ll n;
		cin >> n;
		int mat[n][n];
		ll ans = 0;
		for (ll r = 0; r < n; ++r) {
			for (ll c = 0; c < n; ++c) {
				cin >> mat[r][c];
			}
		}
		for (ll j = 0; j < n; ++j) {
			for (ll k = 0; k < n; ++k) {
				ll r = j, c = k;
				if (mat[j][k] < 0) {

					vector<pair<ll, ll>> pos;
					ll max = mat[j][k];
					while (r < n - 1 && c < n - 1) {
						++r;
						++c;
						if (mat[r][c] < 0) {
							pos.push_back(make_pair(r, c));
							if (mat[r][c] < max) {
								max = mat[r][c];
							}
						}
					}
					ans += max;
					for (auto x : pos) {
						mat[x.first][x.second] -= max;
					}
				} else {
					continue;
				}
			}
		}
		cout << 0 - ans << endl;
	}

	return 0;
}
