#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
using ll = int64_t;

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	ll n, m;
	std::cin >> n >> m;
	std::vector<ll> nums(n + 1);
	std::vector<ll> index(n + 1);
	for (ll i = 1; i <= n; ++i) {
		std::cin >> nums[i];
		index[nums[i]] = i;
	}
	ll ans = 1;
	for (ll i = 1; i < n; ++i) {
		if (index[i] > index[i + 1])
			++ans;
	}
	ll x, y;
	std::set<std::pair<ll, ll>> mem;
	while (m--) {
		std::cin >> x >> y;

		if (nums[x] - 1 >= 1) {
			mem.insert(std::make_pair(nums[x] - 1, nums[x]));
		}
		if (nums[x] + 1 <= n) {
			mem.insert(std::make_pair(nums[x], nums[x] + 1));
		}
		if (nums[y] - 1 >= 1) {
			mem.insert(std::make_pair(nums[y] - 1, nums[y]));
		}
		if (nums[y] + 1 <= n) {
			mem.insert(std::make_pair(nums[y], nums[y] + 1));
		}
		for (auto z : mem) {
			if (index[z.first] > index[z.second])
				--ans;
		}
		ll temp = nums[x];
		nums[x] = nums[y];
		nums[y] = temp;
		index[nums[x]] = x;
		index[nums[y]] = y;

		for (auto z : mem) {
			if (index[z.first] > index[z.second])
				++ans;
		}
		mem.clear();
		std::cout << ans << '\n';
	}
	std::cout << std::endl;

	return 0;
}
