#include <iostream>
#include <set>
#include <vector>

using ll = int64_t;
ll n;
ll sum = 0;
std::vector<ll> apples;

ll closestSum = 0;
std::set<ll> cache;
int generateSum(ll currentSum, ll index) {
    ll newSum = currentSum + apples.at(index);
    if (newSum * 2 == sum)
        return 1;
    else {
        if (newSum * 2 < sum && newSum > closestSum)
            closestSum = newSum;
        if (++index < apples.size()) {
            generateSum(currentSum, index);
            generateSum(newSum, index);
        }
    }
    return 0;
}

int main(void) {
    std::cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll weight;
        std::cin >> weight;
        sum += weight;
        apples.push_back(weight);
    }
    int ans = generateSum(0, 0);
    if (ans == 1)
        std::cout << 0 << std::endl;
    else {
        std::cout << sum - (2 * closestSum) << std::endl;
    }
    for (auto x : cache) {
        std::cout << x << std::endl;
    }
}
