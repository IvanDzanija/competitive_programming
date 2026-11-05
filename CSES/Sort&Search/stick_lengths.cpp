#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using ll = int64_t;

int main(void) {
	ll n, ans = 0;
	std::cin >> n;
	std::multiset<ll> nums;
	for (ll i = 0; i < n; ++i) {
		ll x;
		std::cin >> x;
		nums.insert(x);
	}

	auto b = nums.begin();
	auto e = nums.rbegin();
	while (*e > *b) {
		++e;
		++b;
	}
	ll median = *b;
	for (ll x : nums) {
		ans += abs(median - x);
	}
	std::cout << ans << std::endl;
	return 0;
}
