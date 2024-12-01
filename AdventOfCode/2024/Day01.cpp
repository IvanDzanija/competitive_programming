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

ll p1(vector<ll> a, vector<ll> b) {
	ll ans = 0;
	ll n = (ll)a.size();
	for (ll i = 0; i < n; ++i) {
		// cout << a[i] << ' ' << b[i] << endl;
		ans += abs(a[i] - b[i]);
	}
	return ans;
}

ll p2(vector<ll> a, vector<ll> b) {
	ll ans = 0;
	ll n = (ll)a.size();
	unordered_map<ll, ll> mp1;
	unordered_map<ll, ll> mp2;
	for (ll i = 0; i < n; ++i) {
		if (mp1.count(a[i])) {
			++mp1[a[i]];
		} else {
			mp1[a[i]] = 1;
		}
		if (mp2.count(b[i])) {
			++mp2[b[i]];
		} else {
			mp2[b[i]] = 1;
		}
	}
	for (auto x : mp1) {
		ans += (x.second * mp2[x.first] * x.first);
	}
	return ans;
}

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::ifstream input("input.txt");
	string line;
	vector<ll> a;
	vector<ll> b;
	while (getline(input, line)) {
		a.push_back(stoll(line.substr(0, line.find(' '))));
		line = line.substr(line.find(' ') + 1);
		b.push_back(stoll(line));
	}
	sort(all(a));
	sort(all(b));
	cout << p1(a, b) << endl;
	cout << p2(a, b) << endl;
	return 0;
}
