#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using ll = int64_t;
using namespace __gnu_pbds;
template <typename T>
using indexed_set = tree<T, null_type, std::less<T>, rb_tree_tag,
						 tree_order_statistics_node_update>;

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	indexed_set<int> circ;
	for (int i = 0; i < n; ++i) {
		circ.insert(i + 1);
	}
	int pos = k % n;
	while (!circ.empty()) {
		auto rem = circ.find_by_order(pos);
		std::cout << *rem << ' ';
		circ.erase(rem);
		int s = circ.size();
		if (s)
			pos = (pos + k) % s;
	}
	std::cout << std::endl;

	return 0;
}
