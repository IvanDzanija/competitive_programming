#include <iostream>
using ll = int64_t;

//fully mathematical approach - 1.st Card(Placing 2 same pieces on k x k board)
//                            - 2.nd Count(3 x 2 reagions on k x k board) * 2 (Number of possible attacking knights in each 3 x 2 reagion)
int main(void){
    ll n; 
    std::cin >> n;
    for (ll i = 1 ; i <= n; ++i){
        std::cout << (i*i) * (i*i - 1) / 2 - (i - 1) * (i - 2) * 4 << std::endl;
    } 
    return 0;
}