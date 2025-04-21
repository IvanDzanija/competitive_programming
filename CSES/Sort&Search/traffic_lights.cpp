#include <ios>
#include <iostream>
#include <iterator>
#include <set>
using ll = int64_t;

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int x, n;
	std::cin >> x >> n;
	std::set<ll> ls;
	ls.insert({0, x});
	std::multiset<ll> dist;
	dist.insert(x);
	for (int i = 0; i < n; ++i) {
		ll y;
		std::cin >> y;
		std::set<ll>::iterator it = ls.upper_bound(y);

		dist.erase(dist.find(*it - *std::prev(it)));
		dist.insert(*it - y);
		dist.insert(y - *std::prev(it));
		ls.insert(y);

		std::cout << *std::prev(dist.end()) << ' ';
	}
	std::cout << std::endl;

	return 0;
}
