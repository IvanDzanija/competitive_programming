#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using ll = long long;

int main() {
	ll n;
	std::cin >> n;
	std::multiset<ll> aTime;
	std::multiset<ll> dTime;
	for (int i = 0; i < n; ++i) {
		ll lower, higher;
		std::cin >> lower >> higher;
		aTime.insert(lower);
		dTime.insert(higher);
	}
	ll ans = 0;
	ll current = 0;
	auto i = aTime.begin();
	auto j = dTime.begin();

	while (i != aTime.end()) {
		if (*(i) < *(j)) {
			++current;
			++i;
			if (current > ans)
				ans = current;
		} else if (*i > *j) {
			--current;
			++j;
		} else {
			++i;
			++j;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
