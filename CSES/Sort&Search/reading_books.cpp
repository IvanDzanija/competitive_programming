#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll n;
	cin >> n;
	ll sum = 0;
	ll max = 0;
	for (ll i = 0; i < n; ++i) {
		ll t;
		cin >> t;
		if (t > max)
			max = t;
		sum += t;
	}
	if (sum - max > max) {
		cout << sum << endl;
	} else {
		cout << max * 2 << endl;
		;
	}

	return 0;
}
