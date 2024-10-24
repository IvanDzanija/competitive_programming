#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

#define INF (int)1e9
#define all(x) (x).begin(), (x).end()
#define MOD (int)(1e9 + 7)

using ll = int64_t;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

ll calc(int div) {
	if (div == 1)
		return 1;
	queue<ll> st;
	st.push(1);
	st.push(1);
	ll ind = 2;
	while (true) {
		ind++;
		ll a = st.front() % div;
		st.pop();
		ll b = st.front() % div;
		if ((b + a) % div == 0)
			return ind;
		st.push((b + a) % div);
	}
}
int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; ++i) {
		ll x, y;
		cin >> x >> y;
		x %= MOD;
		auto r = calc(y);
		cout << r * x % MOD << endl;
	}

	return 0;
}
