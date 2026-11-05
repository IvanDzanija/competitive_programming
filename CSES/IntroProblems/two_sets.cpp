#include <iostream>
#include <set>
using ll = int64_t;

ll sum(ll n){
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) ans += i;
    return ans;
}

int main(void){
    ll n;
    std::cin >> n;
    if (n % 2 == 0 && (n / 2) % 2 == 1) std::cout << "NO" << std::endl;
    else if (n % 2 == 0 && (n / 2) % 2 == 0){
        std::cout << "YES" << std::endl;
        std::cout << n / 2 << std::endl;
        for (ll i = 1; i <= n / 2; i += 2){
            std::cout << i << ' ' << n - i + 1 << ' ';
        }
        std::cout << std::endl;
        std::cout << n / 2 << std::endl;
        for (ll i = 2; i <= n / 2; i += 2){
            std::cout << i << ' ' << n - i + 1 << ' ';
        }
        std::cout << std::endl;
    }
    
    else if (n % 2 == 1 && sum(n) % 2 == 0){
        std::cout << "YES" << std::endl;
        std::set<ll> first;
        ll h = sum(n) / 2;
        ll c = n;
        first.insert(n);
        ll i = n - 1;
        while (c < h){
            if (h - c > i) {
                first.insert(i);
                c += i;
                --i;
            }
            else{
                first.insert(h - c);
                c += (h - c);
            }
        }
        std::cout << first.size() << std::endl;
        for (auto x : first) std::cout << x << ' ';
        std::cout << std::endl;
        std::cout << n - first.size() << std::endl;
        for (ll j = 1; j < n; ++j){
            if (!first.count(j)) std::cout << j << ' ';
        }
        std::cout << std::endl;
    }
    else std::cout << "NO" << std::endl;; 

    return 0;
}
