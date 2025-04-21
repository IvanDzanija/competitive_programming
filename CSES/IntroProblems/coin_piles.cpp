#include <iostream>
#include <cmath>
using ll = int64_t;
using ull = uint64_t;

int main(void){
    ull n; 
    std::cin >> n;
    for (ull i = 0; i < n; ++i){
        ull x, y;
        std::cin >> x >> y;
        ull max = std::max(x,y);
        ull min = std::min(x,y);
        if (max > 2 * min || (min + max) % 3 != 0) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;

    }
    return 0;
}