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
	ll n;
	cin >> n;
	vector<ll> a(n, 0);
	stack<ll> s;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		a[i] = x;
		while (!s.empty() && a[s.top()] >= a[i]) {
			s.pop();
		}
		if (s.empty()) {
			cout << "0 ";
		} else {
			cout << s.top() + 1 << ' ';
		}
		s.push(i);
	}
	cout << endl;
	return 0;
}
