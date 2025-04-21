#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
#include <set>

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
	vector<ll> vec(n + 1, 0);
	bool poss = false;
	stack<ll> stack;
	set<ll> vis;
	for (ll i = 1; i <= n; ++i) {
		stack.push(i);
	}
	while (!stack.empty()) {
		ll i = stack.top();
		stack.pop();
		if (vis.count(i)) {
			continue;
		}
		vis.insert(i);
		ll a = vec[i];
		if (a == 0) {
			a = 1;
		}
		ll c = a ^ 3;
		set<ll> b = graph[i];
		// cout << i << ' ' << a << endl;
		for (set<ll>::iterator it = b.begin(); it != b.end(); it = next(it)) {
			if (vec[*it] == a) {
				poss = true;
				break;
			} else {
				vec[*it] = c;
				stack.push(*it);
			}
		}
		if (poss) {
			break;
		}
	}
	if (poss) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (ll i = 1; i <= n; ++i) {
			if (vec[i] == 0) {
				cout << 1 << ' ';
			} else {
				cout << vec[i] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}
