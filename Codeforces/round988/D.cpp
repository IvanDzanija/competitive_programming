#include <algorithm>
#include <bits/stdc++.h>
#include <cerrno>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

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
		ll n, m, k;
		cin >> n >> m >> k;
		map<ll, ll> need;
		set<ll> r;
		for (ll i = 0; i < n; ++i) {
			ll x, y;
			cin >> x >> y;
			need[x] = y - x + 2;
			r.insert(x);
		}
		map<ll, vector<ll>> have;
		for (ll i = 0; i < m; ++i) {
			ll x, y;
			cin >> x >> y;
			have[x].push_back(y);
			r.insert(x);
		}
		ll ans = 0;
		bool poss = false;
		ll tot = 1;
		priority_queue<ll> powers;
		for (auto it = r.begin(); it != r.end() && !poss; it = next(it)) {
			ll i = *it;
			if (have.count(i)) {
				for (auto x : have[i]) {
					powers.push(x);
				}
			} else if (need.count(i)) {
				ll jump = need[i] - tot;
				if (jump <= 0) {
					continue;
				} else {
					while (jump > 0 && !powers.empty()) {
						jump -= powers.top();
						tot += powers.top();
						++ans;
						powers.pop();
					}
					if (jump > 0) {
						poss = true;
						cout << -1 << endl;
					}
				}
			}
		}
		if (!poss) {
			cout << ans << endl;
		}
	}
	return 0;
}
