#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

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
map<string, bool> dp;
map<string, tuple<string, string, string>> cons;
void solve(string x) {
	if (dp.count(x)) {
		return;
	}
	auto [f, s, op] = cons[x];
	bool res;
	if (dp.count(f) && dp.count(s)) {
		if (op == "XOR") {
			res = !dp[f] != !dp[s];
		} else if (op == "AND") {
			res = dp[f] && dp[s];
		} else {
			res = dp[f] || dp[s];
		}
		dp[x] = res;
	}
	if (!dp.count(f)) {
		solve(f);
	}
	if (!dp.count(s)) {
		solve(s);
	}
	if (op == "XOR") {
		res = !dp[f] != !dp[s];
	} else if (op == "AND") {
		res = dp[f] && dp[s];
	} else {
		res = dp[f] || dp[s];
	}
	dp[x] = res;
}
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	int reading = 0;

	while (getline(input, line)) {
		if (line.empty()) {
			reading = 1;
			continue;
		}
		if (reading == 0) {
			dp[line.substr(0, line.find(':'))] =
				stoi(line.substr(line.find(' ') + 1));
		} else {
			string first = line.substr(0, line.find(' '));
			line = line.substr(line.find(' ') + 1);
			string op = line.substr(0, line.find(' '));
			line = line.substr(line.find(' ') + 1);
			string second = line.substr(0, line.find(' '));
			line = line.substr(line.find(' ') + 1);
			line = line.substr(line.find(' ') + 1);
			cons[line] = make_tuple(first, second, op);
		}
	}
	ll ans = 0;

	for (auto it = cons.rbegin(); it != cons.rend(); it = next(it)) {
		if (it->first[0] == 'z') {
			ans <<= 1;
			solve(it->first);
			ans |= dp[(it->first)];
		}
	}

	cout << ans << endl;

	return 0;
}
