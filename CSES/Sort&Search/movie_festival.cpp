#include <iostream>
#include <iterator>
#include <set>
#include <tuple>
#include <vector>
using ll = long long;

int main() {
	ll n;
	std::cin >> n;
	std::multiset<std::pair<ll, ll>> movies;
	for (int i = 0; i < n; ++i) {
		ll lower, higher;
		std::cin >> lower >> higher;
		movies.insert(std::make_pair(higher, lower));
	}
	ll ans = 0;
	ll time = 0;

	for (auto x : movies) {
		ll lower, higher;
		std::tie(higher, lower) = x;
		if (lower >= time) {
			++ans;
			time = higher;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
