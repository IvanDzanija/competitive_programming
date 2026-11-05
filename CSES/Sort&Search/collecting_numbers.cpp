#include <ios>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using ll = int64_t;

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	ll n;
	std::cin >> n;
	std::vector<ll> nums;
	std::map<ll, ll> index;
	for (ll i = 0; i < n; ++i) {
		ll x;
		std::cin >> x;
		nums.push_back(x);
		index[x] = i;
	}
	ll ans = 1;
	for (ll i = 1; i < n; ++i) {
		if (index[i] > index[i + 1])
			++ans;
	}
	std::cout << ans << std::endl;

	return 0;
}
