#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <string>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using ull = unsigned long long;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<int> ans;
		// cout << li << ' ' << ui << endl;
		if (n & 1) {
			if (n == 1 or n == 3) {
				ans.push_back(-1);
			} else {
				n -= 5;
				ans.push_back(6);
				ans.push_back(6);
				ans.push_back(3);
				ans.push_back(6);
				ans.push_back(3);
				while (n--) {
					ans.push_back(3);
				}
			}

		} else {
			ans.push_back(6);
			ans.push_back(6);
			n -= 2;
			while (n--) {
				ans.push_back(3);
			}
		}
		for (ll i = ans.size() - 1; i >= 0; --i) {
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
