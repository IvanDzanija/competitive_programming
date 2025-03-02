// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (ll)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(1e9 + 7)

using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;
struct custom_hash {
	static ull splitmix64(ull x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(ull x) const {
		static const ull FIXED_RANDOM =
			chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
int u_bound(const std::vector<int> &vec, int target, int right) {
	int left = 0;
	while (left < right) {
		int mid = (left + right) / 2;
		if (vec[mid] > target) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n, 0);
	for (int i = 0; i < n; ++i) {
		a[i] = (int)s[i];
	}
	vector<int> vec(n, 0);
	int mx = 0;
	for (int i = n - 1; i >= 0; --i) {
		mx = max(mx, (int)s[i]);
		vec[i] = mx;
	}
	vector<int> old;
	vector<int> pos;
	vector<int> h;
	for (int i = 0; i < n; ++i) {
		if (s[i] == mx) {
			h.push_back(old.size());
			old.push_back(-1);
			continue;
		}
		if (vec[i] == (int)s[i]) {
			pos.push_back(s[i]);
			h.push_back(old.size());
			old.push_back(-1);
		} else {
			old.push_back(s[i]);
		}
	}
	int ind = 0;
	if (pos.size() > 0) {
		for (int i = pos.size() - 1; i >= 0; --i) {
			old[h[ind]] = pos[i];
			++ind;
		}
	}
	bool sorted = true;
	for (int i = 0; i < old.size(); ++i) {
		if (old[i] == -1) {
			old[i] = mx;
		}
	}
	for (int i = 0; i < old.size() - 1; ++i) {
		if (old[i] > old[i + 1]) {
			sorted = false;
			break;
		}
	}
	if (!sorted) {
		cout << -1 << endl;
	} else {
		cout << (int)pos.size() << endl;
	}
	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll tc = 1;
	cin >> tc;
	while (tc--) {
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
