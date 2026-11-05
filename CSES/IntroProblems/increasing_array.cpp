#include <iostream>

using ll = int64_t;

int main(void){
    ll n; 
    std::cin >> n;
    ll ans = 0;
    ll prev = 0;
    for (ll i = 0; i < n; ++i){
        ll x;
        std::cin >> x;
        if (x < prev) ans += prev - x;
        else prev = x;
    }
    std::cout << ans << std::endl;


    return 0;
}