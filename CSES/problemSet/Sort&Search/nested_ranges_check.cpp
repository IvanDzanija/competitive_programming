#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9 + 1

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<pair<ll, ll>, ll>> rg;
	vector<int> fans(n, 0);
	vector<int> sans(n, 0);
	for (int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		rg.push_back(make_pair(make_pair(x, y), i));
	}
	sort(rg.begin(), rg.end(), comp);
	// for (auto x : rg) {
	// 	std::cout << x.first.first << ' ' << x.first.second << ' ' << x.second
	// 			  << endl;
	// }
	ll minE = INF;
	for (int i = n - 1; i >= 0; --i) {
		// cout << mb << endl;
		if (rg[i].first.second >= minE) {
			fans[rg[i].second] = true;
		} else {
			minE = rg[i].first.second;
		}
	}

	ll maxE = 0;
	for (int i = 0; i < n; ++i) {
		if (rg[i].first.second <= maxE) {
			sans[rg[i].second] = true;
		} else {
			maxE = rg[i].first.second;
		}
	}

	for (auto x : fans) {
		cout << x << ' ';
	}
	cout << endl;
	for (auto x : sans) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
