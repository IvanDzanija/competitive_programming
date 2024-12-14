#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
#include <unistd.h>

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
int R = 103;
int C = 101;
vector<vector<ll>> grid(R, vector<ll>(C, 0));

// no reason why this should work
bool check() {
	for (auto x : grid) {
		for (auto y : x) {
			if (y > 1) {
				return false;
			}
		}
	}
	return true;
}

signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	vector<vector<ll>> pos;

	while (getline(input, line)) {
		ll c = stoll(line.substr(line.find('=') + 1, line.find(',')));
		line = line.substr(line.find(',') + 1);
		ll r = stoll(line.substr(0, line.find(' ')));
		line = line.substr(line.find('=') + 1);
		ll dc = stoll(line.substr(0, line.find(',')));
		line = line.substr(line.find(',') + 1);
		ll dr = stoll(line);
		++grid[r][c];
		pos.push_back({r, c, dr, dc});
	}
	ll t = 0;
	while (t < INF / 2) {
		++t;
		for (ll i = 0; i < pos.size(); ++i) {
			ll r = pos[i][0];
			ll c = pos[i][1];
			ll dr = pos[i][2];
			ll dc = pos[i][3];
			ll rr = (r + dr + R) % R;
			ll cc = (c + dc + C) % C;
			pos[i][0] = rr;
			pos[i][1] = cc;
			--grid[r][c];
			++grid[rr][cc];
		}
		if (check()) {
			// uncomment to see the Christmas tree
			// for (auto x : grid) {
			// 	for (auto y : x) {
			// 		cout << y;
			// 	}
			// 	cout << endl;
			// }
			break;
		}
	}
	cout << t << endl;

	return 0;
}
