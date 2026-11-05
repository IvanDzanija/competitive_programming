#include<iostream>
#include <string>
using ll = int64_t;

ll longestRep(std::string input){
    ll ans = 1;
    ll c = 1;
    for (ll i = 1 ; i < input.length(); ++i){
        if (input.at(i - 1) == input.at(i)) ++c;
        else c = 1;
        if (c > ans) ans = c;
    }
    return ans;
}
int main(void){
    std::string input;
    std::cin >> input;
    std::cout << longestRep(input) << std::endl;

    return 0;
}