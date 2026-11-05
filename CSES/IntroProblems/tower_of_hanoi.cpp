#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <stack>
using ll = int64_t;

ll n;

void solve(ll n, int from, int to, int help) {
    if (n == 0)
        return;
    else {
        solve(n - 1, from, help, to);
        std::cout << from << ' ' << to << std::endl;
        solve(n - 1, help, to, from);
    }
}

int main(void) {
    std::cin >> n;
    ll ans = pow(2, n) - 1;
    std::cout << ans << std::endl;
    solve(n, 1, 3, 2);
    return 0;
}
