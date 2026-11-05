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
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	vector<vector<ll>> vec;
	int i = 0;
	while (getline(input, line)) {
		vec.push_back(vector<ll>());
		while (line.find(' ') != string::npos) {
			vec[i].push_back(stoll(line.substr(0, line.find(' '))));
			line = line.substr(line.find(' ') + 1);
		}
		vec[i].push_back(stoll(line));
		++i;
	}
	ll ans = 0;
	// for (auto x : vec) {
	// 	for (auto y : x) {
	// 		cout << y << ' ';
	// 	}
	// 	cout << endl;
	// }

	for (auto x : vec) {
		ll prev = x[0];
		bool dec = false;
		bool inc = false;
		for (ll i = 1; i < x.size(); ++i) {
			if (!(abs(x[i] - prev) <= 3 && abs(x[i] - prev) >= 1)) {
				dec = true;
				inc = true;
				break;
			}
			if (dec && inc) {
				break;
			}
			if (x[i] < prev) {
				dec = true;
			} else if (x[i] == prev) {
				dec = true;
				inc = true;
				break;
			} else {
				inc = true;
			}
			prev = x[i];
		}
		if ((dec && !inc) || (inc && !dec)) {
			++ans;
		}
	}
	cout << ans << endl;

	return 0;
}
