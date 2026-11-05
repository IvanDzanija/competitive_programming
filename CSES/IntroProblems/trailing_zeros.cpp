#include <iostream>
#include <limits>

using ll = int64_t;
using ull = uint64_t;

int main(){
    ll n; 
    std::cin >> n;
    if (n < 5) std::cout << 0 << std::endl;
    else{
        ll result = 0;
        ll five = 5;
        while (n >= five){
            result += n / five;
            five *=5;
        }
        std::cout << result << std::endl;
    }
    
    
    return 0;
}