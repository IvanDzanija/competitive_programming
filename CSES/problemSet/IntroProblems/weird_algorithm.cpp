#include <iostream>
using ll = int64_t;

void weirdAlgo(ll n){
    if (n == 1) {
        std::cout << n << std::endl;
        return;
    }
    std::cout << n << ' ';
    if (n % 2 == 0) weirdAlgo(n / 2);
    else weirdAlgo(n * 3 + 1);
}
int main(void){
    ll n;
    std::cin >> n;
    weirdAlgo(n);
    return 0;
}
