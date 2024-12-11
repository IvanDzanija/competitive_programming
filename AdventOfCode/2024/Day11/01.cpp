#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>

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
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	vector<ll> vec;
	while (getline(input, line)) {
		while (line.find(' ') != string::npos) {
			vec.push_back(stoll(line.substr(0, line.find(' '))));
			line = line.substr(line.find(' ') + 1);
		}
		vec.push_back(stoll(line));
	}
	for (ll i = 0; i < 25; ++i) {
		ll n = vec.size();
		for (ll j = 0; j < n; ++j) {
			if (vec[j] == 0) {
				vec[j] = 1;
				continue;
			}
			string curr = to_string(vec[j]);
			if (curr.size() & 1) {
				vec[j] *= 2024;
			} else {
				string fh = curr.substr(0, curr.size() / 2);
				string sh = curr.substr(curr.size() / 2);
				vec[j] = stoll(fh);
				vec.push_back(stoll(sh));
			}
		}
	}
	cout << vec.size() << endl;
	return 0;
}
