#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

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
int count_bits(ll number) { return (int)log2(number) + 1; }
bool comp(pair<pair<ll, ll>, ll> f, pair<pair<ll, ll>, ll> s) {
	if (f.first.first == s.first.first) {
		return f.first.second > s.first.second;
	}
	return f.first.first < s.first.first;
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<pair<ll, ll>, ll>> rg;
	for (ll i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		rg.push_back(make_pair(make_pair(x, y), i));
	}
	sort(all(rg), comp);

	indexed_set<pair<ll, ll>> ind_set;
	vector<ll> contains(n, 0);
	vector<ll> contained(n, 0);
	for (int i = n - 1, cnt = 0; i >= 0; --i, ++cnt) {
		ind_set.insert(make_pair(rg[i].first.second, cnt));
		contains[rg[i].second] =
			ind_set.order_of_key(make_pair(rg[i].first.second, cnt));
	}

	indexed_set<pair<ll, ll>> set;
	for (int i = 0, cnt = n; i < n; ++i, --cnt) {
		set.insert(make_pair(rg[i].first.second, cnt));
		contained[rg[i].second] =
			(set.size() - 1) -
			set.order_of_key(make_pair(rg[i].first.second, cnt));
	}
	for (auto x : contains) {
		cout << x << ' ';
	}
	cout << endl;
	for (auto x : contained) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
