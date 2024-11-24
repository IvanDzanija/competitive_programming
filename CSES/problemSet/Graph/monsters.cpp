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
	ll h, w;
	cin >> h >> w;
	char grid[h][w];
	int sr, sc;
	for (ll i = 0; i < h; ++i) {
		for (ll j = 0; j < w; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'A') {
				sr = i;
				sc = j;
			}
		}
	}
	stack<pair<ll, ll>> stack;
	stack.push(make_pair(sr, sc));
	char help[h][w];
	while (!stack.empty()) {
	}

	return 0;
}
