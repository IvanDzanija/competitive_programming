#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; ++i) {
		ll n, ans = 0;
		cin >> n;
		set<ll> pref_sums;
		ll sum = 0;
		for (ll j = 0; j < n; ++j) {
			ll curr;
			cin >> curr;
			sum += curr;
			if (sum == 0 or pref_sums.count(sum) or curr == 0) {
				pref_sums.erase(pref_sums.begin(), pref_sums.end());
				++ans;
				sum = 0;
			} else {
				pref_sums.insert(sum);
			}
		}

		cout << ans << endl;
	}

	return 0;
}
