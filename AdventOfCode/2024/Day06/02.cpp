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
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	vector<string> vec;
	ll sr;
	ll sc;
	while (getline(input, line)) {
		vec.push_back(line);
		for (ll i = 0; i < line.size(); ++i) {
			if (vec[vec.size() - 1][i] == '^') {
				sr = vec.size() - 1;
				sc = i;
			}
		}
	}
	int R = vec.size();
	int C = vec[0].size();
	set<tuple<int, int, int>> seen;
	ll ans = 0;
	int tr = sr;
	int tc = sc;

	// naive approach, not efficient at all
	// probably could have used part 1 solution to find all possible spots guard
	// would visit then just try placing the obstacle there
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			int dir = 3;
			char temp = vec[r][c];
			seen.clear();
			if (temp == '#') {
				continue;
			}
			vec[r][c] = '#';
			sr = tr;
			sc = tc;
			while (sr >= 0 && sr < R && sc >= 0 && sc < C) {
				auto key = make_tuple(sr, sc, dir);
				if (seen.count(key)) {
					++ans;
					break;
				}
				seen.insert(key);
				if (dir == 0) {
					if (sc + 1 == C) {
						break;
					} else if (vec[sr][sc + 1] == '#') {
						dir = 1;
					} else {
						++sc;
					}
				} else if (dir == 1) {
					if (sr + 1 == R) {
						break;
					} else if (vec[sr + 1][sc] == '#') {
						dir = 2;
					} else {
						++sr;
					}
				} else if (dir == 2) {
					if (sc == 0) {
						break;
					} else if (vec[sr][sc - 1] == '#') {
						dir = 3;
					} else {
						--sc;
					}
				} else if (dir == 3) {
					if (sr == 0) {
						break;
					} else if (vec[sr - 1][sc] == '#') {
						dir = 0;
					} else {
						--sr;
					}
				}
			}
			vec[r][c] = temp;
		}
	}
	cout << ans << endl;
	return 0;
}
