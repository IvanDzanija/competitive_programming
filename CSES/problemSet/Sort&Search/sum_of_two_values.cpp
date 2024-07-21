#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using ll = int64_t;

int main(void) {
	ll n, y;
	std::cin >> n >> y;
	std::multiset<ll> list;
	std::vector<ll> saved;
	for (int i = 0; i < n; ++i) {
		ll x;
		std::cin >> x;
		list.insert(x);
		saved.push_back(x);
	}
	if (saved.size() < 2) {
		std::cout << "IMPOSSIBLE" << std::endl;
		;
	} else {
		auto hi = --list.upper_bound(y);
		auto lo = list.begin();
		while (*hi >= *lo) {
			// std::cout << *hi << ' ' << *lo << std::endl;
			if (*hi + *lo == y || hi == lo) {
				break;
			} else if (*hi + *lo > y) {
				--hi;
			} else {
				++lo;
			}
		}
		if (hi == lo || *hi < *lo) {
			std::cout << "IMPOSSIBLE" << std::endl;
		} else {
			bool hiP = false;
			bool loP = false;
			for (int i = 0; i < n; ++i) {
				if (saved.at(i) == *hi && !hiP) {
					std::cout << i + 1 << ' ';
					hiP = true;
				} else if (saved.at(i) == *lo && !loP) {
					std::cout << i + 1 << ' ';
					loP = true;
				}
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
