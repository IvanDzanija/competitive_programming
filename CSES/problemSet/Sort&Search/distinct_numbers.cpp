#include <iostream>
#include <set>

using ll = int64_t;

int main(void){
    ll n;
    std::cin >> n;
    std::set<ll> distinct;
    for (ll i = 0; i < n; ++i){
        ll x;
        std::cin >> x;
        distinct.insert(x);
    }
    std::cout << distinct.size() << std::endl;
    return 0;
}