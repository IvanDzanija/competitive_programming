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
const int maxN = 10e5 + 5;
vector<int> links(maxN, 0);
vector<int> sizes(maxN, 1);

int find(int a) {
	while (a != links[a]) {
		a = links[a];
	}
	return a;
}
bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	if (sizes[a] < sizes[b]) {
		swap(a, b);
	}
	links[b] = a;
	sizes[a] += sizes[b];
}

// union find implementation
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll ans = n;
	int res = 1;
	for (int i = 0; i < n; ++i) {
		links[i] = i;
	}

	for (ll i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;
		--x;
		--y;
		if (links[find(x)] != links[find(y)]) {
			--ans;
		}
		unite(x, y);

		int s1 = sizes[find(x)];
		int s2 = sizes[find(y)];
		res = max(s1, res);
		res = max(res, s2);
		cout << ans << ' ' << res << endl;
	}

	return 0;
}
