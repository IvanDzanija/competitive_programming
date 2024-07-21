#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using ll = int64_t;

int main(void){
    std::string input;
    std::cin >> input;
    std::map<char, int> charMap;
    for (char ch : input){
        if (charMap.count(ch) == 0) charMap.insert(std::make_pair(ch, 1));
        else charMap.at(ch) += 1; 
    }
    int oddChars = 0;
    char possibleOdd;
    for (auto x : charMap){
        if (x.second % 2 == 1){
            ++oddChars;
            possibleOdd = x.first;
        } 
    }
    std::string ans = "";
    if (oddChars > 1) std::cout << "NO SOLUTION" << std::endl;
    else{
        if (oddChars == 0){
            for (std::pair x : charMap){
                for (ll i = 0; i < x.second / 2; ++i){
                    ans += x.first;
                }
            }
            std::string ans2;
            for (ll i = ans.length() - 1; i >= 0; --i) ans2 += ans.at(i); 
            std::cout << ans << ans2 << std::endl;
        } 
        else{
            for (std::pair x : charMap){
                if (x.first != possibleOdd){
                    for (ll i = 0; i < x.second / 2; ++i){
                       ans += x.first;
                    }
                }
            }
            std::string ans2;
            std::string ans3;
            for (ll i = 0; i < charMap.at(possibleOdd); ++i) ans3 += possibleOdd;
            for (ll i = ans.length() - 1; i >= 0; --i) ans2 += ans.at(i); 
            std::cout << ans << ans3 << ans2 << std::endl;

        }
    } 
    return 0;
}