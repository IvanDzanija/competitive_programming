#include <iostream>
#include <set>
#include <vector>

#define INF 1e18
using ll = int64_t;

int main(void) {
    int n, x;
    std::vector<ll> coins;
    std::cin >> n >> x;
    for (int m = n; m > 0; --m) {
        ll coin;
        std::cin >> coin;
        coins.push_back(coin);
    }

    std::vector<ll> cache(x + 1, INF);
    cache.at(0) = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < coins.at(j))
                continue;
            else if (cache.at(i - coins.at(j)) == INF)
                continue;
            else {
                if (cache.at(i - coins.at(j)) + 1 < cache.at(i))
                    cache.at(i) = cache.at(i - coins.at(j)) + 1;
            }
        }
    }
    // for (int i = 0; i < x; ++i) {
    //     std::cout << cache.at(i) << std::endl;
    // }
    if (cache.at(x) != INF)
        std::cout << cache.at(x) << std::endl;

    else
        std::cout << "-1" << std::endl;

    return 0;
}
