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
	getline(input, line);
	ll ans = 0, n = line.size(), next = 0;
	vector<pair<ll, ll>> rooms;
	vector<pair<pair<ll, ll>, ll>> nums;
	ll pos = 0;
	ll c = 0;
	for (ll i = 0; i < n; ++i) {
		if (i & 1) {
			rooms.push_back(make_pair(pos, pos + line[i] - '0'));
			pos += line[i] - '0';
		} else {
			nums.push_back(make_pair(make_pair(pos, pos + line[i] - '0'), c));
			++c;
			pos += line[i] - '0';
		}
	}
	for (ll j = nums.size() - 1; j > 0; --j) {
		ll space = nums[j].first.second - nums[j].first.first;
		for (ll i = 0;
			 i < rooms.size() && rooms[i].second <= nums[j].first.first; ++i) {
			ll curr = rooms[i].second - rooms[i].first;
			if (space <= curr) {
				nums[j].first =
					make_pair(rooms[i].first, rooms[i].first + space);
				rooms[i] = make_pair(rooms[i].first + space, rooms[i].second);
				break;
			}
		}
	}
	for (ll i = 0; i < nums.size(); ++i) {
		for (ll k = nums[i].first.first; k < nums[i].first.second; ++k) {
			ans += nums[i].second * k;
		}
	}
	cout << ans << endl;
	return 0;
}
