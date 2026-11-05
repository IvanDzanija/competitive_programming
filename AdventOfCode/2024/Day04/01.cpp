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
		int found = -1;
		while ((found = line.find("XMAS", found + 1)) != string::npos) {
			++ans;
		}
		found = -1;
		while ((found = line.find("SAMX", found + 1)) != string::npos) {
			++ans;
		}
	}
	int R = vec.size();
	int C = vec[0].size();

	for (int i = 0; i < C; ++i) {
		string curr;
		for (int j = 0; j < R; ++j) {
			curr.push_back(vec[j][i]);
		}
		int found = -1;
		while ((found = curr.find("XMAS", found + 1)) != string::npos) {
			++ans;
		}
		found = -1;
		while ((found = curr.find("SAMX", found + 1)) != string::npos) {
			++ans;
		}
	}
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C - 2; ++c) {
			if (r >= 3) {
				string curr;
				curr.push_back(vec[r][c]);
				curr.push_back(vec[r - 1][c + 1]);
				curr.push_back(vec[r - 2][c + 2]);
				curr.push_back(vec[r - 3][c + 3]);
				if (curr == "XMAS" || curr == "SAMX") {
					++ans;
				}
			}
			if (r + 3 < R) {
				string curr;
				curr.push_back(vec[r][c]);
				curr.push_back(vec[r + 1][c + 1]);
				curr.push_back(vec[r + 2][c + 2]);
				curr.push_back(vec[r + 3][c + 3]);
				if (curr == "XMAS" || curr == "SAMX") {
					++ans;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
