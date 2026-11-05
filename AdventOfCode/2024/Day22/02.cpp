#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (ll)(16777216)

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
		vec.push_back(stoll(line));
	}
	set<tuple<int, int, int, int>> s;
	vector<vector<ll>> secrets(vec.size(), vector<ll>(2000, 0));
	vector<map<tuple<int, int, int, int>, int>> scs(vec.size());
	for (ll j = 0; j < vec.size(); ++j) {
		ll x = vec[j];
		for (ll i = 0; i < 2000; ++i) {
			if (i == 0) {
				secrets[j][i] = x % 10;
				continue;
			}
			ll y = x * 64;
			x ^= y;
			x %= MOD;
			y = x / 32;
			x ^= y;
			x %= MOD;
			y = x * 2048;
			x ^= y;
			x %= MOD;
			secrets[j][i] = x % 10;
			if (i >= 4) {
				ll a = secrets[j][i - 3] - secrets[j][i - 4];
				ll b = secrets[j][i - 2] - secrets[j][i - 3];
				ll c = secrets[j][i - 1] - secrets[j][i - 2];
				ll d = secrets[j][i] - secrets[j][i - 1];
				auto tpl = make_tuple(a, b, c, d);
				s.insert(tpl);
				if (!scs[j].count(tpl)) {
					scs[j][tpl] = i;
				}
			}
		}
	}

	ll ans = 0;
	// 15 sec to run
	for (auto change : s) {
		ll curr = 0;
		for (ll i = 0; i < scs.size(); ++i) {
			if (scs[i].count(change)) {
				curr += secrets[i][scs[i][change]];
			}
		}
		ans = max(ans, curr);
	}
	cout << ans << endl;

	return 0;
}
