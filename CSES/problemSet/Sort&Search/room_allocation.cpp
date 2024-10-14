#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <tuple>
#define INF (int)1e9

using ll = int64_t;
using namespace __gnu_pbds;

int main(void) {
	std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int n;
	std::cin >> n;

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
						std::greater<std::pair<int, int>>>
		pq;
	pq.push(std::make_pair(0, 1));
	std::multiset<std::tuple<int, int, int>> gst;
	std::vector<int> rms(n, 0);

	for (int i = 0; i < n; ++i) {
		ll x, y;
		std::cin >> x >> y;
		gst.insert(std::make_tuple(x, y, i));
	}
	// for (auto x : gst) {
	// 	std::cout << x.first << ' ' << x.second << std::endl;
	// }
	std::set<int> tknRms;
	tknRms.insert(1);
	int ans = 0;

	for (auto x : gst) {
		ll c1, c2, c3;
		std::tie(c1, c2, c3) = x;
		ll ch = pq.top().first;
		// std::cout << c1 << ' ' << c2 << ' ' << ch << ' ' << pq.top().second
		// << std::endl;

		if (c1 > ch) {
			int r = pq.top().second;
			pq.push(std::make_pair(c2, r));
			pq.pop();
			rms.at(c3) = r;
		} else {
			int maxR = *std::prev(tknRms.end());
			pq.push(std::make_pair(c2, maxR + 1));
			tknRms.insert(maxR + 1);
			rms.at(c3) = maxR + 1;
		}
		if (tknRms.size() > ans)
			ans = tknRms.size();
	}
	std::cout << ans << '\n';
	for (auto x : rms) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;

	return 0;
}
