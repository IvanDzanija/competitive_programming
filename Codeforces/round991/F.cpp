#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>

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
vector<vector<int>> sparse_table(vector<int> vec) {
	if (vec.size() == 0) {
		return vector<vector<int>>(1, vector<int>(1, 0));
	}
	int n = vec.size();
	int k = log2(n);
	vector<vector<int>> s(n, vector<int>(k + 1, 1));
	for (int i = 0; i < n; ++i) {
		s[i][0] = vec[i];
	}
	int len = 1;
	for (int j = 1; j <= k; ++j) {
		len *= 2;
		for (int i = 0; i + len - 1 < n; ++i) {
			s[i][j] = gcd(s[i][j - 1], s[i + len / 2][j - 1]);
		}
	}
	return s;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, q;
		cin >> n >> q;
		vector<int> a(n, 0);
		for (ll i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> b;
		for (int i = 0; i + 1 < n; ++i) {
			b.push_back(abs(a[i] - a[i + 1]));
		}
		auto s = sparse_table(b);
		while (q--) {
			ll a, b;
			cin >> a >> b;
			if (a == b) {
				cout << 0 << ' ';
				continue;
			}
			--a;
			b -= 2;
			int j = log2(b - a + 1);
			cout << gcd(s[a][j], s[b - (ll)pow(2, j) + 1][j]) << ' ';
		}
		cout << endl;
	}
	return 0;
}
