#include <iostream>
#include <algorithm>
#include <cmath>
using ll = int64_t;
using ull = unsigned long long;
int main(void){
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i){
        ull row,column;
        std::cin >> row >> column;
        ull max = std::max(row,column);
        ull hiBound = max * max;
        ull loBound = (max - 1) * (max - 1);
        // std::cout << hiBound << ' ' << loBound << std::endl;
        if (max & 1){
            if (row > column){
                std::cout << loBound + column << std::endl;
            }
            else{
                std::cout << hiBound - row + 1 << std::endl;
            }
        }
        else{
            if (row > column){
                std::cout << hiBound - column + 1 << std::endl;
            }
            else{
                std::cout << loBound + row << std::endl;
            }

        }

    


    }
    return 0;
}