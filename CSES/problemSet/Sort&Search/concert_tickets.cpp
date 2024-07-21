#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using ll = int64_t;

std::multiset<ll> tickets;

int main(void){
    ll n,m;
    std::cin >> n >> m;
    std::vector<ll> second;
    for (ll i = 0; i < n; ++i){
        ll price;
        std::cin >> price;
        tickets.insert(price);
    }
    for (ll i = 0; i < m; ++i){
        ll price;
        std::cin >> price;
        std::multiset<ll>::iterator upperBound = tickets.upper_bound(price);
        if (upperBound == tickets.begin()){
            std::cout << "-1" << std::endl;
        } 
        else{
            std::cout << *(--upperBound) << std::endl;
            tickets.erase(upperBound);
        }
    }

    return 0;
}