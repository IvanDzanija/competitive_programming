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
vector<ll> dp;
ll solve(ll a) {
	if (a <= 0) {
		return a == 0 ? 1 : 0;
	}
	string s = to_string(a);
	ll ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		ans += dp[i];
	}
	ll prev = 0;
	for (int i = 0; i < s.size(); ++i) {
		int curr = s[i] - '0';
		int dig = s.size() - 1 - i;
		if (prev < curr) {
			if (curr != 0) {
				ans += (curr - 1) * dp[dig];
			}
		} else {
			ans += curr * dp[dig];
		}
		if (curr == prev) {
			return ans;
		}
		prev = curr;
	}
	return ans + 1;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll c = 1;
	for (ll i = 0; i < 19; ++i) {
		dp.push_back(c);
		c *= 9;
	}
	cout << solve(b) - solve(a - 1) << endl;

	return 0;
}
