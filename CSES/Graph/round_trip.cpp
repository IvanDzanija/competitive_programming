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
vector<set<ll>> grid(1e5 + 5, set<ll>());
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;
		grid[x].insert(y);
		grid[y].insert(x);
	}
	vector<ll> vis(n + 1, 0);
	vector<ll> par(n + 1, 0);
	ll start;
	ll end;
	ll i = 0;
	bool f = false;
	for (; i <= n && f == false;) {
		++i;
		if (vis[i]) {
			continue;
		}
		stack<pair<ll, ll>> stack;
		stack.push(make_pair(i, -1));
		while (!stack.empty() && f == false) {
			ll top = stack.top().first;
			ll p = stack.top().second;
			// cout << i << ' ' << top << ' ' << p << endl;
			stack.pop();
			vis[top] = 1;
			par[top] = p;
			for (ll j : grid[top]) {
				if (j == p) {
					continue;
				}
				if (vis[j]) {
					start = j;
					end = top;
					f = true;
				} else {
					stack.push(make_pair(j, top));
				}
			}
		}
	}
	if (!f) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		vector<ll> ans;
		ans.push_back(end);
		while (par[end] != start) {
			ans.push_back(par[end]);
			end = par[end];
		}
		cout << ans.size() + 2 << endl;
		cout << start << ' ';
		for (auto x : ans) {
			cout << x << ' ';
		}
		cout << start << ' ';
		cout << endl;
	}

	return 0;
}
