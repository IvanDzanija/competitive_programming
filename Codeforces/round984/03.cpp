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
int count_bits(ll number) { return (int)log2(number) + 1; }
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<string> vec(s.size(), "12345");
		set<ll> pos;
		for (ll i = 0; i < s.size() - 3; ++i) {
			string tmp;
			tmp.push_back(s[i]);
			tmp.push_back(s[i + 1]);
			tmp.push_back(s[i + 2]);
			tmp.push_back(s[i + 3]);
			if (tmp == "1100") {
				pos.insert(i);
			}
			vec[i] = (tmp);
		}
		// cout << endl;
		// for (auto x : vec) {
		// 	cout << x << endl;
		// }
		ll q;
		cin >> q;
		for (ll i = 0; i < q; ++i) {
			ll x;
			char y;
			cin >> x >> y;
			if (s.size() < 4) {
				cout << "NO" << endl;
				continue;
			}
			if (s[x - 1] == y) {
				if (pos.size() == 0) {
					cout << "NO" << endl;
				} else {
					cout << "YES" << endl;
				}
				continue;
			}
			s[x - 1] = y;
			if (x == 1) {
				vec[0][0] = y;
				if (vec[0] == "1100") {

					pos.insert(0);
				} else {
					pos.erase(0);
				}
			} else if (x == 2) {
				vec[0][1] = y;
				vec[1][0] = y;
				if (vec[0] == "1100") {

					pos.insert(0);
				} else {
					pos.erase(0);
				}
				if (vec[1] == "1100") {

					pos.insert(1);
				} else {
					pos.erase(1);
				}
				// if (vec[0] == "1100" || vec[1] == "1100") {
				// 	cout << "YES" << endl;
				// 	f = true;
				// }
			} else if (x == 3) {
				vec[0][2] = y;
				vec[1][1] = y;
				vec[2][0] = y;
				if (vec[0] == "1100") {

					pos.insert(0);
				} else {
					pos.erase(0);
				}
				if (vec[1] == "1100") {

					pos.insert(1);
				} else {
					pos.erase(1);
				}
				if (vec[2] == "1100") {

					pos.insert(2);
				} else {
					pos.erase(2);
				}
				// if (vec[0] == "1100" || vec[1] == "1100" || vec[2] ==
				// "1100") { 	cout << "YES" << endl; 	f = true;
				// }
			} else {
				vec[x - 4][3] = y;
				vec[x - 3][2] = y;
				vec[x - 2][1] = y;
				vec[x - 1][0] = y;
				if (vec[x - 4] == "1100") {

					pos.insert(x - 4);
				} else {
					pos.erase(x - 4);
				}
				if (vec[x - 3] == "1100") {

					pos.insert(x - 3);
				} else {
					pos.erase(x - 3);
				}
				if (vec[x - 2] == "1100") {

					pos.insert(x - 2);
				} else {
					pos.erase(x - 2);
				}
				if (vec[x - 1] == "1100") {

					pos.insert(x - 1);
				} else {
					pos.erase(x - 1);
				}
				// if (vec[x - 4] == "1100" || vec[x - 3] == "1100" ||
				// 	vec[x - 2] == "1100" || vec[x - 1] == "1100") {
				// 	cout << "YES" << endl;
				// 	f = true;
				// }
			}
			if (pos.size() > 0) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
