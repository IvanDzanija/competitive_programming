#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
using ll = int64_t;

int main(void){
    ll n, m, k;
    std::cin >> n >> m >> k; 
    std::priority_queue<ll> apartments;
    std::priority_queue<ll> wishes;
    for (ll i = 0; i < n; ++i){
        ll x;
        std::cin >> x;
        wishes.push(x);
    }
    for (ll i = 0; i < m; ++i){
        ll x;
        std::cin >> x;
        apartments.push(x);
    }
    apartments.push(0);
    wishes.push(0);
    ll ans = 0;
    ll currentWish = wishes.top();
    wishes.pop();
    ll currentApp = apartments.top();
    apartments.pop();
    while (currentWish > 0 && currentApp > 0){
        if (currentApp >= currentWish - k && currentApp <= currentWish + k){
            ++ans;
            currentWish = wishes.top();
            wishes.pop();
            currentApp = apartments.top();
            apartments.pop();
        }
        else if (currentWish < currentApp){
            currentApp = apartments.top();
            apartments.pop();
        } 
        else{
            currentWish = wishes.top();
            wishes.pop();
        }
    };
    std::cout << ans << std::endl; 
    return 0;
}