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
ll ans = INF;
int n;
map<tuple<int, int, int, int>, ll> memo;
map<tuple<int, int, int>, pair<int, int>> seen;

void solve(ll cnt, int p, int a1, int a2, int a3) {
	if (cnt >= ans) {
		return;
	}
	auto key = make_tuple(p, a1, a2, a3);
	auto key1 = make_tuple(a1, a2, a3);
	if (seen.count(key1)) {
		if (seen[key1].first < cnt) {
			return;
		} else if (seen[key1].second <= p) {
			return;
		}
	}
	seen[key1] = make_pair(cnt, p);
	if (memo.count(key)) {
		ans = min(ans, cnt + memo[key]);
		return;
	}
	if (a1 >= n && a2 >= n && a3 >= n) {
		if (memo.count(key)) {
			memo[key] = min(memo[key], cnt);
		} else {
			memo[key] = cnt;
		}
		ans = min(ans, cnt);
		return;
	}

	if (p - 25 >= 0 && a3 < n) {
		solve(cnt, p - 25, a1, a2, a3 + 1);
	}
	if (p - 21 >= 0 && a2 < n) {
		solve(cnt, p - 21, a1, a2 + 1, a3);
	}
	if (p - 18 >= 0 && a1 < n) {
		solve(cnt, p - 18, a1 + 1, a2, a3);
	}
	if (p < 18) {
		if (a3 < n) {
			if (a3 + 1 < n) {
				solve(cnt + 1, 60 - 25 - 25, a1, a2, a3 + 2);
			} else if (a2 < n) {
				solve(cnt + 1, 60 - 25 - 21, a1, a2 + 1, a3 + 1);
			} else if (a1 < n) {
				solve(cnt + 1, 60 - 18 - 25, a1 + 1, a2, a3 + 1);
			}
		} else if (a2 < n) {
			if (a2 + 1 < n && a1 < n) {
				solve(cnt + 1, 0, a1 + 1, a2 + 2, a3);
			} else if (a1 < n) {
				solve(cnt + 1, 60 - 21 - 18, a1 + 1, a2 + 1, a3);
			}
		} else if (a1 < n) {
			if (a1 + 2 < n) {
				solve(cnt + 1, 60 - 3 * 18, a1 + 3, a2, a3);
			} else if (a1 + 1 < n) {
				solve(cnt + 1, 60 - 2 * 18, a1 + 2, a2, a3);
			} else {
				solve(cnt + 1, 60 - 18, a1 + 1, a2, a3);
			}
		}
	}

	return;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	cin >> n;
	solve(0, 0, 0, 0, 0);
	cout << ans << endl;
	return 0;
}
