#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using ll = int64_t;

int main(void) {
	ll n;
	std::cin >> n;
	ll ans = LLONG_MIN;
	ll hi = 0;
	for (ll i = 0; i < n; ++i) {
		ll x;
		std::cin >> x;
		if (i == 0) {
			hi = x;
			continue;
		}
		if (hi > ans) {
			ans = hi;
		}
		hi += x;
		if (x > hi)
			hi = x;
		// std::cout << hi << ' ' << ans << std::endl;
	}
	if (hi > ans)
		ans = hi;
	std::cout << ans << std::endl;
	return 0;
}
