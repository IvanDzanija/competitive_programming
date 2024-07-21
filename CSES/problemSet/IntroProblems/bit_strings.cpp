#include <iostream>
#include <cmath>
using ll = int64_t;
using ull = unsigned long long;

int main(void){
    ull n;
    std::cin >> n;
    ull mod = pow(10,9) + 7;
    ull ans = 1;
    for (ull i = 0; i < n; ++i){
        ans *= 2;
        ans %= mod;
    } 

    std::cout << ans << std::endl;
    return 0;
}