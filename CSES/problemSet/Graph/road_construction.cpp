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
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<set<ll>> eds(n);
	vector<int> vis(n, 0);
	vector<int> mp(n, 0);
	ll ans = n;
	int curr = 1;
	int max_ = 0;
	for (ll i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;
		--x;
		--y;
		eds[x].insert(y);
		eds[y].insert(x);
		if (!vis[x] && vis[y]) {
			vis[x] = vis[y];
			++mp[vis[y]];
			--ans;
		} else if (!vis[y] && vis[x]) {
			vis[y] = vis[x];
			++mp[vis[y]];
			--ans;
		} else if (!vis[y] && !vis[x]) {
			vis[x] = vis[y] = curr++;
			mp[vis[x]] = 2;
			--ans;
		} else if (vis[x] != vis[y]) {
			if (mp[vis[x]] >= mp[vis[y]]) {
				mp[vis[x]] += mp[vis[y]];
				queue<int> q;
				q.push(y);
				vector<int> visited(n, 0);
				while (!q.empty()) {
					auto top = q.front();
					q.pop();
					if (visited[top]) {
						continue;
					}
					visited[top] = 1;
					for (auto z : eds[top]) {
						vis[z] = vis[x];
						q.push(z);
					}
				}
			} else {
				mp[vis[y]] += mp[vis[x]];
				queue<int> q;
				q.push(x);
				vector<int> visited(n, 0);
				while (!q.empty()) {
					auto top = q.front();
					q.pop();
					if (visited[top]) {
						continue;
					}
					visited[top] = 1;
					for (auto z : eds[top]) {
						vis[z] = vis[y];
						q.push(z);
					}
				}
			}
			--ans;
		}
		if (mp[vis[x]] > max_) {
			max_ = mp[vis[x]];
		}
		cout << ans << ' ' << max_ << "\n";
		// for (auto r : vis) {
		// 	cout << r << ' ';
		// }
		// cout << endl;
	}

	return 0;
}
