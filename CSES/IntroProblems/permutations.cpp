#include <iostream>
using ll = int64_t;

int main(void){
    ll n;
    std::cin >> n;
    if (n == 2 || n == 3) std::cout << "NO SOLUTION" << std::endl;
    else{
        std::cout << (n / 2) + (n % 2);
        ll r = n;
        for (ll i = 1; i <= n / 2; ++i){
            std::cout << ' ' << r;
            if (i < (n / 2) + (n % 2)) std::cout << ' ' <<i;
            --r; 
        }
        std::cout << std::endl;
    }     
    return 0;
}