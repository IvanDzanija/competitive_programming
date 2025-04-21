#include <cmath>
#include <iostream>

using ll = long long;
using ull = unsigned long long;

ll xpow(ll x, ull y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

int main(void) {
    ll n;
    std::cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll query;
        std::cin >> query;

        if (query < 10) {
            std::cout << query << std::endl;
        } else {
            ll start = 9;
            ll digits = 2;
            while (start + (9 * xpow(10, digits - 1) * digits) < query) {
                start += (9 * xpow(10, digits - 1) * digits);
                ++digits;
            }

            ll use = query - start - 1;
            ll number = use / digits;
            ll wantedDigit = use % digits;
            // std::cout << use << ' ' << digits << ' ' << number << ' '
            //           << wantedDigit << std::endl;

            ll ans = xpow(10, digits - 1) + number;
            // std::cout << ans << std::endl;
            std::string s = std::to_string(ans);
            std::cout << s[wantedDigit] << std::endl;
        }
    }
    return 0;
}
