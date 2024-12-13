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
ll res = INF;
int a, b, c, d;

map<pair<int, int>, ll> memo;
void solve(int e, int f, ll cnt) {
	auto key = make_pair(e, f);
	if (memo.count(key) && memo[key] <= cnt) {
		return;
	}
	memo[key] = cnt;
	if (e < 0 || f < 0) {
		return;
	}
	if (e == 0 && f == 0) {
		cout << "tu" << endl;
		res = min(res, cnt);
		return;
	}
	solve(e - a, f - b, cnt + 3);
	solve(e - c, f - d, cnt + 1);
	return;
}
signed main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ifstream input("../input.txt");
	string line;
	vector<pair<int, int>> vec;
	ll ans = 0;
	while (getline(input, line)) {
		if (line == "") {
			res = INF;
			memo.clear();
			vec.clear();
			continue;
		}
		if (line.find("Button A") != string::npos) {
			ll first = stoll(line.substr(line.find('+') + 1, line.find(',')));
			line = line.substr(line.find('Y') + 2);
			ll second = stoll(line);
			vec.push_back(make_pair(first, second));
		} else if (line.find("Button B") != string::npos) {
			ll first = stoll(line.substr(line.find('+') + 1, line.find(',')));
			line = line.substr(line.find('Y') + 2);
			ll second = stoll(line);
			vec.push_back(make_pair(first, second));
		} else {
			ll first = stoll(line.substr(line.find('=') + 1, line.find(',')));
			line = line.substr(line.find('Y') + 2);
			ll second = stoll(line);
			vec.push_back(make_pair(first, second));
			a = vec[0].first;
			b = vec[0].second;
			c = vec[1].first;
			d = vec[1].second;
			solve(vec[2].first, vec[2].second, 0);
			cout << a << ' ' << b << endl;
			cout << c << ' ' << d << endl;
			cout << vec[2].first << ' ' << vec[2].second << endl;
			ans += (res != INF ? res : 0);
		}
	}
	cout << ans << endl;
	return 0;
}
