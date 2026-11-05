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
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	vector<string> vec;
	ll ans = 0;
	while (getline(input, line)) {
		vec.push_back(line);
	}
	int R = vec.size();
	int C = vec[0].size();
	for (int r = 1; r < R - 1; ++r) {
		for (int c = 1; c < C - 1; ++c) {
			string curr1;
			curr1.push_back(vec[r - 1][c - 1]);
			curr1.push_back(vec[r][c]);
			curr1.push_back(vec[r + 1][c + 1]);
			string curr2;
			curr2.push_back(vec[r - 1][c + 1]);
			curr2.push_back(vec[r][c]);
			curr2.push_back(vec[r + 1][c - 1]);
			// cout << curr1 << ' ' << curr2 << endl;
			if ((curr1 == "MAS" || curr1 == "SAM") &&
				(curr2 == "MAS" || curr2 == "SAM")) {
				++ans;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
