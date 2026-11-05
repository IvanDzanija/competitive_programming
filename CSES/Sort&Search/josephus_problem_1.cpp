#include <ios>
#include <iostream>
#include <iterator>
#include <set>

using ll = int64_t;

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::set<ll> circ;
	for (int i = 0; i < n; ++i) {
		circ.insert(i + 1);
	}
	std::set<ll>::iterator pos = circ.begin();
	// std::cout << *pos << std::endl;

	while (!circ.empty()) {
		// for (auto x : circ) {
		// 	std::cout << x << ' ';
		// }
		// std::cout << '\n';

		if (pos == std::prev(circ.end())) {
			std::cout << *circ.begin() << ' ';
			circ.erase(circ.begin());
			pos = circ.begin();
		} else if (pos == std::prev(std::prev(circ.end()))) {
			std::cout << *std::next(pos) << ' ';
			circ.erase(std::next(pos));
			pos = circ.begin();

		} else {
			std::cout << *std::next(pos) << ' ';
			circ.erase(std::next(pos));
			pos = std::next(pos);
		}
		std::cout << std::endl;
	}
	return 0;
}
