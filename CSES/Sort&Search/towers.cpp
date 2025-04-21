#include <ios>
#include <iostream>
#include <set>
#include <vector>
using ll = int64_t;

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	ll n;
	std::cin >> n;
	std::vector<ll> nums(n);
	std::multiset<ll> st;
	for (int i = 0; i < n; ++i) {
		ll x;
		std::cin >> x;
		if (i > 0) {
			auto pt = st.upper_bound(x);
			if (pt != st.end()) {
				st.erase(pt);
			}
		}
		st.insert(x);
	}
	std::cout << st.size() << std::endl;

	return 0;
}
