#include <iostream>
#include <set>
using ll = int64_t;

int main(void){
    ll n;
    std::cin >> n;
    std::set<ll> nums;
    for (ll i = 1; i < n ; ++i){
        ll x;
        std::cin >> x;
        nums.insert(x);
    }
    ll i = 1;
    while (nums.find(i) != nums.end()) ++i;
    std::cout << i << std::endl; 
    return 0;
}