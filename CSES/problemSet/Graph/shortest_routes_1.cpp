#include <bits/stdc++.h>
#include <cinttypes>
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
	vector<set<pair<ll, ll>>> a(n + 1, set<pair<ll, ll>>());
	for (ll i = 0; i < m; ++i) {
		ll x, y, z;
		cin >> x >> y >> z;
		a[x].insert(make_pair(z, y));
	}
	vector<ll> vis(n + 1, -1);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
		pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		ll w = pq.top().first;
		ll top = pq.top().second;
		pq.pop();
		if (vis[top] != -1) {
			continue;
		}
		vis[top] = w;
		for (auto next : a[top]) {
			pq.push(make_pair(next.first + w, next.second));
		}
	}
	for (ll i = 1; i <= n; ++i) {
		cout << vis[i] << ' ';
	}
	cout << endl;
	return 0;
}
