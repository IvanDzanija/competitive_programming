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
	ll n, x;
	cin >> n >> x;
	vector<ll> num(n, 0);
	vector<ll> vec;
	vec.push_back(x);
	for (ll i = 0; i < n; ++i) {
		cin >> num[i];
		if (num[i] > x) {
			continue;
		}
		vec.push_back(vec[vec.size() - 1] - num[i]);
		if (vec[vec.size() - 1] <= 0) {
			vec[vec.size() - 1] += x;
		}
	}

	ll ans = 0;
	ll lpos = 0;
	ll npos = 0;
	bool cond = false;
	for (ll i = 1; i < vec.size(); ++i) {
		if (vec[i] > vec[i - 1]) {
			if (cond == true) {
				lpos = npos;
			}
			cond = true;
			npos = i;
		}
		if (cond) {
			while (vec[i] < vec[lpos] && lpos < npos) {
				++lpos;
			}
			// cout << vec[i] << ' ' << lpos << endl;
		}

		if (vec[i] == vec[lpos]) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
