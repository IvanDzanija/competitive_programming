#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
#include <unordered_map>

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
ll count_digits(ll x) { return floor(log10(x) + 1); }

map<pair<ll, int>, ll> dp;
ll solve(ll x, int steps) {
	if (steps == 0) {
		return 1;
	}
	if (dp.count(make_pair(x, steps))) {
		return dp[make_pair(x, steps)];
	}
	ll ans = 0;
	int digits = count_digits(x);
	if (x == 0) {
		ans += solve(1, steps - 1);
	} else if (digits & 1) {
		ans += solve(x * 2024, steps - 1);
	} else {
		ans += solve(x / (ll)pow(10, digits / 2), steps - 1);
		ans += solve(x % (ll)pow(10, digits / 2), steps - 1);
	}
	dp[make_pair(x, steps)] = ans;
	return ans;
}
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	unordered_map<ll, int> mp;
	while (getline(input, line)) {
		while (line.find(' ') != string::npos) {
			ll curr = stoll(line.substr(0, line.find(' ')));
			line = line.substr(line.find(' ') + 1);
			if (mp.count(curr)) {
				++mp[curr];
			} else {
				mp[curr] = 1;
			}
		}
		ll curr = stoll(line);
		if (mp.count(curr)) {
			++mp[curr];
		} else {
			mp[curr] = 1;
		}
	}
	ll ans = 0;
	for (auto x : mp) {
		ans += (x.second * solve(x.first, 75));
	}

	cout << ans << endl;
	return 0;
}
