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
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	map<string, set<string>> graph;
	while (getline(input, line)) {
		string first = line.substr(0, line.find('-'));
		string second = line.substr(line.find('-') + 1);
		graph[first].insert(second);
		graph[second].insert(first);
	}
	set<tuple<string, string, string>> ans;
	for (auto x : graph) {
		if (x.first[0] == 't') {
			for (auto y : x.second) {
				for (auto z : graph[y]) {
					if (x.second.count(z)) {
						ans.insert(make_tuple(x.first, y, z));
						ans.insert(make_tuple(x.first, z, y));
						ans.insert(make_tuple(z, x.first, y));
						ans.insert(make_tuple(y, x.first, z));
						ans.insert(make_tuple(z, y, x.first));
						ans.insert(make_tuple(y, z, x.first));
					}
				}
			}
		}
	}
	cout << ans.size() / 6 << endl;
	return 0;
}
