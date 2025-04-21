#include <iostream>
#include <vector>
#include <algorithm>
using ll = int64_t;

int main(void){
    ll n, x;
    std::cin >> n >> x;
    std::vector<ll> kids;
    for (ll i = 0; i < n; ++i){
        ll y; 
        std::cin >> y;
        kids.push_back(y);
    }
    std::sort(kids.begin(), kids.end());
    ll ans = 0;
    ll i = 0; 
    ll j = kids.size() - 1; 
    while (i < j){
        if (kids.at(i) + kids.at(j) <= x){
            ++ans;
            ++i;
            --j;
        }
        else --j;
    }
    std::cout << n - ans<< std::endl;    
    return 0;
}