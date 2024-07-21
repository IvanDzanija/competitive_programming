#include <ios>
#include <iostream>
#include <iterator>
#include <set>
using ll = int64_t;

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	ll n;
	std::cin >> n;
	std::multiset<ll> nums;
	for (ll i = 0; i < n; ++i) {
		ll x;
		std::cin >> x;
		nums.insert(x);
	}
	ll ans = 0;
	bool cond = false;
	auto p = nums.begin();
	while (!cond && p != nums.end()) {
		if (*p <= ans + 1) {
			ans += *p;
			++p;
			continue;
		} else {
			++ans;
			cond = true;
			continue;
		}
	}
	if (p == nums.end())
		ans++;
	std::cout << ans << std::endl;

	return 0;
}
