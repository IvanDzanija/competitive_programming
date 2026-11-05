#include <bits/stdc++.h>
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
	ll n, m;
	cin >> n >> m;
	map<ll, vector<ll>> g;
	ll dot;
	for (ll i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		dot = x;
	}
	set<ll> vis;
	set<ll> poss;
	for (ll i = 1; i <= n; ++i) {
		poss.insert(i);
	}
	queue<ll> q;
	q.push(dot);
	ll ans = 0;
	vector<pair<ll, ll>> pairs;
	while (!q.empty()) {
		ll curr = q.front();
		q.pop();
		if (vis.count(curr)) {
			continue;
		}
		vis.insert(curr);

		vector<ll> paths = g[curr];
		for (ll i = 0; i < paths.size(); ++i) {
			if (vis.count(paths[i]) == 0) {
				q.push(paths[i]);
				poss.erase(paths[i]);
			}
		}
		if (q.empty()) {
			if (vis.size() < n) {
				q.push(*poss.begin());
				++ans;
				pairs.push_back(make_pair(curr, *poss.begin()));
				poss.erase(poss.begin());
			}
		}
		poss.erase(curr);
	}
	cout << ans << endl;
	for (auto x : pairs) {
		cout << x.first << ' ' << x.second << endl;
	}
	return 0;
}
