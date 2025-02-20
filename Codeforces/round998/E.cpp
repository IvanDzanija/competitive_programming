#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
const int maxN = 2e5 + 5;
ll n, m1, m2;
vector<int> sizeG(maxN, 0);
vector<int> sizeF(maxN, 0);
vector<int> linkF(maxN, 0);
vector<int> linkG(maxN, 0);

int find(int a, bool g) {
	if (g) {
		while (a != linkG[a]) {
			a = linkG[a];
		}
	} else {
		while (a != linkF[a]) {
			a = linkF[a];
		}
	}
	return a;
}

bool same(int a, int b, bool g) { return find(a, g) == find(b, g); }

void unite(int a, int b, bool g) {
	a = find(a, g);
	b = find(b, g);
	if (g) {
		if (sizeG[a] < sizeG[b]) {
			swap(a, b);
		}
		sizeG[a] += sizeG[b];
		linkG[b] = a;
	} else {
		if (sizeF[a] < sizeF[b]) {
			swap(a, b);
		}
		sizeF[a] += sizeF[b];
		linkF[b] = a;
	}
}

void solve() {
	cin >> n >> m1 >> m2;
	ll ans = 0;
	set<pair<int, int>> f;
	set<pair<int, int>> g;
	for (int i = 1; i <= n; i++) {
		linkF[i] = i;
		linkG[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		sizeF[i] = 1;
		sizeG[i] = 1;
	}
	for (ll i = 0; i < m1; ++i) {
		ll x, y;
		cin >> x >> y;
		f.insert(make_pair(x, y));
	}
	for (ll i = 0; i < m2; ++i) {
		ll x, y;
		cin >> x >> y;
		g.insert(make_pair(x, y));
		if (!same(x, y, true)) {
			unite(x, y, true);
		}
	}
	for (pair<int, int> x : f) {
		if (same(x.first, x.second, true)) {
			if (!same(x.first, x.second, false)) {
				unite(x.first, x.second, false);
			}
			if (g.count(x)) {
				g.erase(x);
			} else if (g.count(make_pair(x.second, x.first))) {
				g.erase(make_pair(x.second, x.first));
			}
		} else {
			++ans;
		}
	}
	for (pair<int, int> x : g) {
		if (!same(x.first, x.second, false)) {
			unite(x.first, x.second, false);
			++ans;
		}
	}
	cout << ans << endl;
	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int t = 1;
	cin >> t;

	while (t--) {
		solve();
#ifdef LOCAL
		cout << "--------------------------------------------" << endl;
#endif
	}

#ifdef LOCAL
	cerr << "Finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
	return 0;
}
