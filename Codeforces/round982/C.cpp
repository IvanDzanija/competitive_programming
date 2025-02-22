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

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	for (ll id = 0; id < t; ++id) {
		ll n;
		cin >> n;
		map<ll, vector<ll>> g;
		for (ll i = 0; i < n; ++i) {
			ll x;
			cin >> x;
			g[x - (n - i)].push_back(i + (x - (n - i)));
		}
		// for (auto x : g) {
		// 	cout << x.first << ": ";
		// 	for (auto y : x.second) {
		// 		cout << y << ' ';
		// 	}
		// 	cout << endl;
		// }
		stack<ll> q;
		ll max = 0;
		q.push(0);
		set<ll> vis;
		while (!q.empty()) {
			ll curr = q.top();
			q.pop();
			if (vis.count(curr)) {
				continue;
			}
			vis.insert(curr);
			for (auto x : g[curr]) {
				if (x > max) {
					max = x;
				}
				q.push(x);
			}
		}
		cout << n + max << endl;
	}
	return 0;
}
