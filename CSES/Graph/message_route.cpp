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
	ll n, m;
	cin >> n >> m;
	map<ll, set<ll>> graph;
	for (ll i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;
		graph[x].insert(y);
		graph[y].insert(x);
	}
	map<ll, ll> c;
	std::queue<ll> q;
	q.push(1);
	set<ll> vis;
	bool poss = false;
	while (!q.empty() && !poss) {
		ll top = q.front();
		q.pop();
		if (vis.count(top)) {
			continue;
		}
		vis.insert(top);
		set<ll> b = graph[top];
		for (auto x : b) {
			if (x == n) {
				poss = true;
				c[x] = top;
				break;

			} else {
				if (!c.count(x)) {
					c[x] = top;
					q.push(x);
				}
			}
		}
		if (poss) {
			break;
		}
	}
	if (!poss) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		ll r = n;
		vector<ll> res;
		while (n != 1) {
			res.push_back(c[n]);
			n = c[n];
		}
		cout << res.size() + 1 << endl;
		for (ll i = res.size() - 1; i >= 0; --i) {
			cout << res[i] << ' ';
		}
		cout << r << endl;
	}

	return 0;
}
