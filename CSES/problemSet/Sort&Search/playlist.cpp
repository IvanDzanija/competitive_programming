#include <iostream>
#include <map>
#include <vector>
using ll = int64_t;

int main(void) {
	ll n;
	std::cin >> n;
	std::vector<ll> nums(n);
	std::map<ll, ll> log;
	for (ll i = 0; i < n; ++i) {
		std::cin >> nums[i];
	}
	ll ans = 0;
	ll start = 0;
	ll end = 0;
	for (end = 0; end < n; end++) {
		if (log.find(nums[end]) != log.end() && log[nums[end]] >= start) {
			start = log[nums[end]] + 1;
		}
		log[nums[end]] = end;
		ans = std::max(ans, end - start + 1);
	}

	std::cout << ans << std::endl;
	return 0;
}
